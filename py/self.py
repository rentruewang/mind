# Copyright (c) RenChu Wang - All Rights Reserved

import abc
import typing
from collections import abc as cabc

T = typing.TypeVar("T", bound="HasChildren", covariant=True)


class HasChildren(typing.Protocol[T]):
    @abc.abstractmethod
    def children(self) -> cabc.Sequence[T]: ...


class HasSelfAsChildren(HasChildren["HasSelfAsChildren"]):
    # It does autocomplete. Seems fine.
    def children(self) -> cabc.Sequence["HasSelfAsChildren"]:
        return []
