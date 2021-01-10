#define _CRT_SECURE_NO_WARNINGS
#include "subway.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	//구조체 생성 및 파일 입출력을 위한 기본 변수 설정
	struct subway subway[300]; //지하철 역 변호, 역 명을 포함한 구조체
	struct line line[300]; //지하철 출발 역, 도착 역, 역간 거리를 포함한 구조체

	FILE* f; //파일 입출력을 위한 포인터 설정
	char a[50], b[50]; 
	int i = 1;
	
	f = fopen("station_num.txt", "r"); 
	while (i != 243) {
		fscanf(f, "%d %s", &(subway[i].num), a);
		strcpy(subway[i].name, a);
		i++;
	}
	//지하철 역 번호, 역 명을 포함한 txt 파일 입력
	//구조체의 멤버 변수에 문자열을 바로 입력을 받을 때 오류가 생기는 것을 방지하기 위해 strcpy 함수를 사용

	i = 1;
	f = fopen("distance.txt", "r");
	while (i != 273) {
		fscanf(f, "%s %s %d", a, b, &(line[i].num));
		strcpy(line[i].start, a);
		strcpy(line[i].end, b);
		i++;
	}
	//지하철 출발 역, 도착 역, 역간거리를 포함한 txt 파일 입력
	//구조체의 멤버 변수에 문자열을 바로 입력을 받을 때 오류가 생기는 것을 방지하기 위해 strcpy 함수를 사용

	graphtype* g1 = (graphtype*)malloc(sizeof(graphtype));
	creategraph(g1);

	insertDist(g1, line, subway);//노드, 간선, 가중치를 삽입하는 연산

	while (1) {
		int number;
		menu(); //number를 입력받기 위한 기본 순서 출력 연산
		scanf("%d", &number);
		switch (number) {
		case 1:
			for (i = 1; i < 243; i++) printf(" | %5d | %-18s |\n", subway[i].num, subway[i].name);
			break;
			//전체 역의 역 번호, 역명 출력
		case 2:
			for (i = 1; i < 273; i++) printf(" | %-18s | %-18s | %-5d |\n", line[i].start, line[i].end, line[i].num);
			break;
			//전체 역의 출발 역, 도착 역, 역간 거리 출력
		case 3:
			printlist(g1, subway); //연결 역을 출력하는 연산
			break;
		case 4 :
			turnlist(g1, subway); //환승역을 출력하는 연산
			break;
		default :
			return 0;
			break;

		}
	}
	getchar();
	return;
}

