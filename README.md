# C-PROJECT

- This is a c project compilations that are use to test the level of `c`
  programming.

- Need to make an `out` directory to keep all of the binary.

```bash
mkdir -p out/
```

- To run, just type:

```bash
./build.sh
#OR
bash build.sh
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
- The compilations and the flags are on the `build.sh` file

## 3. Input Gesture Detection

- Reference:
  - [input gesture](https://www.raylib.com/examples.html)
- This is a input gesture detection using `raylib`.
- The compilations and the flags are on the `build.sh` file
