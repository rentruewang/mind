/// Copyright (c) RenChu Wang - All Rights Reserved

#include <concepts>
#include <iostream>

using namespace std;

template <typename T>
concept HasAdd = requires(T a, T b, int c) {
    { a + b } -> std::same_as<T>;
    { a + c } -> std::same_as<T>;
};

template <typename T>
concept Comparable = requires(T a, T b) {
    { a < b } -> std::same_as<bool>;
};

template <Comparable T>
T larger(T a, T b) {
    T result = (a > b) ? a : b;
    return result;
}

template <typename T>
bool operator<<(T a, T b)
    requires Comparable<T>
{
    return a < b;
}

template <typename T>
class Container {
   public:
    Container(T value) noexcept { value_ = value; }

    T operator()() const { return value_; }

    bool operator<(const Container& other) const {
        cout << "   --- Container cmp called. ---   ";
        return value_ < other.value_;
    }

   private:
    T value_;
};

template <HasAdd T>
void operator+=(T& left, const T& right) {
    left = left + right;
}

class MyInt0 {
   public:
    MyInt0(int val) : val_(val) {}
    MyInt0 operator+(MyInt0 i) { return MyInt0(val_ + i.val_); }
    MyInt0 operator+(int i) { return MyInt0(val_ + i); }
    int value() const { return val_; }

   private:
    int val_;
};

class MyInt1 {
   public:
    MyInt1(int val) : val_(val) {}
    MyInt1 operator+(MyInt1 i) { return MyInt1(val_ + i.val_); }
    int value() const { return val_; }

   private:
    int val_;
};

class MyInt2 {
   public:
    explicit MyInt2(int val) : val_(val) {}
    MyInt2 operator+(MyInt2 i) { return MyInt2(val_ + i.val_); }
    int value() const { return val_; }

   private:
    int val_;
};
template <typename T>
class AnotherContainer {
   public:
    AnotherContainer(T a) : a_(a) {}

   private:
    T a_;
};

int main() {
    int i = 5, j = 6, k;
    long l = 10, m = 5, n;
    k = larger<int>(i, j);
    n = larger<long>(l, m);

    cout << k << endl;
    cout << n << endl;

    cout << "1 << 2: " << (Container<int>(1) << Container<int>(2)) << endl;
    cout << "1 << 0: " << (Container<int>(1) << Container<int>(0)) << endl;

    // Let's try something that will fail.
    // because 'AnotherContainer<std::string>' does not satisfy 'Comparable'
    // auto res = larger<AnotherContainer<string>>({"a"}, {"b"});

    cout << "\n\n\n";

    // Is MyInt0 += automatically supplied?
    MyInt0 mi0{3};
    if constexpr (HasAdd<MyInt0>) {
        // Yes
        cout << "My int 0 is HasAdd\n";
        cout << "+= for my int 0\n";
        mi0 += mi0;
        cout << "Result value: " << mi0.value() << "\n";
    } else {
        cout << "My int 0 is not HasAdd\n";
    }

    MyInt1 mi1{3};
    if constexpr (HasAdd<MyInt1>) {
        // Yes, because of auto conversion from int -> MyInt1.
        cout << "My int 1 is HasAdd\n";
    } else {
        cout << "My int 1 is not HasAdd\n";
    }

    MyInt2 mi2{3};
    if constexpr (HasAdd<MyInt2>) {
        cout << "My int 2 is HasAdd\n";
    } else {
        // No
        cout << "My int 2 is not HasAdd\n";
    }
    return 0;
}
