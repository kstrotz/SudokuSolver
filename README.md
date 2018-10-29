SudokuSolver

This project is a simple program to solve Sudoku puzzles as a way to learn
C programming.  It may not be the most efficient, but it makes use of a 
variety of important topics:
	
	- Functions
	- Memory allocation
	- Pointers
	- Structures
	- Enums
	- For loops
	- While loops
	- Basic error checking
	- Arrays
	- User input
	- Headers
	- Header guards
	- Compile time options
	- Multiple source files
	- Basic test implementation
	- Git usage
	
This is intended as a purely personal project, and no guarantee is made of 
any functionality.  Feel free to fork or clone as desired.

To use:

	1. git clone https://github.com/kstrotz/SudokuSolver.git
	2. cd src
	3. gcc main.c funcs.c [-o ../target/debug/solver] [-D TEST]

The -o flag allows you to specify an output file. Default is ./a.out
The -D flag with the TEST parameter will compile using a test grid. Leave
this flag out to allow the user to input a grid.

