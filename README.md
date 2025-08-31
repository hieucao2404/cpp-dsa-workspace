
# C++ DSA Workspace

This repository contains C++ implementations and exercises for Data Structures and Algorithms (DSA). It is organized for easy building and testing using CMake.


## Structure

- **src/**: Main source files and examples.
	- `main.cpp`: Entry point for the main program.
	- `testCard.cpp`: Test harness for the CreditCard class.
	- `Example1-4-5.cpp`: Example of root-finding using bisection.
	- `useDatabase.cpp`: Example usage of the database exercise.
- **exercises/**: Exercise implementations.
	- `CreditCard.cpp`: Implementation of the CreditCard class.
	- `ex1_stack.cpp`: Stack exercise implementation.
	- `Personal.cpp`: Implementation of the Personal class for the database exercise.
- **include/**: Header files.
	- `CreditCard.hpp`: Header for the CreditCard class.
	- `personal.hpp`: Header for the Personal class.
	- `database.hpp`: Header for the Database template class.
- **notes/**: Study notes and explanations.
	- `chapter1.txt`: Notes for chapter 1.
- **build/**: Build output directory (created by CMake).
- **PersonalDB.txt**: Sample database file for the Personal database exercise.

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
- `ex_useDatabase`: Runs the Personal database exercise.


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

### Personal Database Exercise
Run the database exercise:
```bash
./ex_useDatabase
```
When prompted, enter the file name:
```
PersonalDB.txt
```
Follow the menu to add, find, or modify records in the database.

## Requirements
- C++17 or newer
- CMake 3.10 or newer

## Notes
- All exercises and examples are for educational purposes.
- Contributions and suggestions are welcome!
