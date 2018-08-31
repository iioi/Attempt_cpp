#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct BTNode {
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

// ����������	1	2��3	4��5 6��7
int buildTree(BTNode *&p) {
	BTNode *q, *s;
	q = (BTNode *)malloc(sizeof(BTNode));
	q->data = 1;
	q->lchild = q->rchild = NULL;
	s = (BTNode *)malloc(sizeof(BTNode));
	s->data = 2;
	q->lchild = s;
	s = (BTNode *)malloc(sizeof(BTNode));
	s->lchild = s->rchild = NULL;
	s->data = 3;
	q->rchild = s;

	p = q;

	q = q->lchild;
	s = (BTNode *)malloc(sizeof(BTNode));
	s->lchild = s->rchild = NULL;
	s->data = 4;
	q->lchild = s;
	s = (BTNode *)malloc(sizeof(BTNode));
	s->lchild = s->rchild = NULL;
	s->data = 5;
	q->rchild = s;

	q = p->rchild;

	s = (BTNode *)malloc(sizeof(BTNode));
	s->lchild = s->rchild = NULL;
	s->data = 6;
	q->lchild = s;
	s = (BTNode *)malloc(sizeof(BTNode));
	s->lchild = s->rchild = NULL;
	s->data = 7;
	q->rchild = s;

	return 1;
}

int preArr[7];
int preArrN = 0;

void preOrder(BTNode *p) {
	if (p == NULL)
		return;
	cout << p->data << " ";
	preArr[preArrN++] = p->data;
	preOrder(p->lchild);
	preOrder(p->rchild);
}

int inArr[7];
int inArrN;

void inOrder(BTNode *p) {
	if (p == NULL)
		return;
	inOrder(p->lchild);
	cout << p->data << " ";
	inArr[inArrN++] = p->data;
	inOrder(p->rchild);
}

void postOrder(BTNode *p) {
	if (p == NULL)
		return;
	postOrder(p->lchild);
	postOrder(p->rchild);
	cout << p->data << " ";
}

/*ͨ��ǰ�������������������鹹��������*/
BTNode * createBT(int *pre, int preL, int preR, int *in, int inL, int inR) {
	// ǰ��������м�Ľ�㣨���ڵ㣩��������ǰ�棬��������м�Ľ����������м�
	// ����������������ҵ�����㣬���ð�����һ��Ϊ��
	if (preL > preR)
		return NULL;
	BTNode *p = (BTNode *)malloc(sizeof(BTNode));
	p->data = pre[preL];
	int i;
	for (i = inL; i <= inR; i++) {
		if (in[i] == pre[preL])
			break;
	}
	// ����i-1����ʵ���ü�һ���Ǵ�0��ʼ���ģ�Ӧ�ô����������ڵ������
	// ���ǣ�i�Ǹ�������������������±�
	// inR - i�����������������
	// i - inL�����������������
	// ����������
	p->lchild = createBT(pre, preL + 1, preR - inR + i, in, inL, i - 1);
	// ����������
	p->rchild = createBT(pre, preL + 1 + i - inL, preR, in, i + 1, inR);

	return p;
}

int main5() {
	BTNode *bt;
	buildTree(bt);
	preOrder(bt);
	cout << endl;
	inOrder(bt);
	cout << endl;
	postOrder(bt);

	cout << endl;
	BTNode *p = createBT(preArr, 0, 6, inArr, 0, 6);
	postOrder(p);

	getchar();
	return 0;
}