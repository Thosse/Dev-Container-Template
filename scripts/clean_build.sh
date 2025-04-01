#!/bin/bash

# Get absolute path of the project directory
SCRIPT_DIR="$(dirname $(realpath $0) )"
PROJECT_DIR="$SCRIPT_DIR/.."
SOURCE_DIR="$PROJECT_DIR"
BUILD_DIR="$PROJECT_DIR/build"

GENERATOR="Unix Makefiles"

echo "=============================="
echo "Remove existing build directory"
echo "=============================="
# Must delete build directory before generating new one, to avoid
# Command line error: Option --cpu can only occur once
if [ -d "$BUILD_DIR" ]; then
    rm -rf "$BUILD_DIR"
fi

echo "=============================="
echo "Generate CMake build directory"
echo "=============================="

cmake -S "$SOURCE_DIR" -B "$BUILD_DIR" -G "$GENERATOR"

echo "========================"
echo "Build Executable/Library"
echo "========================"

cmake --build "$BUILD_DIR"

echo "========="
echo "Run Tests"
echo "========="
if [ -f "$BUILD_DIR/tests/sudoku_tests" ]; then
    "$BUILD_DIR/tests/sudoku_tests"
fi
