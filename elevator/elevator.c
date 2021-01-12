#include "elevator.h"

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
