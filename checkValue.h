/*
 * checkValue.h
 *
 *  Created on: May 28, 2018
 *  Version:	1.001
 *  Author:     Andre Moraes
 */

#ifndef CHECKVALUE_H_
#define CHECKVALUE_H_

class checkValue {
	public:
	/* Check if the input number is not negative and return updated status (int)
	 */
	int notNegative(int n, int status);
	int notNegative(double n, int status);

	/* Check if the input number is on the right max limit and return updated status (int)
	 */
	int atMaxLimit(int n, int status);
	int atMaxLimit(double n, int status);

	/* Check if the output value is overflowed and return updated status (int)
	 */
	int overflowedValue(double factorial, int status, bool isInt = false);

	/* Check if input number is an integer and return updated status (int)
	 */
	int isInteger(double n, int status);

	private:
		/* enum validateNumber list the possible input status. (1) "valid" indicates the
		 * input value is OK; (2) "negative_number" indicates that the input value is
		 * negative; (3) "overflow_number" indicates that the input value will overflow
		 * the calculation; (4) "overflow" indicates that the output value exceeds the
		 * maximum value allowed for the output variable
		 */
		enum validateNumber {
			valid				= 0, 		// 0000 0000
			negative_number		= 1, 		// 0000 0001
			overMaxLimit_number = 2, 		// 0000 0010
			overflow			= 4, 		// 0000 0100
			not_integer			= 8 		// 0000 1000
		};
};

#endif /* CHECKVALUE_H_ */
