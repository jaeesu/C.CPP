#define _CRT_SECURE_NO_WARNINGS
#include "header.h"


//1.�� ������ �ö󰬴ٰ� ������ �Է��ϸ� ��������, �Է¹����� �ö󰡴� �Լ�, �Է¹����� �������� �Լ�

//�ö󰡴� �Լ�
//floor ���� ��??
//������ ��ư�� ������ �Ͱ� �ȿ��� ���� ������ ��





/*
//���� �Է��ϰ� ���� �� ���� ��ǥ�� ������ �ö󰡴� �Լ�, ������ �������� �Լ� ����

//�ö󰡴� �Լ�

void Upfloor(nodetype* dq, int floor);


//�������� �Լ�

void Downfloor(nodetype* dq, int floor);


//�� �Է¹ް� ���������� ����

void Infloor(nodetype* dq);


//�ö󰡴� �߿� �� ū �� ������ front, �� ������ rear

void Inupfloor(nodetype* dq, int tofloor);


//�������� �߿� �� ���� �� ������ front, �� ū �� rear

void Indownfloor(nodetype* dq, int tofloor);

//���ϴ� ���� �������� ��

void stopfloor(nodetype* dq , int floor);

//���� ��

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
	//���� ���� ������ ��....
}*/
