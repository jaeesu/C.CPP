#define _CRT_SECURE_NO_WARNINGS
#include "headerInt.h"


//1.층 누르면 올라갔다가 목적지 입력하면 내려오기, 입력받으면 올라가는 함수, 입력받으면 내려오는 함수

//올라가는 함수
//floor 현재 층??
//위에서 버튼을 누르는 것과 안에서 층을 누르는 것

//위에서 내림 버튼 누르면 올라가는 함수


void button(nodetype* dq,int, int);

void Downfloor(int*, int);

void Upfloor(int*, int);

void Number(nodetype* dq, int, int);



//오름인지 내림인지에 따라 ifelse, button 층 입력되자마자 데크에 넣고 실행