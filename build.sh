#!/bin/bash

set -xe

CFLAGS="-O3 -Wall -Wextra -ggdb -I./thirdparty/ -I. $(pkg-config --cflags raylib)"
LIBS="-lm $(pkg-config --libs raylib) -lglfw -ldl -lpthread"

mkdir -p out

# clang -o out/calculator calculator.c -lm
# clang $CFLAGS -o out/student_management_system student_management_system.c $LIBS
clang $CFLAGS -o out/input_gesture input_gesture_detection.c $LIBS
