/// Copyright (c) RenChu Wang - All Rights Reserved

#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <variant>
#include <vector>

using namespace std;

/// Inheritance Base
struct NodeBase {};
/// Inheritance A
struct NodeA : public NodeBase {};
/// Inheritance B
struct NodeB : public NodeBase {
    int a;
};
/// Inheritance C
struct NodeC : public NodeBase {
    string g;
};

/// No inheritance D
struct NodeD {};
/// No inheritance E
struct NodeE {
    int a;
};
/// No inheritance F
struct NodeF {
    string g;
};

// Note that the types can be very different, inherit or not!
using NodeInherit = variant<NodeA, NodeB, NodeC>;
using NodeNoInherit = variant<NodeD, NodeE, NodeF>;

/// Visitor can be reused!
struct Visitor {
    // For inheritance.
    void operator()(const NodeA&) { cout << "NodeA" << endl; }
    void operator()(const NodeB&) { cout << "NodeB" << endl; }
    void operator()(const NodeBase&) { cout << "NodeBase" << endl; }

    // For non inheritance.
    void operator()(const NodeD&) { cout << "NodeD" << endl; }
    void operator()(const NodeE&) { cout << "NodeE" << endl; }

    // Even if NodeF is not present in the list, you cannot omit it.
    // Error: `std::visit` requires the visitor to be exhaustive.
    void operator()(const NodeF&) { cout << "NodeF" << endl; }
};

// We can use visitor pattern to make tree nodes that are very different,
// only sharing the part where we define parents / children.
struct TreeNode {
    vector<shared_ptr<TreeNode>> children;
};

struct NodeX : public TreeNode {
    NodeX(int data) : TreeNode({}), data(data) {}
    int data;
};

struct NodeY : public TreeNode {
    NodeY(string data) : TreeNode({}), data(data) {}
    string data;
};

struct TreeVisitor {
    void operator()(const NodeX& n) {
        cout << "X [" << n.children.size() << "] (int) = " << n.data << endl;
    }
    void operator()(const NodeY& n) {
        cout << "Y [" << n.children.size() << "] (string) = " << n.data << endl;
    }
};

using NodeXY = variant<NodeX, NodeY>;

int main() {
    vector<NodeInherit> nodes_i = {NodeA{}, NodeB{}, NodeC{}, NodeA{}};

    for (NodeInherit& node : nodes_i) {
        visit(Visitor{}, node);
    }

    cout << endl;
    vector<NodeNoInherit> nodes_ni = {NodeD{}, NodeE{}};

    for (NodeNoInherit& node : nodes_ni) {
        visit(Visitor{}, node);
    }

    cout << endl;
    auto nx = make_shared<NodeX>(1);
    auto ny = make_shared<NodeY>("hi");
    ny->children.push_back(nx);

    vector<NodeXY> xy = {*nx, *ny};
    for (NodeXY& n : xy) {
        visit(TreeVisitor{}, n);
    }
}
