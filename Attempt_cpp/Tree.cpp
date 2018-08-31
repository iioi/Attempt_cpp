#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct BTNode {
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BTNode;

// 创建二叉树	1	2、3	4、5 6、7
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

/*通过前序遍历和中序遍历的数组构建二叉树*/
BTNode * createBT(int *pre, int preL, int preR, int *in, int inL, int inR) {
	// 前序遍历第中间的结点（父节点）再数组最前面，中序遍历中间的结点在数组的中间
	// 在中序遍历数组中找到父结点，正好把数组一分为二
	if (preL > preR)
		return NULL;
	BTNode *p = (BTNode *)malloc(sizeof(BTNode));
	p->data = pre[preL];
	int i;
	for (i = inL; i <= inR; i++) {
		if (in[i] == pre[preL])
			break;
	}
	// 这里i-1（其实不用减一，是从0开始数的）应该代表左子树节点的数量
	// 不是，i是父结点在中序遍历数组的下标
	// inR - i代表右子树结点数量
	// i - inL代表左子树结点数量
	// 构建左子树
	p->lchild = createBT(pre, preL + 1, preR - inR + i, in, inL, i - 1);
	// 构建右子树
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