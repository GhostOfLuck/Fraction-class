#include "Exception.h"
#include <iostream>
#include "pch.h"
#include <string>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
#include <string>
using namespace std;

class MyException {
private:
	string msg;
public:
	MyException(const string& str) : msg(str) {}
	~MyException() {}
	string getMessage() const { return(msg); }
};

