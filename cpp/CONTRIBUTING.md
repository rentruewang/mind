# Contributing

## Code style

01. Use ISO Cpp's code style (`snake_case_everything`).
02. Except for private member variable, (`suffix_with_underscore_`).
03. Use `clang-format` (`BasedOnStyle: Chromium; IndentWidth: 4; IncludeBlocks: Regroup`).
04. Use `=` initialization only for pointer / reference types.
05. Use `{}` universal initialization for everything else.
06. Except when ambiguous, then use `()` normal initialization.
07. Never omit braces after `if` / `else` / `while` / `for`.
08. Except for side effects (empty body). In which case put a `;` as the body.
09. Use `///` for documentation strings.
10. Follow [CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines).
