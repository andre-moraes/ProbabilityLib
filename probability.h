/*
 *  probability.h
 *
 *  Created on: May 5, 2018
 *  Version:	1.001
 *  Author:     Andre Moraes
 */

#ifndef PROBABILITY_H_
#define PROBABILITY_H_

class probability {

	public:
		unsigned int factorial(unsigned int n); // Receive and return an unsigned int. Max valid input should be 12. Output value should be from 0 to 4.294.967.295
		double factorial(double m); 			// Receive and return an double. Max valid input should be 170. Output value should be from 0 to 1.7e+308 (~15 digits)
		int checkStatus();						// Checks the calculation validity

	private:
		int status = 0;							// "status" contain the result of input value validation as defined at enum validateNumber
};

#endif /* PROBABILITY_H_ */
