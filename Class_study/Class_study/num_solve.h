#pragma once
class num_solve
{
public:
	num_solve(double,double); 
	//类的构造函数是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。
	//构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。
	//构造函数可用于为某些成员变量设置初始值。
	~num_solve(); 
	//类的析构函数是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。
	//析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，
	//它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。
	double add(void);
	double sub(void);
	double mult(void);
	double div(void);
private:
	double num1, num2;
};

