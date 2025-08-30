
# C++ DSA Workspace

This repository contains C++ implementations and exercises for Data Structures and Algorithms (DSA). It is organized for easy building and testing using CMake.

## Structure

- **src/**: Main source files and examples.
	- `main.cpp`: Entry point for the main program.
	- `testCard.cpp`: Test harness for the CreditCard class.
	- `Example1-4-5.cpp`: Example of root-finding using bisection.
- **exercises/**: Exercise implementations.
	- `CreditCard.cpp`: Implementation of the CreditCard class.
	- `ex1_stack.cpp`: Stack exercise implementation.
- **include/**: Header files.
	- `CreditCard.hpp`: Header for the CreditCard class.
- **notes/**: Study notes and explanations.
	- `chapter1.txt`: Notes for chapter 1.
- **build/**: Build output directory (created by CMake).

## Building

This project uses CMake for building. To build all targets:

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

## Executables

After building, the following executables are available in the `build/` directory:

- `main`: Runs the main program.
- `ex1_stack`: Runs the stack exercise.
- `ex_creditcard`: Runs the CreditCard test harness.
- `ex_ptfunc`: Runs the root-finding example (`Example1-4-5.cpp`).

## Example Usage

### CreditCard Test
Run the CreditCard test harness:
```bash
./ex_creditcard
```

### Root-Finding Example
Run the root-finding example:
```bash
./ex_ptfunc
```

## Requirements
- C++17 or newer
- CMake 3.10 or newer

## Notes
- All exercises and examples are for educational purposes.
- Contributions and suggestions are welcome!
