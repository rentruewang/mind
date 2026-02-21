/// Copyright (c) RenChu Wang - All Rights Reserved

class ConstMember {
   public:
    ConstMember(int x) : member_(x) {}

   private:
    const int member_;
};

class NormalMember {
   public:
    NormalMember(int x) : member_(x) {}
    int member() const { return member_; }

   private:
    int member_;
};

int main() {
    // No problem doing this.
    NormalMember nm{3};
    nm = NormalMember{4};

    ConstMember cm{9};
    // const_member& const_member::operator=(const_member&&)’ is implicitly
    // deleted because the default definition would be ill-formed
    //
    // operator= is deleted because of const member.
    //
    //  cm = const_member{100};
}
