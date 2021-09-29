#pragma once
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

