# Copyright (c) RenChu Wang - All Rights Reserved


class TestClass:
    def __init__(self) -> None:
        self.x = 1
        print(self.x)

    def __getattr__(self, attr: str) -> None:
        print("attr", attr)
        return 10


class C:
    def __repr__(self):
        return repr(self.__dict__)

    def __getattr__(self, name: str):
        # `self.__dict__` does not go through here, because the object already has it.
        # So `object.__getattribute__` would find it first.
        try:
            return self.__dict__[name]
        except KeyError:
            raise AttributeError(name)

    def __setitem__(self, name: str, val):
        self.__dict__[name] = val


if __name__ == "__main__":
    print("t.x=", TestClass().x)
    print("t.y=", TestClass().y)

    print("---")
    c = C()
    print(c)
    c.a = 4
    print(c)
