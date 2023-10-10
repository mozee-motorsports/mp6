Literally Ripped from 2600 codestyle and CSSE codestyle

# Source Files
```c
/**
 * @file throttle.h
 * @author Caleb Andreano (caleb@andreano.dev, andreanoc@msoe.edu)
 * @brief API for accessing throttle control functions for the MP6
 * gas motor. 
 * 
 * @version 1
 * @date 2023-10-10
 */
```

- All files need to have file headers in this format. You can use the `doxygen` VSCode extension which lets you type `/**` and enter and will autofill these fields. The author field should have both your MSOE email and your personal email, so that future team members can trace you down after you graduate. 
- All source files should be explicitly documented with inline comments

## File names
- The file extension for C source files should be `.c`
- The file extension for header files should be `.h`
- The file extension for assembly files should be `.s`

Note the casing here: we need to have consistent casing for our file extensions as the project Makefile uses a regular expression to pass files to the compiler/assembler, and it only checks the lowercase extensions. 


## Header File structure
All header files should use compile guards:
```c
#ifndef FILENAME_H
#define FILENAME_H

/* some code */

#endif /* FILENAME_H */
```
Header files should only use typedefs if the defined types are publicly exposed. Otherwise, forward declarations should be in the source file right before the struct it's referring to:
```c
typedef struct node node;
struct node {
	node* left;
	node* right;
}
```
## Source File structure
1. File header
2. Include statements
3. Global variables (unexposed `#defines` followed by constant expressions)
4. Prototypes
5. Function definitions

## Commenting
Every function in a source file needs a doxygen comment. 
```c
/**
 * @brief Does something really awesome with the input values
 * @param value1 - the first value to process
 * @param value2 - the second value to process
 * @return The result of the awesome computation 
 * @return -1 if the input values are not valid
 */
```
Structs and unions should also have the same kind of comment.
```c
/**
 * @brief - Structure to do something with values
 * @property value1 - the first property of the structure
 * @property value2 - the second property of the structure
 */
```

## Other
- Name all of your variables reasonably. You can use stuff like `i` in a for loop, but don't do any `int a = ...`
- Tabs, not spaces. 4 spaces is one indent level. 
- Variables and functions should be lower snake case, like `variable_name`. Constants and `#defines` should be all caps. 
- 100 Character limit per line. If a function is over one line, it should be like
```c
printf(
	"string", 
	arg1, 
	arg2
);
```
- I swear to god, no magic numbers. I do not ever want to see a number outside of a constant declaration of a `#define` that is not either `0` or `1`, and I never want to see `0`s or `1`s next to each other. 
- Local functions should always be `static`.
- Pointers to registers/memory mapped IO should always be `volatile`.
- No infinite loops, besides the `while(1)` in main. ????
- Every function should have a purpose, no code that doesn't need to be there
- Code should make sense to people that didn't write it. Inline comment everything
- Code should compile with no warnings or errors
- MISRA: add all these, VSCode extension 
