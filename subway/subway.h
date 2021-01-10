#pragma once
//��������Ʈ�� ����

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<limits.h>

#define MAX_VERTEX 500
#define FALSE 0
#define TRUE 1
#define INF 1000

//��������Ʈ�� ����(���) ������ ��Ÿ���� ����ü
typedef struct graphnode {
	int vertex; //������ ��
	struct graphnode* link; //������ ����� ������ �ּҸ� �����ϱ� ���� ������
}graphnode;

//�׷����� ��Ÿ���� ����ü
typedef struct graphtype {
	int n; //������ ����
	int dist[MAX_VERTEX][MAX_VERTEX]; //����ġ�� �����ϱ� ���� ���� ���
	graphnode* head[MAX_VERTEX]; //�� ���� ��带 �����ϱ� ���� �迭
}graphtype;

//����ö �뼱�� �����
//����ö �� ��ȣ, ������ �����ϴ� ����ü
typedef struct subway {
	int num; //�� ��ȣ
	char name[50]; //���� ���ڿ��� �����ϱ� ���� �迭
}subway;

//����ö ��� ��, ���� ��, ���� �Ÿ��� �����ϴ� ����ü
typedef struct line {
	char start[50]; //��� �� ���ڿ��� �����ϱ� ���� �迭
	char end[50]; //���� �� ���ڿ��� �����ϱ� ���� �迭
	int num; //��� ���� ���� �� ������ �Ÿ�
}line;

//-------------------------------------------------

//���� �׷����� �����ϴ� ����
void creategraph(graphtype* g);

//�׷��� g�� ���� v�� �����ϴ� ����
void insertVertex(graphtype* g, int v);

//�׷��� g�� ����(u,v)�� �����ϴ� ����
void insertEdge(graphtype* g, int u, int v);

//�׷��� g�� ����, ���� �Ÿ��� ������ �����ϴ� ����
void insertDist(graphtype* g, line* l, subway* s);

//�׷��� g�� �� ������ ���� ���� ��(��������Ʈ)�� ����ϴ� ����
void printlist(graphtype* g, subway *s);

//ȯ�¿��� ����ϴ� ����
void turnlist(graphtype* g, subway* s);

//����ڰ� ���ϴ� ����� �Է¹ޱ� ���� �⺻ ���� ��� ����
int menu();

