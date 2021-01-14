#pragma once

#include<iostream>
#include<stdlib.h>
using namespace std;
#include "new_header.h"

//노드 설정

deq::deq() {
	this->front = NULL;
	this->rear = NULL;
}

//공백 검사
int deq::isEmpty() {
	if (this->front == NULL) {
		cout << "empty";
		return 1;
	}
	return 0;
}


void deq::pushF(element item) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	if (this->front == NULL) {
		this->front = newnode;
		this->rear = newnode;
		newnode->llink = NULL;
		newnode->rlink = NULL;
	}
	else {
		this->front->llink = newnode;
		newnode->rlink = this->front;
		newnode->llink = NULL;
		this->front = newnode;
	}
	cout << "front 삽입 %c >>"+item;
}

//rear 뒤에 item
void deq::pushR(element item) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = item;
	if (this->rear == NULL) {
		this->front = newnode;
		this->rear = newnode;
		newnode->rlink = NULL;
		newnode->llink = NULL;
	}
	else {
		this->rear->rlink = newnode;
		newnode->llink = this->rear;
		newnode->rlink = NULL;
		this->rear = newnode;
	}
	cout << "rear  삽입 %c >>"+item;
}

//front 삭제 반환
element deq::popF() {
	element item;
	node* old = this->front;
	if (this->isEmpty()) return 0;
	else {
		item = old->data;
		if (old->rlink == NULL) {//원소가 1개일 때
			this->front = NULL;
			this->rear = NULL;
		}
		else {
			this->front = old->rlink;//
			this->front->llink = NULL;
		}
		free(old);
		cout << "front 삭제 %c >>"+item;
		return item;
	}
}

//rear 삭제 반환
element deq::popR() {
	node* old = this->rear;
	element item;
	if (this->isEmpty()) return 0;
	else {
		item = old->data;
		if (old->llink == NULL) {
			this->front = NULL;
			this->rear = NULL;
		}
		else {
			this->rear = old->llink;
			this->rear->rlink = NULL;
		}
		free(old);
		cout << "rear  삭제 %d >>"+item;

		return item;
	}
}

//front 반환
element deq::peekF() {
	element item;
	if (this->isEmpty()) {
		cout << "peek Front item : none\n";
		return 0;
	}

	else {
		item = this->front->data;
		cout << "peek Front item : %d\n"+item;
		return item;
	}
}

//rear 반환
element deq::peekR() {
	element item;
	if (this->isEmpty()) {
		cout << "peek  Rear item : none\n";
		return 0;
	}

	else {
		item = this->rear->data;
		cout << "peek  Rear item : %d\n"+item;
		return item;
	}
}

//front부터 rear까지 반환
void deq::printdeque() {
	node* temp = this->front;
	printf("DeQue : [");
	while (temp) {
		printf("%2d", temp->data);
		temp = temp->rlink;
	}
	cout << " ]\n";
}