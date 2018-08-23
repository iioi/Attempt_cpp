#include<iostream>
#include<stdlib.h>
using namespace std;

const int DefaultSize = 30;

template<class Type>
class Array {
	Type *elements;
	int ArraySize;
	void getArray();
public:
	Array(int size = DefaultSize);
	Array(const Array<Type>&x);
	~Array() { delete[]elements; }
};