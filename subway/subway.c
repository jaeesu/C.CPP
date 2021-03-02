//��������Ʈ�� ����
#include "subway.h"
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//���� �׷����� �����ϴ� ����
void creategraph(graphtype* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTEX; i++) {
		g->head[i] = NULL;

		int j = 1;

		while (j != 243) {
			g->dist[i][j] = INF;
			j++;
		} //���� �Ÿ�(����ġ)�� ��Ÿ���� ���� ��� �ʱ�ȭ
	}
}

//�׷��� g�� ���� v�� �����ϴ� ����
void insertVertex(graphtype* g, int v) {
	if ((g->n) > MAX_VERTEX) {
		printf("max!");
		return;
	}
	g->n++;
}

//�׷��� g�� ����(u,v)�� �����ϴ� ����
void insertEdge(graphtype* g, int u, int v) {
	graphnode* node;
	if (u > g->n || v > g->n) {
		printf("no");
		return;
	}
	node = (graphnode*)malloc(sizeof(graphnode));
	node->vertex = v;
	node->link = g->head[u];//���� ������ ���� ��带 ����Ʈ�� ù ��° ���� ����
	g->head[u] = node;
}

//�׷��� g�� ����, ���� �Ÿ��� ������ �����ϴ� ����
void insertDist(graphtype* g, line* l, subway* s) {
	int x, y, i, j = 1;

	for (i = 1; i < 243; i++) insertVertex(g, s[i].num); //�׷��� g�� ���� ����

	for (i = 272; i >= 1; i--) {
		j = 1;
		int ret1, ret2;
		while (j != 273) {
			ret1 = strcmp(l[i].start, s[j].name);
			ret2 = strcmp(l[i].end, s[j].name);

			if (ret1 == 0) x = j;
			if (ret2 == 0) y = j;

			//����ö �뼱�� ��� ���� ���� ���� ���� �� ��ȣ�� ����ü�� �����ϱ� ���� strcmp �Լ��� ���ڿ� ��

			j++;
		}

		insertEdge(g, x, y);
		insertEdge(g, y, x);
		//��� ���� ���� ���� �� ��ȣ�� �������� ���� ���� ����

		g->dist[x][y] = l[i].num;
		g->dist[y][x] = l[i].num;
		//��� ���� ���� ���� ��Ÿ���� �� ���� ���̿� ���� �Ÿ�(����ġ) �Է�
	}
}


//�׷��� g�� �� ������ ���� ���� ��(��������Ʈ)�� ����ϴ� ����
void printlist(graphtype* g, subway* s) {
	for (int i = 1; i < 243; i++) {
		graphnode* p;
		printf("\n\n%-18s�� ���� ����Ʈ  :", s[i].name);
		p = g->head[i];
		while (p) {
			printf("%-18s | ", s[p->vertex].name);
			p = p->link;
		}
	}
}

//�׷��� g�� �� ������ ���� ���� ������ 3�� �̻��� ������ ����ϴ� ����
//����� ������ 3�� �̻��� ������ ����ö ������ ġ�� ȯ�¿� -> ȯ�¿��� ����ϴ� ����
void turnlist(graphtype* g, subway* s) {
	for (int i = 1; i < 243; i++) {
		graphnode* p;
		p = g->head[i];
		int count = 0;
		while (p) {
			count++;
			p = p->link;
			//p�� ����� ������ ���� �� ���� p�� ����� �������� �Ű� ����, count�� 1�� ������Ų��.
		}
		if (count >= 3) printf("| %-10s |\n", s[i].name);
	}
}

//����ڰ� ���ϴ� ����� �Է¹ޱ� ���� �⺻ ���� ��� ����
int menu() {
	printf("\n\n-----------------------------------\n");
	printf("1. ��ü �� ��ȣ ���\n");
	printf("2. ��ü �뼱 �� �Ÿ� ���\n");
	printf("3. ��ü ���� ���� �� ���\n");
	printf("4. ȯ�¿� ���\n");
	printf("-----------------------------------\n");
}

///

