#include<iostream>
using namespace std;

#define MaxSize 50
typedef int ElemType;
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;

#define InitSize 100
typedef struct {
	ElemType *data;		// 指示动态分配数组的指针
	int MaSize, length;
}SeqList;

SeqList createSeq() {
	SeqList L;
	L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
	L.MaSize = InitSize;
	L.length = 0;
	return L;
}

SqList createSqList() {
	SqList L;
	L.length = 0;
	return L;
}

// 本算法实现将元素e插入到顺序表L中第i个位置
bool ListInsert(SqList &L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e;
	L.length++;
	return true;
}

// 本算法实现删除顺序表L中第i个位置的元素
bool ListDelete(SqList &L, int i, ElemType &e) {
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;
}

// 本算法实现查找顺序表中值为e的元素，如果查找成功，返回元素位序，否则返回0
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

int main3() {
	SqList L = createSqList();
	ListInsert(L, 1, 11);
	ListInsert(L, 2, 22);
	ListInsert(L, 2, 222);
	int e = 22;
	int loc = LocateElem(L, e);
	cout << loc << endl;
	getchar();
	return 0;
}