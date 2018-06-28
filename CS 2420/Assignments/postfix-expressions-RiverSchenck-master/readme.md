# Converting Infix to Postfix Expressions

Infix and Postfix notations are two different but equivalent ways of writing expressions. It is easiest to demonstrate the differences by looking at examples of operators that take two operands.

## Infix notation: X + Y
Operators are written in-between their operands. This is the usual way we write expressions. An expression such as A * ( B + C ) / D is usually taken to mean something like: "First add B and C together, then multiply the result by A, then divide by D to give the final answer."
Infix notation needs extra information to make the order of evaluation of the operators clear: rules built into the language about operator precedence and associativity, and brackets ( ) to allow users to override these rules. For example, the usual rules for associativity say that we perform operations from left to right, so the multiplication by A is assumed to come before the division by D. Similarly, the usual rules for precedence say that we perform multiplication and division before we perform addition and subtraction.

## Postfix notation (also known as "Reverse Polish notation"): X Y +
Operators are written after their operands. The infix expression given above is equivalent to A B C + * D / 
The order of evaluation of operators is always left-to-right, and brackets cannot be used to change this order. Because the "+" is to the left of the "*" in the example above, the addition must be performed before the multiplication. 
Operators act on values immediately to the left of them. For example, the "+" above uses the "B" and "C". We can add (totally unnecessary) brackets to make this explicit: 
( (A (B C +) *) D /) 
Thus, the "*" uses the two values immediately preceding: "A", and the result of the addition. Similarly, the "/" uses the result of the multiplication and the "D".

## Goals:
The goal of this assignment is to gain familiarity working with stacks and implementing good class design (proper use of const, and access specifiers).  Problem 9 from Chapter 7 (p. 449) has been slightly modified as follows.

## Requirements:
Design a class named Infix that stores the infix and postfix strings  Remember to carefully consider the use of const and access specifiers. Your class will need to handle +, -, *, /, and ^ (exponentiation). You may assume that the expressions you will process are error free. The class must include the following public operations:

+ void setInfix(std::string) – stores the infix expression, and updates the postfix expression.
+ std::string getInfix() – retrieves the infix expression
+ std::string getPostfix() – retrieves the postfix expression
+ int getNumberOfOperators() – returns the number of operators contained in the expression
+ int getNumberOfOperands() – returns the number of operands contained in the expression
+ void clear() – resets the infix/postfix expression to an empty string
+ Infix(std::string ) constructor – takes a string parameter as an infix expression, stores the infix expression and sets the postfix expression.
+ Default constructor – stores an empty infix/postfix expression

You may find it useful to include these additional functions:
+ convertToPostfix – Converts the infix expression into a postfix expression. The resulting postfix expression is stored in pfx.
+ bool precedence – Determines the precedence between two operator parameters.  If the first operator is of higher or equal precedence than the second operator, it returns the value true; otherwise, it returns the value false.

You may use the STL stack class or your own stack implementation.

## Helpful Hints:

The following process can be used to convert an infix expression to a postfix expression. Suppose *infx* is a string that represents the infix expression and *pfx* is a string that represents the postfix expression. The rules to convert infx to pfx are as follows:

1. Initialize *pfx* to an empty string and also initialize the stack.
2. Get the next symbol from *infx* and store it in a string called *sym*. (Note that a symbol could be an operator, a parenthesis (left or right), a single digit, or an entire number. For 
example, if *infx* is "123 + 456", then the first symbol is 123, not 1. The second symbol is 
a + character. The third symbol is 456. Whitespaces of any kind are not symbols.)

    + If *sym* is an operand (i.e. a number), append *sym* to *pfx*.

    + If sym is '(', push sym into the stack.

    + If *sym* is ')', pop and append all the symbols from the stack until the most recent left parenthesis. Pop and discard the left parenthesis.

    + If *sym* is an operator (i.e. '+', '-', '*', '/', '^'):

        + Pop and append all the operations from the stack to *pfx* that are above the most recent left parenthesis and have precedence greater than or equal to *sym*.
        + Push *sym* onto the stack.

3. After processing *infx*, some operators might be left in the stack. Pop and append to *pfx* everything from the stack.

Standard precedence for arithmetic operators:
1. exponents
2. multiplication and division
3. addition and subtraction
