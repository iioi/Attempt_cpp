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
	ElemType *data;		// ָʾ��̬���������ָ��
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

// ���㷨ʵ�ֽ�Ԫ��e���뵽˳���L�е�i��λ��
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

// ���㷨ʵ��ɾ��˳���L�е�i��λ�õ�Ԫ��
bool ListDelete(SqList &L, int i, ElemType &e) {
	if (i<1 || i>L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j++)
		L.data[j-1] = L.data[j];
	L.length--;
	return true;
}

// ���㷨ʵ�ֲ���˳�����ֵΪe��Ԫ�أ�������ҳɹ�������Ԫ��λ�򣬷��򷵻�0
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