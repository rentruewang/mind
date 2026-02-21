/// Copyright (c) RenChu Wang - All Rights Reserved

#include <iostream>
#include <string>

using namespace std;

#define NOT_USED [[maybe_unused]]

class OnlyCopy {
   public:
    OnlyCopy(string member) : member_(member) { cout << "init only copy\n"; }
    OnlyCopy(const OnlyCopy& other) : member_(other.member_) {
        cout << "copy only copy\n";
    }
    OnlyCopy(OnlyCopy&& other) = delete;
    const string& member() const { return member_; }

   private:
    string member_;
};

class OnlyMove {
   public:
    OnlyMove(string member) : member_(member) { cout << "init only move\n"; }
    OnlyMove(const OnlyMove& other) = delete;
    OnlyMove(OnlyMove&& other) : member_(std::move(other.member_)) {
        cout << "move only move\n";
    }
    const string& member() const { return member_; }

   private:
    string member_;
};

class HaveBoth {
   public:
    HaveBoth(string member) : member_(member) { cout << "init both\n"; }
    HaveBoth(const HaveBoth& other) : member_(other.member_) {
        cout << "copy both\n";
    }
    HaveBoth(HaveBoth&& other) : member_(std::move(other.member_)) {
        cout << "move both\n";
    }
    const string& member() const { return member_; }

   private:
    string member_;
};

template <typename T>
class NoUse {
   public:
    void call_copy(NOT_USED const T& obj) {}
    void call_move(NOT_USED T&& obj) {}
};

template <typename T>
class UseCopy {
   public:
    void call_copy(const T& obj) { T copied(obj); }
    void call_move(NOT_USED T&& obj) {}
};

template <typename T>
class UseMove {
   public:
    void call_copy(NOT_USED const T& obj) {}
    void call_move(T&& obj) { T moved(std::move(obj)); }
};

template <typename T>
class BothCopyMove {
   public:
    void call_copy(const T& obj) { T copied(obj); }
    void call_move(T&& obj) { T moved(std::move(obj)); }
};

template <typename T>
class MoveCopies {
   public:
    void call_copy(NOT_USED const T& obj) {}
    void call_move(T&& obj) { T moved(obj); }
};

template <typename T>
class CopyMoves {
   public:
    void call_copy(const T& obj) { T copied(std::move(obj)); }
    void call_move(NOT_USED T&& obj) {}
};

int main() {
    OnlyCopy has_copy{"copy"};
    OnlyMove has_move{"move"};
    HaveBoth has_both{"both"};

    NOT_USED NoUse<OnlyCopy> dnu_copy;
    NOT_USED NoUse<OnlyMove> dnu_move;
    NOT_USED NoUse<HaveBoth> dnu_both;

    NOT_USED UseCopy<OnlyCopy> uc_copy;
    NOT_USED UseCopy<OnlyMove> uc_move;
    NOT_USED UseCopy<HaveBoth> uc_both;

    NOT_USED UseMove<OnlyCopy> um_copy;
    NOT_USED UseMove<OnlyMove> um_move;
    NOT_USED UseMove<HaveBoth> um_both;
    cout << "Use copy\n";

    UseCopy<OnlyCopy> uc_used_copy;
    NOT_USED UseCopy<OnlyMove> uc_used_move;
    UseCopy<HaveBoth> uc_used_both;

    uc_used_copy.call_copy(has_copy);

    // error: call to deleted constructor of 'only_move'
    // uc_used_move.call_copy(has_move);

    uc_used_both.call_copy(has_both);

    cout << "\n";

    cout << "Use move\n";

    NOT_USED UseMove<OnlyCopy> um_used_copy;
    UseMove<OnlyMove> um_used_move;
    UseMove<HaveBoth> um_used_both;

    // error: rvalue reference to type 'only_copy' cannot
    // bind to lvalue of type 'only_copy'
    // um_used_copy.call_move(has_copy);

    // error: call to deleted constructor of 'only_copy'
    // um_used_copy.call_move(move(has_copy));

    um_used_move.call_move(std::move(has_move));
    um_used_both.call_move(std::move(has_both));

    cout << "\n";

    cout << "Move is copy\n";

    MoveCopies<OnlyCopy> mic_used_copy;
    NOT_USED MoveCopies<OnlyMove> mic_used_move;
    MoveCopies<HaveBoth> mic_used_both;

    mic_used_copy.call_move(std::move(has_copy));

    // error: rvalue reference to type 'only_copy' cannot
    // bind to lvalue of type 'only_copy'
    // mic_used_copy.call_move(has_copy);

    // error: call to deleted constructor of 'only_move'
    // mic_used_move.call_move(move(has_move));

    // error: rvalue reference to type 'only_move' cannot
    // bind to lvalue of type 'only_move'
    // mic_used_move.call_move(has_move);

    mic_used_both.call_move(std::move(has_both));

    cout << "\n";

    cout << "Copy is move (but is copy)\n";
    // https://stackoverflow.com/questions/28595117/why-can-we-use-stdmove-on-a-const-object
    // https://stackoverflow.com/questions/27810535/why-does-calling-stdmove-on-a-const-object-call-the-copy-constructor-when-pass
    // https://stackoverflow.com/questions/63466914/move-semantics-vs-const-reference
    // https://stackoverflow.com/questions/4938875/do-rvalue-references-to-const-have-any-use

    CopyMoves<OnlyCopy> cim_used_copy;
    NOT_USED CopyMoves<OnlyMove> cim_used_move;
    CopyMoves<HaveBoth> cim_used_both;

    cim_used_copy.call_copy(has_copy);
    cim_used_copy.call_copy(std::move(has_copy));

    // error: call to deleted constructor of 'only_move'
    // cim_used_move.call_copy(std::move(has_move));

    // error: call to deleted constructor of 'only_move'
    // cim_used_move.call_copy(has_move);

    cim_used_both.call_copy(std::move(has_both));

    BothCopyMove<OnlyCopy> ub_copy;
    BothCopyMove<OnlyMove> ub_move;
    BothCopyMove<HaveBoth> ub_both;

    ub_copy.call_copy(has_copy);

    // error: call to deleted constructor of 'only_copy'
    // ub_copy.call_move(has_move);

    // error: no viable conversion from 'typename
    // std::remove_reference<only_move
    // &>::type' (aka 'only_move') to 'only_copy'
    // ub_copy.call_move(move(has_move));

    // error: call to deleted constructor of 'only_move'
    // ub_move.call_copy(has_move);
    ub_move.call_move(std::move(has_move));

    ub_both.call_copy(has_both);
    ub_both.call_move(std::move(has_both));

    return 0;
}
