/*
 *  probability.cpp
 *
 *  Created on: May 28, 2018
 *  Version:	1.001
 *  Author:     Andre Moraes
 */

#include "checkValue.h"
#include <math.h>

/* Checks if unsigned int n value is greater than zero. If not updates the "status"
 * value ORing "status" with "enum validateNumber (@checkValue.h) = negative_number"
 */
int checkValue::notNegative(unsigned int n, int status){
	if (n < 0) 										status = status | negative_number;
	return status;
}

/* Checks if double n value is greater than zero. If not updates the "status"
 * value ORing "status" with "enum validateNumber (@checkValue.h) = negative_number"
 */
int checkValue::notNegative(double n, int status){
	if (n < 0) 										status = status | negative_number;
	return status;
}

/* Checks if unsigned int n value is less or equal the max limit (12). If not updates
 * the "status" value ORing "status" with "enum validateNumber (@checkValue.h) =
 * overMaxLimit_number"
 */
int checkValue::atMaxLimit(unsigned int n, int status){
	if (n > 12) 									status = status | overMaxLimit_number;
	return status;
}

/* Checks if double n value is less or equal the max limit (170). If not updates
 * the "status" value ORing "status" with "enum validateNumber (@checkValue.h) =
 * overMaxLimit_number"
 */
int checkValue::atMaxLimit(double n, int status){
	if (n > 170) 									status = status | overMaxLimit_number;
	return status;
}

/* If "isInt" equals 1 checks is the double "factorial" exceeds the maximum
 * output value allowed for unsigned int (4.294.967.295). In case the output
 * exceeds this value "status" value is updated to indicate an error. If "isInt"
 * equals 0 (default value) checks if the double "factorial" exceeds the maximum
 * output value allowed for double variables (inf). In case the output indicates
 * inf function updates the "status" value ORing "status" with "enum validateNumber
 * (@checkValue.h) = overflow"
 */
int checkValue::overflowedValue(double factorial, int status, bool isInt){
	if (isInt == true && factorial > 4294967295) 	status = status | overflow;
	if (isinf(factorial)) 							status = status | overflow;
	return status;
}

/* Check if input number is an integer by checking if there is any decimal value using
 * function modf@math.h. If not updates the "status" value ORing "status" with "enum
 * validateNumber (@checkValue.h) = not_integer"
 */
int checkValue::isInteger(double n, int status){
	  double intpart;
	  if (modf (n , &intpart)) 						status = status | not_integer;
	  return status;
}
