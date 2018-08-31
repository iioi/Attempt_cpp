#define _CRT_SECURE_NO_WARNINGS

#include<iostream>

using namespace std;

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct  LNode *next;
}LNode, *LinkList;

// ͷ�巨����������
// �ӱ�β����ͷ������������L��ÿ�ξ���ͷ���֮�����Ԫ��
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

// β�巨����������
// �ӱ�ͷ����β������������L��ÿ�ξ��ڱ�β����Ԫ��
LinkList CreateList2(LinkList &L) {
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L;		// rΪ��βָ��
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

// ����Ų��ҽ��ֵ
// ���㷨ȡ��������L����ͷ��㣩�е�i��λ�õĽ��ָ��
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

// ��ֵ���ұ���
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