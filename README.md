# C-PROJECT

- This is a c project compilations that are use to test the level of `c`
  programming.

- Need to make an `out` directory to keep all of the binary.

```bash
mkdir -p out/
```

## 1. Calculator

- Reference:
  - https://github.com/BradStevenson/Simple-C-Calculator
- Need to compile using `clang`, specify the outdir using `-o` flags, and need
  to link with `math.h` library using `-lm` flags:

```bash
clang calculator.c -o out/calculator -lm
./out/calculator
```

## 2. Student Management System

- Reference:
  - https://github.com/AveyBD/student-management-system
- Use [raylib](https://www.raylib.com/) to render the screen.
- Please read this [wiki](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux) on how to install on linux.
  - Please use `cmake` to build.
