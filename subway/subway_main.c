#define _CRT_SECURE_NO_WARNINGS
#include "subway.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
	//����ü ���� �� ���� ������� ���� �⺻ ���� ����
	struct subway subway[300]; //����ö �� ��ȣ, �� ���� ������ ����ü
	struct line line[300]; //����ö ��� ��, ���� ��, ���� �Ÿ��� ������ ����ü

	FILE* f; //���� ������� ���� ������ ����
	char a[50], b[50]; 
	int i = 1;
	
	f = fopen("station_num.txt", "r"); 
	while (i != 243) {
		fscanf(f, "%d %s", &(subway[i].num), a);
		strcpy(subway[i].name, a);
		i++;
	}
	//����ö �� ��ȣ, �� ���� ������ txt ���� �Է�
	//����ü�� ��� ������ ���ڿ��� �ٷ� �Է��� ���� �� ������ ����� ���� �����ϱ� ���� strcpy �Լ��� ���

	i = 1;
	f = fopen("distance.txt", "r");
	while (i != 273) {
		fscanf(f, "%s %s %d", a, b, &(line[i].num));
		strcpy(line[i].start, a);
		strcpy(line[i].end, b);
		i++;
	}
	//����ö ��� ��, ���� ��, �����Ÿ��� ������ txt ���� �Է�
	//����ü�� ��� ������ ���ڿ��� �ٷ� �Է��� ���� �� ������ ����� ���� �����ϱ� ���� strcpy �Լ��� ���

	graphtype* g1 = (graphtype*)malloc(sizeof(graphtype));
	creategraph(g1);

	insertDist(g1, line, subway);//���, ����, ����ġ�� �����ϴ� ����

	while (1) {
		int number;
		menu(); //number�� �Է¹ޱ� ���� �⺻ ���� ��� ����
		scanf("%d", &number);
		switch (number) {
		case 1:
			for (i = 1; i < 243; i++) printf(" | %5d | %-18s |\n", subway[i].num, subway[i].name);
			break;
			//��ü ���� �� ��ȣ, ���� ���
		case 2:
			for (i = 1; i < 273; i++) printf(" | %-18s | %-18s | %-5d |\n", line[i].start, line[i].end, line[i].num);
			break;
			//��ü ���� ��� ��, ���� ��, ���� �Ÿ� ���
		case 3:
			printlist(g1, subway); //���� ���� ����ϴ� ����
			break;
		case 4 :
			turnlist(g1, subway); //ȯ�¿��� ����ϴ� ����
			break;
		default :
			return 0;
			break;

		}
	}
	getchar();
	return;
}

