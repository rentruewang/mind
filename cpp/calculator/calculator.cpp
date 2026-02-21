/// Copyright (c) RenChu Wang - All Rights Reserved

#include "calculator.hpp"

#include <string>

using namespace std;

shared_ptr<expression> expression::operator+(
    const shared_ptr<expression>& other) const {
    return make_shared<evaluation>(shared_from_this(), other, "+",
                                   [](int a, int b) { return a + b; });
}

shared_ptr<expression> expression::operator-(
    const shared_ptr<expression>& other) const {
    return make_shared<evaluation>(shared_from_this(), other, "-",
                                   [](int a, int b) { return a - b; });
}

shared_ptr<expression> expression::operator*(
    const shared_ptr<expression>& other) const {
    return make_shared<evaluation>(shared_from_this(), other, "*",
                                   [](int a, int b) { return a * b; });
}

shared_ptr<expression> expression::operator/(
    const shared_ptr<expression>& other) const {
    return make_shared<evaluation>(shared_from_this(), other, "/",
                                   [](int a, int b) { return a / b; });
}

expression::~expression() {}

Lit::Lit(int data) : data_(data) {}

shared_ptr<const expression> Lit::simplify() const {
    return shared_from_this();
}

Lit::operator string() const {
    return to_string(data_);
}

int Lit::data() const {
    return data_;
}

Lit::~Lit() {}

Var::Var(string data) : data_(data) {}

shared_ptr<const expression> Var::simplify() const {
    return shared_from_this();
}

Var::operator string() const {
    return data_;
}

Var::~Var() {}

Eval::Eval(shared_ptr<const expression> left,
           shared_ptr<const expression> right,
           string token,
           function<int(int, int)> func)
    : left_(left), right_(right), token_(token), func_(func) {}

shared_ptr<const expression> Eval::simplify() const {
    auto lp = dynamic_pointer_cast<const Lit>(left_->simplify());
    auto rp = dynamic_pointer_cast<const Lit>(right_->simplify());

    // Do nothing because no simplification is needed.
    if (lp == nullptr || rp == nullptr) {
        return shared_from_this();
    }

    return make_shared<Lit>(func_(lp->data(), rp->data()));
}

Eval::operator string() const {
    return string(*left_) + " " + token_ + " " + string(*right_);
}

Eval::~Eval() {}
