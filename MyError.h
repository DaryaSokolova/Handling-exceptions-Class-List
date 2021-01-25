#pragma once
#include <iostream>

using namespace std;

class MyError
{
public:
	virtual void print()
	{
		cerr << "MyError???";
	}
};

class My_Bad_Alloc :public MyError 
{
	void print() override
	{
		cerr << "оепеонкмемхе???";
	}
};

class My_File_Error: public MyError
{
	void print() override
	{
		cerr << "врн_рн я тюикнл???";
	}
};
