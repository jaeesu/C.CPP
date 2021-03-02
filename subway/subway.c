//인접리스트로 구현
#include "subway.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//공백 그래프를 생성하는 연산
void creategraph(graphtype* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTEX; i++) {
		g->head[i] = NULL;

		int j = 1;

		while (j != 243) {
			g->dist[i][j] = INF;
			j++;
		} //역간 거리(가중치)를 나타내는 인접 행렬 초기화
	}
}

//그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphtype* g, int v) {
	if ((g->n) > MAX_VERTEX) {
		printf("max!");
		return;
	}
	g->n++;
}

//그래프 g에 간선(u,v)를 삽입하는 연산
void insertEdge(graphtype* g, int u, int v) {
	graphnode* node;
	if (u > g->n || v > g->n) {
		printf("no");
		return;
	}
	node = (graphnode*)malloc(sizeof(graphnode));
	node->vertex = v;
	node->link = g->head[u];//삽입 간선에 대한 노드를 리스트의 첫 번째 노드로 연결
	g->head[u] = node;
}

//그래프 g에 정점, 역간 거리와 간선을 삽입하는 연산
void insertDist(graphtype* g, line* l, subway* s) {
	int x, y, i, j = 1;

	for (i = 1; i < 243; i++) insertVertex(g, s[i].num); //그래프 g에 정점 삽입

	for (i = 272; i >= 1; i--) {
		j = 1;
		int ret1, ret2;
		while (j != 273) {
			ret1 = strcmp(l[i].start, s[j].name);
			ret2 = strcmp(l[i].end, s[j].name);

			if (ret1 == 0) x = j;
			if (ret2 == 0) y = j;

			//지하철 노선의 출발 역과 도착 역을 각각 역 번호로 구조체에 저장하기 위해 strcmp 함수로 문자열 비교

			j++;
		}

		insertEdge(g, x, y);
		insertEdge(g, y, x);
		//출발 역과 도착 역의 역 번호를 정점으로 보고 간선 삽입

		g->dist[x][y] = l[i].num;
		g->dist[y][x] = l[i].num;
		//출발 역과 도착 역을 나타내는 두 정점 사이에 역간 거리(가중치) 입력
	}
}


//그래프 g의 각 정점에 대한 연결 역(인접리스트)를 출력하는 연산
void printlist(graphtype* g, subway* s) {
	for (int i = 1; i < 243; i++) {
		graphnode* p;
		printf("\n\n%-18s의 인접 리스트  :", s[i].name);
		p = g->head[i];
		while (p) {
			printf("%-18s | ", s[p->vertex].name);
			p = p->link;
		}
	}
}

//그래프 g의 각 정점에 대한 연결 정점이 3개 이상인 정점을 출력하는 연산
//연결된 정점이 3개 이상인 정점은 지하철 역으로 치면 환승역 -> 환승역을 출력하는 연산
void turnlist(graphtype* g, subway* s) {
	for (int i = 1; i < 243; i++) {
		graphnode* p;
		p = g->head[i];
		int count = 0;
		while (p) {
			count++;
			p = p->link;
			//p에 연결된 정점이 없을 때 까지 p는 연결된 정점으로 옮겨 가며, count를 1씩 증가시킨다.
		}
		if (count >= 3) printf("| %-10s |\n", s[i].name);
	}
}

//사용자가 원하는 명령을 입력받기 위한 기본 순서 출력 연산
int menu() {
	printf("\n\n-----------------------------------\n");
	printf("1. 전체 역 번호 출력\n");
	printf("2. 전체 노선 간 거리 출력\n");
	printf("3. 전체 역의 연결 역 출력\n");
	printf("4. 환승역 출력\n");
	printf("-----------------------------------\n");
}

///

