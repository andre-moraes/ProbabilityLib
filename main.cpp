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

	double n = 3;
	cout << n << endl;

	double m = tst.factorial(n);
	cout << m << " double" << endl;
	int status = tst.checkStatus();
	cout << status << endl << endl;

	int o = 5;
	cout << o << endl;
	unsigned int p = tst.factorial(o);
	cout << p << " int" << endl;
	status = tst.checkStatus();
	cout << status << endl;


	// check the problem reports

	return 0;
}
