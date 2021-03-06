// find_file_practice.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include <io.h>
#include <string>
#include <vector>
using namespace std;

void getFiles(string path, vector<string>& files,bool recursive,string find_type)
{
	//文件句柄  
	long   hFile = 0;
	string file_name;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0 && recursive)
					getFiles(p.assign(path).append("\\").append(fileinfo.name), files,recursive,find_type);
			}
			else
			{
				file_name = fileinfo.name;
				if (file_name.find(find_type)!=string::npos)
					files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
int main()
{
	string path = "D:\\Downloads\\Compressed\\89268708OpenCV3编程入门+代码\\img";
	vector<string> files;
	getFiles(path, files,false,".jpg");
	for (int i=0,size1=files.size();i<size1;i++)
	{
		cout << files[i] << endl;
	}
	//cout << "Hello World! " << path << endl;
}