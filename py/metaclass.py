# Copyright (c) RenChu Wang - All Rights Reserved

import contextlib as ctxl
import copy
from typing import ClassVar, Self


@ctxl.contextmanager
def block(title: str):
    sep = "-" * 20
    try:
        print(sep + " " + title + " " + sep)
        yield
    except Exception as e:
        print("failed with error:", e)
    finally:
        print(sep + "-" * (len(title) + 2) + sep)
        print()


class Meta1(type):
    def __call__(self, *args, **kwargs):
        print("meta1.__call__ 1", args, kwargs)
        # Calls new then init.
        obj = super().__call__(*args, **kwargs)
        print("meta1.__call__ 2", args, kwargs)
        return obj


class Class1(metaclass=Meta1):
    def __new__(cls, i, j):
        print("c1.new 1")
        inst = super().__new__(cls)
        print("c1.new 2", type(inst))
        inst._init(i=i, j=j)
        print("c1.new 3", type(inst), inst)
        return inst

    # This would be called before ``__init__``.
    def _init(self, i, j):
        self.i = i
        self.j = j
        print(i, j, "init in new")

    # This would be called later.
    def __init__(self, i, j):
        self.i = i + 1
        self.j = j + 1
        print(self.i, self.j, "init outside new")

    def __repr__(self) -> str:
        return f"1(i={self.i},j={self.j})"


class Meta2(type):
    # This would be called first, when ``Class2`` is defined.
    def __new__(cls, *args, **kwargs):
        print("meta2.new", args, kwargs)
        inst = type.__new__(cls, *args, **kwargs)
        print("meta2.new", type(inst), inst)
        return inst

    def __call__(self, *args, **kwargs):
        """
        ``type.__call__`` calls ``__new__`` in subclass, then ``__init__`` on instance.
        See the ``type_call`` function in cpython.
        """
        print("meta2.__call__", args, kwargs)
        obj = super().__call__(*args, **kwargs)
        return obj


print("FIRST STATEMENT HERE")
print()


class Class2(metaclass=Meta2):

    def __init__(self, i, j) -> None:
        self.i = i
        self.j = j
        print(i, j, "init")

    def __repr__(self) -> str:
        return f"2(i={self.i},j={self.j})"


print()
print("META 2 NEW IS CALLED")
print()


class Class3:
    def __class_getitem__(cls, item):
        return f"3[{item.__name__}]"


class Meta4(type):
    def __getitem__(cls, item):
        print("meta4.getitem 1")
        cls = copy.deepcopy(cls)
        assert cls is copy.deepcopy(cls), "no copy takes place"
        cls.ARG = item
        print("meta4.getitem 2")
        return cls


class Class4(metaclass=Meta4):
    ARG: ClassVar[int] = 999

    def __new__(cls, *args, **kwargs):
        print("class4.new 1")
        result = object.__new__(cls)
        print("class4.new 2")
        return result

    def __init__(self, i, j):
        self.i = i
        self.j = j
        print("class4.init")

    def __repr__(self):
        return f"4[{type(self).ARG}](i={self.i},j={self.j})"


class Meta5(type):
    def __getitem__(cls, item):
        print("meta5.getitem 1")
        out = type(f"{cls.__name__}[{item}]", (cls,), {})
        print(out.__dict__)
        out = type(f"{cls.__name__}[{item}]", (cls,), {"ARG": 0})
        print(out.__dict__)
        out.ARG = item
        print(out.__dict__)
        print("meta5.getitem 2")
        return out


class Class5(metaclass=Meta5):
    ARG: ClassVar[int] = 999

    def __new__(cls, *args, **kwargs):
        print("class5.new 1")
        result = object.__new__(cls)
        print("class5.new 2")
        return result

    def __init__(self, i, j):
        self.i = i
        self.j = j
        print("class5.init")

    def __repr__(self):
        return f"5[{type(self).ARG}](i={self.i},j={self.j})"


class StrOk(str):
    # If we do ``__init__``, ``str.__new__`` will still be the original one.
    # This means that it has something that we wouldn't want e.g. encoding, errors fields.
    # Now this only applies to builtin types, because ``object.__new__`` ignores *args **kwargs.
    def __new__(cls, value: str, meta: int) -> Self:
        inst = str.__new__(cls, value)
        inst.meta = meta
        return inst


class StrNotOk(str):
    def __init__(self, value: str, meta: int) -> None:
        super().__init__(value)
        self.meta = meta


if __name__ == "__main__":

    with block("class 1"):
        c1 = Class1(1, 2.0)
        print(c1)

    with block("class 2"):
        c2 = Class2(1, 2.0)
        print(c2)

    with block("class 3"):
        print(Class3[str])
        print(type(Class3[str]))

    with block("class 4"):
        c4 = Class4(1, 2)
        print(c4)
        # This modifieds the ARG globally.
        c4 = Class4[888](2, 3)
        print(c4)
        c4 = Class4(3, 4)
        print(c4)

    with block("class 5"):
        c5 = Class5(1, 2)
        print(c5)
        c5 = Class5[888](2, 3)
        print(c5)
        c5 = Class5(3, 5)
        print(c5)

    with block("string ok"):
        # When using new is better
        str_ok = StrOk("ok", 11)
        print(str_ok, str_ok.meta)

    with block("string not ok"):
        str_fail = StrNotOk("fail", meta=11)
