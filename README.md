# ProbabilityLib
C++ Probability Functions Library

## Scope:
Provides a general purpose library of probability functions.

## Requirements:

PROBLIB_0001  Library shall include a function to calculate the factorial value for integer positive numbers

Note_0001	The factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n (https://en.wikipedia.org/wiki/Factorial)

PROBLIB_0001_0001	ProbabilityLib shall have a function to calculate the factorial value for integer positive numbers

PROBLIB_0001_0002	Factorial function shall receive INT or DOUBLE numbers as input

PROBLIB_0001_0003	Factorial function shall check if the input value is negative and return the check status 

PROBLIB_0001_0004	Factorial function shall check if the input value is on the right max input limit (i.e. 12 for INT input and 170 for DOUBLE input) and return the check status

PROBLIB_0001_0005	Factorial function shall check if the output value is overflowed and return check status

PROBLIB_0001_0006	Factorial function shall check if the input value is an integer and return check status

## Specification:

PROBLIB_0001_0001/0002_0001	Calculates the factorial of the integer "n". If "n" equals 0 the "factorial" function returns 1, otherwise the for loop uses the unsigned integer "i", which is incremented until it's equal to "n". At every interaction "n" is multiplied by the previous value. When "i" is equal to "n" the "factorial" function returns the unsigned integer "factorial". 

PROBLIB_0001_0001/0002_0002	Calculates the factorial of the unsigned long integer "n". If "n" equals 0 the "factorial" function returns 1, otherwise the for loop uses the unsigned long integer "i", which is incremented until it's equal to "n". At every interaction "n" is multiplied by the previous value. When "i" is equal to "n" the "factorial" function returns the unsigned long integer "factorial".

PROBLIB_0001_0003_0001	Checks if int n value is greater than zero. If not updates the "status" value ORing "status" with "enum validateNumber (@checkValue.h) = negative_number"

PROBLIB_0001_0003_0002	Checks if double n value is greater than zero. If not updates the "status" value ORing "status" with "enum validateNumber (@checkValue.h) = negative_number"

PROBLIB_0001_0004_0001	Checks if int n value is less or equal the max limit (12). If not updates the "status" value ORing "status" with "enum validateNumber (@checkValue.h) = overMaxLimit_number"

PROBLIB_0001_0004_0002	Checks if double n value is less or equal the max limit (170). If not updates the "status" value ORing "status" with "enum validateNumber (@checkValue.h) = overMaxLimit_number"

PROBLIB_0001_0005_0001	If "isInt" equals 1 checks is the double "factorial" exceeds the maximum output value allowed for unsigned int (4.294.967.295). In case the output exceeds this value "status" value is updated to indicate an error. If "isInt" equals 0 (default value) checks if the double "factorial" exceeds the maximum output value allowed for double variables (inf). In case the output indicates inf function updates the "status" value ORing "status" with "enum validateNumber (@checkValue.h) = overflow"

PROBLIB_0001_0006_001	Check if input number is an integer by checking if there is any decimal value using function modf@math.h. If not updates the "status" value ORing "status" with "enum validateNumber (@checkValue.h) = not_integer"


##Problem reports

001 If unsigned int "o" is negative, the program compiles and return factorial 0 and status 6, i.e. overMaxLimit_number and overflow. Since the 2's complement is used to compose negative numbers, compiler will understand the binary sequence as a positive number, e.g. -6 will be understood as 4294967290, since the 32 bits binary representation of -2 in  2's complement will be 11111111111111111111111111111010. The negative input read as unsigned integer will always represent a number equal or higher than 2.147.483.648, therefore the "factorial" calculation will always indicate an overflow error and return 0 as calculation result. -->
 * There is no workaround for determining the whether a negative value was addressed as input, however the function will always respond as if an overflow occurred and the error condition will be detected. --> If factorial uses int instead of unsigned int the problem would be detected. Since the max input unsigned int value allowed for factorial function is 12, the maximum output value is 479.001.600, which is supported by int variables. In addition the factorial calculation will stop in the first for loop since "i" will be greater than "n".  Therefore the variable type will be changed and the problem will be solved. --> Closed
 
 002 If int "o" is not an integer the program compiles and return factorial as if the input was an integer, i.e. disregards the decimal values. Status = 0. C++ automatically cast the float value to int and discard the decimal value (https://www.quora.com/If-I-assign-an-integer- variable-to-a-float-value-in-C++-Why-is-the-variable-initialized-with-the-integer- part-And-what-happens-in-the-opposite-case). There is no workaround for this scenario. ProbabilityLib documentation alerts for this constraint. --> Closed
 