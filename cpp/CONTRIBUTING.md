# Contributing

## Code style

00. Try to mimick the surrounding code.
01. Use python's style (`ClassName`, `function_name`, `var_name`, `CONSTANT`).
02. Except for private member variable, (`suffix_with_underscore_`).
03. Use `clang-format` (`BasedOnStyle: Chromium; IndentWidth: 4; IncludeBlocks: Regroup`).
04. Use `=` initialization only for pointer / reference types.
05. Use `{}` universal initialization for everything else.
06. Except when ambiguous, then use `()` normal initialization.
07. Never omit braces after `if` / `else` / `while` / `for`.
08. Except for side effects (empty body). In which case put a `;` as the body.
09. Use `///` for documentation strings.
10. Try avoiding polluting the global namespace (`using` statements).
11. If there is a collision e.g. between `std` and ours, only do `using` on ours.
12. Follow [CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).
