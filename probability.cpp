/*
 *  probability.cpp
 *
 *  Created on: May 5, 2018
 *  Version:	1.001
 *  Author:     Andre Moraes
 */

#include "probability.h"
#include "checkValue.h"

/* Calculates the factorial of the integer "n". If "n" equals 0 the
 * "factorial" function returns 1, otherwise the for loop uses the
 * unsigned integer "i", which is incremented until it's equal to "n". At
 * every interaction "n" is multiplied by the previous value. When "i" is
 * equal to "n" the "factorial" function returns the unsigned integer
 * "factorial". PROBLIB_0001_0001/0002_0001
 *
 * Function also checks if the input is negative, exceeds the
 * maximum input value (12), overflows the output value, and if input is
 * an integer. If the input check proves true in any case, the function
 * returns 0 and the "status" value, which informs the problems found.
 * Moreover, function also check the output for overflow and in case of
 * error the function returns 0 and the "status" value, which informs the
 * problems found.
 *
 * If an float value is addressed to a int and the this int is sent to factorial
 * function, or if a float value is sent to factorial function and the result is
 * addressed to an int variable, C++ automatically cast the float value to int and
 * discard the decimal value. This scenario will not set an error condition warning.
 * There is no workaround for this scenario and special attention for this limitation
 * is required.
 */
unsigned int probability::factorial(int n){
	unsigned int factorial = 1;
	if (n == 0) return 1;
	double factorialDouble = 1;
	for(int i=1; i<=n; ++i) factorialDouble = factorialDouble * i;

	checkValue check;														// checkValue class defined at check
	status = check.notNegative(n,status);									// Checks if the input is negative
	status = check.atMaxLimit(n,status);									// Checks is the input exceeds the maximum value (12)
	double nDouble = static_cast<double>(n);								// Cast input "n" as double to be checked as integer
	status = check.isInteger(nDouble,status);								// Checks is the input is an integer
	bool isInt = true;														// Inform function check.overflowedValue that the input represents an integer
	status = check.overflowedValue(factorialDouble,status,isInt);			// Checks is the output overflow the variable limit
	if (status!=0) return 0;												// In case of status != 0 i.e. error detected, function returns 0

	factorial = static_cast<unsigned int>(factorialDouble);					// Cast "fatorialDouble" as int and returns "fatorial"
	return factorial;
}

/* Calculates the factorial of the unsigned long integer "n". If "n" equals 0
 * the "factorial" function returns 1, otherwise the for loop uses the
 * unsigned long integer "i", which is incremented until it's equal to "n". At
 * every interaction "n" is multiplied by the previous value. When "i" is
 * equal to "n" the "factorial" function returns the unsigned long integer
 * "factorial". PROBLIB_0001_0001/0002_0002
 *
 * Function also checks if the input is negative, exceeds the
 * maximum input value (170), overflows the output value, and if input is
 * an integer. If the input check proves true in any case, the function
 * returns 0 and the "status" value, which informs the problems found.
 * Moreover, function also check the output for overflow and in case of
 * error the function returns 0 and the "status" value, which informs the
 * problems found.
 */
double probability::factorial(double n){
	double factorial = 1;
	if (n == 0) return 1;
	for(int i=1; i<=n; ++i) factorial = factorial * i;

	checkValue check;
	status = check.notNegative(n,status);									// Checks if the input is negative
	status = check.atMaxLimit(n,status);									// Checks is the input exceeds the maximum value (170)
	status = check.isInteger(n,status);										// Checks is the input is an integer
	status = check.overflowedValue(factorial,status);						// Checks is the output overflow the variable limit
	if (status!=0) return 0;												// In case of status != 0 i.e. error detected, function returns 0

	return factorial;														// Cast "fatorialDouble" as int and returns "fatorial"
}

/* Returns "Status" value, informing calculation validity
 */
int probability::checkStatus(){
	return status;
}
