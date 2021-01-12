#pragma once

#include<stdio.h>
#include<stdlib.h>

//��� ����
typedef char element;

typedef struct node { //typedef struct ����ü �̸� �������� ����ü ��Ī
	element data;
	struct node* rlink;
	struct node* llink;
}node;

//front, rear ��� ����

typedef struct {
	struct node* front;
	struct node* rear;
}nodetype;

//���� ��ũ ����
nodetype* Createdeque();

//���� �˻�
int isEmpty(nodetype* dq);

//front �տ� item
void pushF(nodetype* dq, element item);

//rear �ڿ� item
void pushR(nodetype* dq, element item);

//front ���� ��ȯ
element popF(nodetype* dq);

//rear ���� ��ȯ
element popR(nodetype* dq);

//front ��ȯ
element peekF(nodetype* dq);

//rear ��ȯ
element peekR(nodetype* dq);

//front���� rear���� ��ȯ
void printdeque(nodetype* dq);

nodetype* Createdeque() {
	nodetype* dq;
	dq = (nodetype*)malloc(sizeof(nodetype));
	dq->front = NULL;
	dq->rear = NULL;

	return dq;//
}

//���� �˻�
int isEmpty(nodetype* dq) {
	if (dq->front == NULL) {
		printf("Empty!");
		return 1;
	}
	else return 0;
}



void pushF(nodetype* dq, element item) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	if (dq->front == NULL) {
		dq->front = newnode;
		dq->rear = newnode;
		newnode->llink = NULL;
		newnode->rlink = NULL;
	}
	else {
		dq->front->llink = newnode;
		newnode->rlink = dq->front;
		newnode->llink = NULL;
		dq->front = newnode;
	}
	printf("front ���� %c >>", item);
}

//rear �ڿ� item
void pushR(nodetype* dq, element item) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	if (dq->rear == NULL) {
		dq->front = newnode;
		dq->rear = newnode;
		newnode->rlink = NULL;
		newnode->llink = NULL;
	}
	else {
		dq->rear->rlink = newnode;
		newnode->llink = dq->rear;
		newnode->rlink = NULL;
		dq->rear = newnode;
	}
	printf("rear  ���� %c >>", item);
}

//front ���� ��ȯ
element popF(nodetype* dq) {
	element item;
	node* old = dq->front;
	if (isEmpty(dq)) return 0;
	else {
		item = old->data;
		if (old->rlink == NULL) {//���Ұ� 1���� ��
			dq->front = NULL;
			dq->rear = NULL;
		}
		else {
			dq->front = old->rlink;//
			dq->front->llink = NULL;
		}
		free(old);
		printf("front ���� %c >>", item);
		return item;
	}
}

//rear ���� ��ȯ
element popR(nodetype* dq) {
	node* old = dq->rear;
	element item;
	if (isEmpty(dq)) return 0;
	else {
		item = old->data;
		if (old->llink == NULL) {
			dq->front = NULL;
			dq->rear = NULL;
		}
		else {
			dq->rear = old->llink;
			dq->rear->rlink = NULL;
		}
		free(old);
		printf("rear  ���� %c >>", item);

		return item;
	}
}

//front ��ȯ
element peekF(nodetype* dq) {
	element item;
	if (isEmpty(dq)) {
		printf("peek Front item : none\n");
		return 0;
	}

	else {
		item = dq->front->data;
		printf("peek Front item : %c\n", item);
		return item;
	}
}

//rear ��ȯ
element peekR(nodetype* dq) {
	element item;
	if (isEmpty(dq)) {
		printf("peek  Rear item : none\n");
		return 0;
	}

	else {
		item = dq->rear->data;
		printf("peek  Rear item : %c\n", item);
		return item;
	}
}

//front���� rear���� ��ȯ
void printdeque(nodetype* dq) {
	node* temp = dq->front;
	printf("DeQue : [");
	while (temp) {
		printf("%2c", temp->data);
		temp = temp->rlink;
	}
	printf(" ]\n");
}
