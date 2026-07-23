# Contributing

## Shared code style

Try to mimick the surrounding code.

Prefer context managers (in C++ RAII guard) to manage scope-related setups.

> Context managers are fundamentally mutating non-local state (context). Why?
> Because it's tied to a scope.
> And it allows you to do some operation, only in a certain scope.
>
> 1. It must be mutating state. Why?
> Immutability has no concept of time (functional programming),
> which means that after initializing the variable is forever.
> If something cannot be used after a certain scope ends,
> this means that the end of scope has mutated that something,
> moving it into an invalid state.
> 
> 2. Tying to a scope means it doesn't work with variables inside a scope,
> who would get cleaned up in a normal, non context managing scope.
> So, it is tied to non-local state.

## Python code style

1. Mainly use PEP 484.
2. All module imports, if not top level, use `from a import b [as c]` (no `import a.b [as c]`)[^1].
3. All 1st party (in tree) objects should not be qualified [^2]
4. All 3rd objects (non modules) should be qualified with their module [^3].
5. Use autoflake, isort, black to format the code, default settings.
6. `__init__` should use `from .module import *` and modules should define an `__all__`, under the import section.
7. Try to add type hints as little as you can, while maintaining as high coverage as you can (use LSP).
8. Prefer 1 word (plural except abbreviations) for the modules to be imported. Imports are long enough.


## C++ code style

1. Use python's style (`ClassName`, `function_name`, `var_name`, `CONSTANT`).
2. Except for private member variable, (`suffix_with_underscore_`).
3. Use `clang-format` (`BasedOnStyle: Chromium; IndentWidth: 4; IncludeBlocks: Regroup`).
4. Use `=` initialization only for pointer / reference types.
5. Use `{}` universal initialization for everything else.
6. Except when ambiguous, then use `()` normal initialization.
7. Never omit braces after `if` / `else` / `while` / `for`.
8.  Except for side effects (empty body). In which case put a `;` as the body.
9.  Use `///` for documentation strings.
10. Try avoiding polluting the global namespace (`using` statements).
11. If there is a collision e.g. between `std` and ours, only do `using` on ours.
12. Use `.hpp` `.cpp` for files names, when possible.
13. Follow [CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).


[^1]: E.g. some libraries have a lot of functionalities (e.g. `torch`), it's common to do `from torch import nn, optim...`. `import as` would result in many lines.

[^2]: Example: Always `from our.module import func, Class`, not `module.func, module.Class`. This reduces clutter, ensure no duplicae names on 1st party objects, and is more in line with my C++ style.

[^3]: Example: `torch.Tensor` not `from torch import Tensor`.
