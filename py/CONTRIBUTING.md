# Contributing

## Code style

0. Try to mimick the surrounding code.
1. Mainly use PEP 484.
2. All module imports, if not top level, use `from a import b` (no `import a.b`).
3. All objects (non modules) should be qualified (e.g. `module.func`, `module.Class`, not `from module import func, Class`).
4. Use autoflake, isort, black to format the code, default settings.
5. `__init__` should use `from .module import *` and modules should define an `__all__`, under the import section.
6. Try to add type hints as little as you can, while maintaining as high coverage as you can (use LSP).
