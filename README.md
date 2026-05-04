# Calculator

Console calculator for mathematical expressions with runtime-loaded plugins.

## Features

- **Recursive descent parser** — correct operator precedence (`^`, `*`/`/`, `+`/`-`), nested functions; modular lexer, parser, AST, plugin manager.
- **Extensible via plugins** — built‑in functions (`sin`, `cos`, `pow`, `ln`, `deg`) are loaded from shared libraries that implement a common interface (`plugin_interface.h`); drop a new `.so`/`.dll` into the `plugins/` folder and use it instantly — no need to recompile the calculator.
- **Cross‑platform** — works on Linux and Windows, using `dlopen`/`LoadLibrary` behind a clean abstraction.

## Error handling

```text
cos(sinn(3.14))
ERROR: invalid name of function

1 + ln(-1)
ERROR: invalid args in function: ln

1/sin(0)
ERROR: division by zero

(5 + 5) * (5
ERROR: invalid bracket expression
```

## Examples

```text
cos(deg( 180 ) )
cos(deg(180.00)) = -1

(deg(180^--1) ^ 2) ^0.5
deg(180.00 ^ --1.00) ^ 2.00 ^ 0.5000 = 3.14159

-2^-2
-2.00 ^ -2.00 = -0.25

sin(2 - 1* ( 2*( cos(0))))
sin(2.00 - 1.00 * 2.00 * cos(0.0000)) = 0

```


## Build

Requires CMake and a C++20-compatible compiler.

```bash
cmake -S . -B build
cmake --build build
```