#include <stdio.h>  
#include <stdlib.h>

typedef int Element;
typedef struct LinkNode {
    Element data;
    struct LinkdeNode* link;
}Node;

Node* front = NULL;
Node* rear = NULL;  // 연결된 큐 NULL로 반드시 초기화

void error(char str[]) 
{    //185p 에러 함수
    fprintf(stderr, "s\n", str);
    exit(1);
}

int is_empty() { return front == NULL; }    // 공백상태 검사
void init_queue() { front = rear = NULL; }   // 초기화 함수
int size()
{   // 큐의 모든 노드의 개수를 계산하는 함수 (시작 포인터가 front인 점을 제외하면 스택과 코드 동일)
    Node* p;
    int count = 0;
    for (p = front; p != NULL; p = p->link) count++;
    return count;
}
// 연결된 큐의 삽입 연산
void enqueue(Element e ) { // main 함수의 매개변수 (i 가 e) 
    Node* p = (Node*)malloc(sizeof(Node));  // 노드 동적 할당
    p->data = e;    // data 필드 초기화
    p->link = NULL; // link 필드 초기화 

    if (is_empty()) front = rear = p;
    else {
        rear->link = p;
        rear = p;
    }
}
//  연결된 큐의 삭제 연산
Element dequeue() {
    Node* p;
    Element e;

    if (is_empty())
        error("큐 공백 에러");

    p = front;  // front가 가르키는 노드 a를 p가 가르키게 한다 
    front = front->link;    // front가 다음 노드 b를 가르키도록 한다
    if (front == NULL) rear = NULL; // 노드가 하나뿐일때 front 가 NULL 이면  rear 도 NULL 로 만들어준다
    e = p->data;    // p의 항목 복사 -> 출력 부분에 dequeue 를 출력해주어야 하기때문에 코드 존재
    free(p);    // p 동적 해제
    return e;   // 복사된 항목 반환
}
// peek 함수. 공백을 검사하고 시작포인터 front 의 데이터 필드를 반환함
Element peek()
{
    if (is_empty())
        error("큐 공백 에러");
    return front->data;
}

// 연결된 큐의 모든 노드를 동적으로 해제하는 함수. 공백상태가 아닐때까지 dequeue 연산 실행
void destroy_queue()
{
    while (is_empty() == 0)
        dequeue();
}

// 큐의 모든 내용을 화면에 출력하는 함수. front 부터 출력
void print_queue(char* msg)
{
    Node* p;
    print("%s[%2d]= ", msg, size());
    for (p = front; p != NULL; p = p->link)
        printf("%2d", p->data);
    printf("\n");
}