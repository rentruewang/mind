# Copyright (c) RenChu Wang - All Rights Reserved

import typing
from collections import abc as cabc

Real = typing.TypeVar("Real", int, float)


def f(n: float):
    print(n)


def fnum(a: Real, b: Real) -> None:
    print(a, b, a + b)


AnyStr = typing.TypeVar("AnyStr", str, bytes)


def fstr(a: AnyStr, b: AnyStr) -> None:
    print(a, b, a + b)


P = typing.ParamSpec("P")
R = typing.TypeVar("R")


def print_before_and_after(function: cabc.Callable[P, R]) -> cabc.Callable[P, R]:
    def _function(*args: P.args, **kwargs: P.kwargs) -> R:
        print("function:", function)
        print(args, kwargs)
        out = function(*args, **kwargs)
        print(out)
        return out

    return _function


if __name__ == "__main__":
    f(int(3))

    fnum(int(1), int(2))
    fnum(float(1), float(2))
    # ints can be casted to floats. Will pass.
    fnum(int(1), float(2))

    fstr("hello", "world")
    fstr(b"hello", b"world")
    # bytes cannot be casted to string. Will fail.
    # fstr(b"hello", "world")

    fstr_print = print_before_and_after(fstr)
    fstr_print("hello", "world")
