// 大数阶乘.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <assert.h>
#include <vector>
using std::cout;
using std::endl;
// each element < 10000
// LSB first, ie. little endian
typedef std::vector<int> BigInt;

BigInt* factorial(int n)
{
	// 9999 * 9999 < 10000 * 10000 = 100000000 < 1073741824  = 2 ** 30
	BigInt* result = new BigInt;
	result->push_back(1);
	for (int factor = 1; factor <= n; ++factor) {
		int carry = 0;
		for (auto& item : *result) {
			int product = item * factor + carry;
			item = product % 10000;
			carry = product / 10000;
		}
		if (carry > 0) {
			result->push_back(carry);
		}
	}
	return result;
}

void printBigInt(const BigInt& number)
{
	if (number.empty())
	{
		printf("0\n");  // compiles to puts()
	}
	else
	{
		printf("%d", number.back());
		for (auto it = number.rbegin() + 1; it != number.rend(); ++it)
			printf("%04d", *it);
		printf("\n");
	}
}

int main()
{
	/*
	for (int i = 0; i <= 10000; ++i)
	{
	  BigInt result = factorial(i);
	  printf("%d: ", i);
	  printBigInt(result);
	}
	*/
	BigInt* result = factorial(10000);
	// 结果为什么是负的？？？？
	printBigInt(*result);
	delete result;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
