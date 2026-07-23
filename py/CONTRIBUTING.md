# Contributing

## Code style

0. Try to mimick the surrounding code.
1. Mainly use PEP 484.
2. All module imports, if not top level, use `from a import b [as c]` (no `import a.b [as c]`)[^1].
3. All 1st party (in tree) objects should not be qualified [^2]
4. All 3rd objects (non modules) should be qualified with their module [^3].
5. Use autoflake, isort, black to format the code, default settings.
6. `__init__` should use `from .module import *` and modules should define an `__all__`, under the import section.
7. Try to add type hints as little as you can, while maintaining as high coverage as you can (use LSP).
8. Prefer 1 word (plural except abbreviations) for the modules to be imported. Imports are long enough.
9. Avoid global state, unless using it leans to cleaner code (e.g. tied to a scope like context managers, or global resource like network / device).

[^1]: E.g. some libraries have a lot of functionalities (e.g. `torch`), it's common to do `from torch import nn, optim...`. `import as` would result in many lines.

[^2]: Example: Always `from our.module import func, Class`, not `module.func, module.Class`. This reduces clutter, ensure no duplicae names on 1st party objects, and is more in line with my C++ style.

[^3]: Example: `torch.Tensor` not `from torch import Tensor`.

[^4]: See global state section.
