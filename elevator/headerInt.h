#pragma once

#include<stdio.h>
#include<stdlib.h>

//노드 설정
typedef int element;

typedef struct node { //typedef struct 구조체 이름 마지막에 구조체 별칭
	element data;
	struct node* rlink;
	struct node* llink;
}node;

//front, rear 노드 설정

typedef struct {
	struct node* front;
	struct node* rear;
}nodetype;

//공백 데크 생성
nodetype* Createdeque();

//공백 검사
int isEmpty(nodetype* dq);

//front 앞에 item
void pushF(nodetype* dq, element item);

//rear 뒤에 item
void pushR(nodetype* dq, element item);

//front 삭제 반환
element popF(nodetype* dq);

//rear 삭제 반환
element popR(nodetype* dq);

//front 반환
element peekF(nodetype* dq);

//rear 반환
element peekR(nodetype* dq);

//front부터 rear까지 반환
void printdeque(nodetype* dq);

nodetype* Createdeque() {
	nodetype* dq;
	dq = (nodetype*)malloc(sizeof(nodetype));
	dq->front = NULL;
	dq->rear = NULL;

	return dq;//
}

//공백 검사
int isEmpty(nodetype* dq) {
	if (dq->front == NULL) {
		printf("Empty!");
		return 1;
	}
	else return 0;
}



void pushF(nodetype* dq, element item) {
	node* new = (node*)malloc(sizeof(node));
	new->data = item;
	if (dq->front == NULL) {
		dq->front = new;
		dq->rear = new;
		new->llink = NULL;
		new->rlink = NULL;
	}
	else {
		dq->front->llink = new;
		new->rlink = dq->front;
		new->llink = NULL;
		dq->front = new;
	}
	printf("front 삽입 %c >>", item);
}

//rear 뒤에 item
void pushR(nodetype* dq, element item) {
	node* new = (node*)malloc(sizeof(node));
	new->data = item;
	if (dq->rear == NULL) {
		dq->front = new;
		dq->rear = new;
		new->rlink = NULL;
		new->llink = NULL;
	}
	else {
		dq->rear->rlink = new;
		new->llink = dq->rear;
		new->rlink = NULL;
		dq->rear = new;
	}
	printf("rear  삽입 %c >>", item);
}

//front 삭제 반환
element popF(nodetype* dq) {
	element item;
	node* old = dq->front;
	if (isEmpty(dq)) return 0;
	else {
		item = old->data;
		if (old->rlink == NULL) {//원소가 1개일 때
			dq->front = NULL;
			dq->rear = NULL;
		}
		else {
			dq->front = old->rlink;//
			dq->front->llink = NULL;
		}
		free(old);
		printf("front 삭제 %c >>", item);
		return item;
	}
}

//rear 삭제 반환
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
		printf("rear  삭제 %d >>", item);

		return item;
	}
}

//front 반환
element peekF(nodetype* dq) {
	element item;
	if (isEmpty(dq)) {
		printf("peek Front item : none\n");
		return 0;
	}

	else {
		item = dq->front->data;
		printf("peek Front item : %d\n", item);
		return item;
	}
}

//rear 반환
element peekR(nodetype* dq) {
	element item;
	if (isEmpty(dq)) {
		printf("peek  Rear item : none\n");
		return 0;
	}

	else {
		item = dq->rear->data;
		printf("peek  Rear item : %d\n", item);
		return item;
	}
}

//front부터 rear까지 반환
void printdeque(nodetype* dq) {
	node* temp = dq->front;
	printf("DeQue : [");
	while (temp) {
		printf("%2d", temp->data);
		temp = temp->rlink;
	}
	printf(" ]\n");
}
