# Contributing

## Code style

0. Try to mimick the surrounding code.
1.  Use python's style (`ClassName`, `function_name`, `var_name`, `CONSTANT`).
2.  Except for private member variable, (`suffix_with_underscore_`).
3.  Use `clang-format` (`BasedOnStyle: Chromium; IndentWidth: 4; IncludeBlocks: Regroup`).
4.  Use `=` initialization only for pointer / reference types.
5.  Use `{}` universal initialization for everything else.
6.  Except when ambiguous, then use `()` normal initialization.
7.  Never omit braces after `if` / `else` / `while` / `for`.
8.  Except for side effects (empty body). In which case put a `;` as the body.
9.  Use `///` for documentation strings.
10. Try avoiding polluting the global namespace (`using` statements).
11. If there is a collision e.g. between `std` and ours, only do `using` on ours.
12. Use `.hpp` `.cpp` for files names, when possible.
13. Follow [CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).
