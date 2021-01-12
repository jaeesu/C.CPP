#pragma once

#include<stdio.h>
#include<stdlib.h>

//노드 설정

typedef int element;

typedef struct node { //typedef struct 구조체 이름 마지막에 구조체 별칭
	element data;
	struct node* rlink;
	struct node* llink;
}node;

class deq{
    private :
        struct node* front;
        struct node* rear;
    public :
        //공백 데크 생성
        deq();

        //공백 검사
        int isEmpty();

        //front 앞에 item
        void pushF(element item);

        //rear 뒤에 item
        void pushR(element item);

        //front 삭제 반환
        element popF();

        //rear 삭제 반환
        element popR();

        //front 반환
        element peekF();

        //rear 반환
        element peekR();

        //front부터 rear까지 반환
        void printdeque();

};