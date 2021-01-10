#pragma once
//인접리스트로 구현

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<limits.h>

#define MAX_VERTEX 500
#define FALSE 0
#define TRUE 1
#define INF 1000

//인접리스트의 정점(노드) 구조를 나타내는 구조체
typedef struct graphnode {
	int vertex; //정점의 값
	struct graphnode* link; //정점과 연결된 정점의 주소를 저장하기 위한 포인터
}graphnode;

//그래프를 나타내는 구조체
typedef struct graphtype {
	int n; //정점의 개수
	int dist[MAX_VERTEX][MAX_VERTEX]; //가중치를 저장하기 위한 인접 행렬
	graphnode* head[MAX_VERTEX]; //각 정점 헤드를 저장하기 위한 배열
}graphtype;

//지하철 노선도 만들기
//지하철 역 번호, 역명을 포함하는 구조체
typedef struct subway {
	int num; //역 번호
	char name[50]; //역명 문자열을 저장하기 위한 배열
}subway;

//지하철 출발 역, 도착 역, 역간 거리를 포함하는 구조체
typedef struct line {
	char start[50]; //출발 역 문자열을 저장하기 위한 배열
	char end[50]; //도착 역 문자열을 저장하기 위한 배열
	int num; //출발 역과 도착 역 사이의 거리
}line;

//-------------------------------------------------

//공백 그래프를 생성하는 연산
void creategraph(graphtype* g);

//그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphtype* g, int v);

//그래프 g에 간선(u,v)를 삽입하는 연산
void insertEdge(graphtype* g, int u, int v);

//그래프 g에 정점, 역간 거리와 간선을 삽입하는 연산
void insertDist(graphtype* g, line* l, subway* s);

//그래프 g의 각 정점에 대한 연결 역(인접리스트)를 출력하는 연산
void printlist(graphtype* g, subway *s);

//환승역을 출력하는 연산
void turnlist(graphtype* g, subway* s);

//사용자가 원하는 명령을 입력받기 위한 기본 순서 출력 연산
int menu();

