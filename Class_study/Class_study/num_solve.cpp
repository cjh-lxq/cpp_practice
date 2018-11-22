#include "pch.h"
#include "num_solve.h"
#include <iostream>
using namespace std;

num_solve::num_solve(double a,double b)
{
	num1 = a;
	num2 = b;
	cout << "a new num_solve is find" << endl;
}

num_solve::~num_solve()
{
	cout << "a num_solve class is deleted!" << endl;
}

double num_solve::add()
{
	return num1 + num2;
}
double num_solve::mult()
{
	return num1 * num2;
}
double num_solve::div()
{
	if (num2 == 0.0)
	{
		return 0.0;
	}
	return num1 / num2;
}
double num_solve::sub()
{
	return num1 - num2;
}