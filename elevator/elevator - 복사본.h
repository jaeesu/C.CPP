#define _CRT_SECURE_NO_WARNINGS
#include "header.h"


//1.층 누르면 올라갔다가 목적지 입력하면 내려오기, 입력받으면 올라가는 함수, 입력받으면 내려오는 함수

//올라가는 함수
//floor 현재 층??
//위에서 버튼을 누르는 것과 안에서 층을 누르는 것





/*
//층을 입력하고 현재 층 보다 목표가 높으면 올라가는 함수, 낮으면 내려가는 함수 실행

//올라가는 함수

void Upfloor(nodetype* dq, int floor);


//내려가는 함수

void Downfloor(nodetype* dq, int floor);


//층 입력받고 엘리베이터 운행

void Infloor(nodetype* dq);


//올라가는 중에 더 큰 층 눌리면 front, 더 작은층 rear

void Inupfloor(nodetype* dq, int tofloor);


//내려가는 중에 더 작은 층 눌리면 front, 더 큰 층 rear

void Indownfloor(nodetype* dq, int tofloor);

//원하는 층에 도착했을 때

void stopfloor(nodetype* dq , int floor);

//현재 층

//tofloor  peekF



//--------------------------------
void Upfloor(nodetype* dq, int floor) {
	int to = peekF(dq);
	for (int i = floor; i <= to; i++) {

	}
}

void Downfloor(nodetype* dq, int floor) {
	int to = peekF(dq);
	for (int i = floor; i >= to; i--) {

	}
}

void Infloor(nodetype* dq) {
	int floor;
	scanf("%d", &floor);
	int tofloor;
	scanf("%d", &tofloor);

	if (tofloor > floor) {
		Upfloor(dq,);
	}


	Upfloor(dq, floor);
	Downfloor(dq, floor);
}

void Inupfloor(nodetype* dq, int tofloor) {
	if (tofloor > peekF(dq)) {
		pushF(dq, tofloor);
	}
	else {
		pushR(dq, tofloor);
	}
}

void Indownfloor(nodetype* dq, int tofloor) {
	if (tofloor < peekF(dq)) {
		pushF(dq, tofloor);
	}
	else {
		pushR(dq, tofloor);
	}
}

void stopfloor(nodetype* dq, int floor){
	//현재 층은 마지막 층....
}*/
