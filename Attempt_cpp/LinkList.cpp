#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct  LNode *next;
}LNode, *LinkList;

// 头插法建立单链表
// 从表尾到表头逆向建立单链表L，每次均在头结点之后插入元素
LinkList CreateList1(LinkList &L) {
	LNode *s; int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

// 尾插法建立单链表
// 从表头到表尾正向建立单链表L，每次均在表尾插入元素
LinkList CreateList2(LinkList &L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;		// r为表尾指针
	scanf("%d", &x);
	while (x != 9999)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

// 按序号查找结点值
// 本算法取出单链表L（带头结点）中第i个位置的结点指针
LNode *GetElem11(LinkList L, int i) {
	if (i < 1)
		return NULL;
	LNode *s = L->next;
	for (int j = 1; j < i&&s; j++) {
		s = s->next;
	}
	return s;
}
LNode *GetElem(LinkList L, int i) {
	int j = 1;
	LNode *p = L->next;
	if (i == 0)
		return L;
	if (i < 1)
		return NULL;
	while (p&&j < i) {
		p = p->next;
		j++;
	}
	return p;
}

// 按值查找表结点
LNode *LocateElem(LinkList L, ElemType e) {
	LNode *p = L->next;
	while (p&&p->data != e)
		p = p->next;
	return p;
}

int main4() {
	LinkList L;
	CreateList2(L);
	LNode *s = GetElem(L, 3);
	cout << s->data << endl;
	getchar();
	return 0;
}