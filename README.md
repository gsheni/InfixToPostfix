InfixToPostfix
==============

This InfixToPostfix program will read in command line arguments that correspond to an infix expression. 

Each number and operator in the expression is expected to be space delimited.

The following conditions must be fulfilled
- The expression needs to have positive integers and atomico operators (+,-,*,/) as well as left and right parentheses.   
-	The first command line argument is either a positive integer or a left parenthesis. 
-	Each pair of positive integers is separated by an operator. 

Program will thrown an error in the following cases
- When there is no command line arguments.
- There will be an error when there is an operator that is not one of the atomic ones listed above.
- There is a parenthesis mistmatch. 

Example Input Expressions:
```txt
$	2 + 3 

$	3 \* 5 

$ 4 / 2 

$ 6 \* \( 3 + 9 \) 

$ \( 7 - 3 \) \* 2 

$	6 \* \( 5 - 2 + 4 \) 

$	\( \( 1 + 2 \) \* 3 + 4 \) \* 5 
```

___
The output of the program will just be the postfix expression.

Example Output Expressions:
```txt
$ 2 3 + 

$ 3 5 \* 

$ 4 2 / 

$ 6 3 9 + \* 

$ 7 3 - 2 \* 

$ 6 5 2 - 4 + \* =

$	1 2 + 3 \* 4 + 5 \* 
```
If there is an error in the input, the output will be a blank line.
