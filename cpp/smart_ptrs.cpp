/// Copyright (c) RenChu Wang - All Rights Reserved

#include <initializer_list>
#include <iostream>
#include <memory>

using namespace std;

template <typename T>
void print(T anything) {
    cout << anything << "\n";
}

template <typename T>
class SomeClass {
   public:
    SomeClass(T name) { name_ = name; }
    ~SomeClass() { print(name_); }

    T& name() { return name_; }
    const T& name() const { return name_; }

   private:
    T name_;
};

struct BasicStruct {
    int data;
};
struct SingleStruct : BasicStruct {};
struct SomeStruct {
    int datai;
    float dataf;
};
struct SomeStructVec {
    int datai;
    float dataf;
    vector<int> vec;
};

int main() {
    print("First experiment: 12345");
    {
        print(1);
        auto ptr = make_unique<SomeClass<int>>(3);
        print(2);
        ptr = make_unique<SomeClass<int>>(5);
        print(4);
    }

    print("Second experiment: 12345");
    {
        print(1);
        // 0 wouldn't appear in the output because it's an initialization.
        auto sc = SomeClass<int>(0);
        print(2);
        // Destructor called once here for the temporary object.
        sc = SomeClass<int>(3);
        sc.name() = 5;
        print(4);
    }

    print("Doesn't work.");
    {
        // This doesn't work. Cannot convert int -> SingleStruct directly.
        // Need to define constructor manually.
        // auto ptr0 = make_unique<SingleStruct>(1);

        // Does work.
        auto ptr1 = make_unique<SomeStruct>(1, 2);

        // Having initializer list doesn't work.
        // auto ptr2 = make_unique<SomeStructVec>(1, 2, {});
        // Perhaps:
        // https://stackoverflow.com/questions/11820981/stdshared-ptr-and-initializer-lists
        auto ptr3 = make_unique<SomeStructVec>(1, 2, initializer_list<int>{});
    }
}
