/*
 *  main.cpp
 *
 *  Created on: May 5, 2018
 *  Version:	1.001
 *  Author:     Andre Moraes
 */

#include <iostream>
#include <bitset>
#include "probability.h"

using namespace std;

int main(){

	probability tst;

	/*double n = 170;
	double m = tst.factorial(n);
	cout << m << " double" << endl;
	int status = tst.checkStatus();
	cout << status << endl;*/

	unsigned int o = 6;
	int q = static_cast<int>(o);
	cout << o << endl;
	cout << q << endl;

	unsigned int p = tst.factorial(o);
	cout << p << " int" << endl;
	int status = tst.checkStatus();
	cout << status << endl;

	   bitset<32> x(o);
	   cout << "Binary of input: " << o << " -> " << x << endl;

	// check the problem reports

	return 0;
}

/* Problem reports
 *
 * 001 If unsigned int o is negative the program compiles and return factorial 0 and status 6,
 * i.e. overMaxLimit_number and overflow. Since the 2's complement is used to compose negative
 * numbers, compiler will understand the binary sequence as a positive number, e.g. -6 will be
 * understood as 4294967290, since the 32 bits binary representation of -2 in  2's complement
 * will be 11111111111111111111111111111010. The negative input read as unsigned integer will
 * always represent a number equal or higher than 2.147.483.648, therefore the "factorial"
 * calculation will always indicate an overflow error and return 0 as calculation result. -->
 *
 *
 * 002 If unsigned int o is not an integer the program compiles and return factorial as is the
 * input was an integer, i.e. disregards the decimal values. Status = 0
 */
