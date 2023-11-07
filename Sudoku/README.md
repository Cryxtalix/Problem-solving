# Sudoku solver written in C

## Instructions
* Sudoku board input in the form of a text file, with 9 lines of 9 numbers, with no spaces and '0' to represent blank cells.
* Place file in the root folder and enter the file name in the code.
* Run "make" command in terminal.
* Check the output folder for the generated solution.

## Future improvements
* Dedicated input folder
* Enter file name through commands
* Tests

### Comments
* Avoids using heap memory(no malloc).
* Filenames are limited to about 40 characters.
* Judicious use of "goto" in check_board() function, only used for escaping multiple loops.
* Use of a recursion function to guess inputs. Sudoku puzzle in "input2.txt" takes 9 recursion levels just to find the single solution.