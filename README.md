# GCD Calculator (Euclidean Algorithm) — C and Guile Scheme

Two small command-line programs that interactively read two integers and print their greatest common divisor (GCD) using the Euclidean algorithm. One implementation is written in C, the other in Guile Scheme.

The project is intended as a minimal, readable reference: each program has an English-language interface, a banner-style frame, input validation, and handles negative numbers via absolute values.

## Authors

- **Assistant (AI)** — primary author: initial implementations, interface design, input validation, documentation.
- **User** — project idea, requirements, testing, review.

## Repository contents

- `gcd.c` — C implementation (C11).
- `gcd.scm` — Guile Scheme implementation (with shebang).
- `README.md` — this file.
- `LICENSE` — MIT License.

## Tested on

Both programs were built and run on **Linux** (Debian-based distribution, GCC and Guile 3.x). No platform-specific code is used; they should work on any POSIX-like system with a C compiler and/or Guile installed.

## Requirements

### C version

- A C compiler supporting C11 (e.g. `gcc` or `clang`).
- Standard C library only — no external dependencies.

On Debian/Ubuntu:

```bash
sudo apt install build-essential
```

### Scheme version

- Guile 2.x or 3.x.
- Uses the standard module `(ice-9 rdelim)` for `read-line`.

On Debian/Ubuntu:

```bash
sudo apt install guile-3.0
```

## Building and running — C

Compile:

```bash
gcc -std=c11 -Wall -Wextra -O2 -o gcd gcd.c
```

Run:

```bash
./gcd
```

Example session:

```text
******************************
***   GCD CALCULATOR       ***
***   Euclidean algorithm  ***
******************************

>>> First number:  42
>>> Second number: 30

*** >>> RESULT <<< ***
>>> GCD(42, 30) = 6
*** >>> DONE <<< ***
```

## Building and running — Guile Scheme

The Scheme file starts with a shebang (`#!/usr/bin/env guile … !#`), so it can be run directly if it is executable:

```bash
chmod +x gcd.scm
./gcd.scm
```

Alternatively, run it explicitly through the interpreter (shebang not required in this case):

```bash
guile gcd.scm
```

Example session is identical to the C version.

## Input rules

- Each prompt expects a single integer (decimal, optionally signed).
- Leading/trailing whitespace is ignored.
- On invalid input the program prints `Not a number, try again.` and re-prompts (C version also reports out-of-range values).
- On end of input (Ctrl-D) the program prints `No input, exiting.` and terminates with a non-zero exit code.

## Algorithm

Both implementations use the classical Euclidean algorithm:

```text
gcd(a, b):
    while b != 0:
        r = a mod b
        a = b
        b = r
    return a
```

Negative inputs are normalized with `abs` before the loop, so the result is always non-negative. This matches the definition of (GCD) used in the accompanying lecture notes on the Euclidean algorithm.

## License

Released under the MIT License. See `LICENSE`.