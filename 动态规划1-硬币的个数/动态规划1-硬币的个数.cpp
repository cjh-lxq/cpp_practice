// 动态规划1-硬币的个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 2018-12-13
// 如果我们有面值为1元、3元和5元的硬币若干枚，如何用最少的硬币凑够11元？
// http://www.hawstein.com/posts/dp-novice-to-advanced.html
#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int find_coin(int money)
{
	// 状态转移方程：
	// d(i)=min(d(1-vj)+1) 其中i-vj>=0,vj表示第j个硬币的值
	vector<int> min_vec = { 0 };
	vector<int> coin = { 1,3,5 };
	vector<int> min_now;
	for (int i = 1; i <= money; i++)
	{
		min_now.clear();
		for (auto it_coin = coin.begin(); it_coin != coin.end() && *it_coin <= i; it_coin++)
		{
			min_now.push_back(min_vec[i - *it_coin] + 1);
		}
		auto min_iter = min_element(min_now.begin(), min_now.end());
		min_vec.push_back(*min_iter);
	}
	return min_vec[money];
}
int main()
{
	for (int i = 0; i <= 20; i++)
	{
		cout << "拼凑" << i << "元最少需要" << find_coin(i) << "枚硬币" << endl;
	}
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
