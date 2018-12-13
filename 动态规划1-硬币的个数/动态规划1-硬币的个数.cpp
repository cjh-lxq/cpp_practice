// 动态规划1-硬币的个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-13
// 如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find_coin(int money)
{
	vector<int> min_vec = { 0 };
	vector<int> coin = { 1,3,5 };
	int d_now = 0;
	for (int i = 1; i <= money; i++)
	{
		for (int j = 0; j < coin.size(); j++)
		{
			if (coin[j] <= i && min_vec[i - coin[j]] + 1 < min_vec[i])
				min_vec[i] = min_vec[i - coin[j]] + 1;
		}
	}
}
int main()
{
    std::cout << "Hello World!\n"; 
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
