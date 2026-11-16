# Build System, Installation & Usage Guide

## 1. Prerequisites & Environment

The project compiles on POSIX-compliant operating systems (Linux, macOS) and requires:
- **C Compiler**: `cc`, `gcc`, or `clang`
- **Build System**: GNU `make`
- **Standard Libraries**: Standard C library (`libc`)

---

## 2. Compilation with Make

The project includes a standard 42 `Makefile` configured with strict compiler flags:
```makefile
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = push_swap
```

### Supported Makefile Targets

| Target | Command | Purpose |
|---|---|---|
| `all` | `make` or `make all` | Compiles all source files and produces the `push_swap` binary. |
| `$(NAME)` | `make push_swap` | Links compiled object files (`.o`) into executable. |
| `clean` | `make clean` | Removes compiled object files (`.o`). |
| `fclean` | `make fclean` | Removes compiled object files (`.o`) and the `push_swap` binary. |
| `re` | `make re` | Rebuilds the entire project from scratch (`fclean all`). |

---

## 3. Usage & Execution Syntax

### Command Syntax
```bash
./push_swap [list_of_integers]
```

### Examples

#### Example 1: Separate Parameters
```bash
$ ./push_swap 2 1 3 6 5 8
ra
pb
ra
pb
...
```

#### Example 2: Single Quoted Parameter
```bash
$ ./push_swap "2 1 3 6 5 8"
```

#### Example 3: Mixed Quoted & Separate Parameters
```bash
$ ./push_swap "2 1" 3 "6 5 8"
```

---

## 4. Verification with the Official 42 Checker

The repository includes pre-compiled official 42 checkers:
- `checker_linux`: For Linux x86_64 systems.
- `checker_Mac`: For macOS x86_64 systems.

Make the checker executable (if not already):
```bash
chmod +x checker_linux checker_Mac
```

### Basic Verification
Pipe `push_swap` output directly into the checker:
```bash
$ ./push_swap 3 2 1 | ./checker_linux 3 2 1
OK
```

### Count Operations While Checking
Use `wc -l` to count generated instructions:
```bash
$ ARG="3 2 1"; ./push_swap $ARG | tee /dev/tty | ./checker_linux $ARG
sa
rra
OK
```

### Large Random Input Testing
Generate 100 random numbers and verify both validity and operation count:
```bash
# On Linux
ARG=$(shuf -i 0-1000 -n 100 | tr '\n' ' ')
echo "Operations: $(./push_swap $ARG | wc -l)"
./push_swap $ARG | ./checker_linux $ARG
```

Example terminal output:
```text
Operations: 638
OK
```

---

## 5. Build Troubleshooting & Environment Notes

### Note 1: GCC 12+ Compiler Warning (`-Werror=use-after-free`)
On modern Linux distributions equipped with GCC 12 or newer, compiling unmodified code with strict `-Werror` can encounter an error on line 73 of `push_swap.c` where `size` was freed before `free_arguments(splited, size->a)`.

To build cleanly on modern GCC toolchains without altering the existing C code:
```bash
cc -Wall -Wextra -Wno-use-after-free *.c -o push_swap
```
*(See [PROJECT_AUDIT.md](PROJECT_AUDIT.md#defect-1-use-after-free-in-ft_free_all) for detailed defect documentation).*

### Note 2: Non-Interactive Shells (`clear` utility in `shifuuu`)
In headless subshells or CI runners where `TERM` is not set, the `clear` command in `Makefile:39` can return exit code 1. Set `TERM=xterm` when building in automated environments:
```bash
TERM=xterm make
```
