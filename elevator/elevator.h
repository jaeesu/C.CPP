#define _CRT_SECURE_NO_WARNINGS
#include "headerInt.h"


//1.�� ������ �ö󰬴ٰ� ������ �Է��ϸ� ��������, �Է¹����� �ö󰡴� �Լ�, �Է¹����� �������� �Լ�

//�ö󰡴� �Լ�
//floor ���� ��??
//������ ��ư�� ������ �Ͱ� �ȿ��� ���� ������ ��

//������ ���� ��ư ������ �ö󰡴� �Լ�

void button(nodetype* dq,int, int);

void Downfloor(int*, int);

void Upfloor(int*, int);

void Number(nodetype* dq, int, int);

void button(nodetype* dq, int floor, int to) {
	pushF(dq, to);
	printdeque(dq);
	if (floor < to) Downfloor(floor, to);
	else Upfloor(floor, to);
}

void Downfloor(int* floor, int to) {
	for (int i = floor; i <= to; i++) {
		floor++;
	}
	printf("end to %d", to);
}

void Upfloor(int* floor, int to) {
	for (int i = floor; i >= to; i--) {
		floor--;
	}
	printf("end to %d", to);
}

void Number(nodetype* dq, int floor, int to) {
	pushF(dq, to);
	if (floor < to) Downfloor(floor, to);
	else Upfloor(floor, to);
}





//�������� ���������� ���� ifelse, button �� �Էµ��ڸ��� ��ũ�� �ְ� ����