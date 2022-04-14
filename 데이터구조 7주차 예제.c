#include <stdio.h>  
#include <stdlib.h>

typedef int Element;
typedef struct LinkNode {
    Element data;
    struct LinkdeNode* link;
}Node;

Node* front = NULL;
Node* rear = NULL;  // ����� ť NULL�� �ݵ�� �ʱ�ȭ

void error(char str[]) 
{    //185p ���� �Լ�
    fprintf(stderr, "s\n", str);
    exit(1);
}

int is_empty() { return front == NULL; }    // ������� �˻�
void init_queue() { front = rear = NULL; }   // �ʱ�ȭ �Լ�
int size()
{   // ť�� ��� ����� ������ ����ϴ� �Լ� (���� �����Ͱ� front�� ���� �����ϸ� ���ð� �ڵ� ����)
    Node* p;
    int count = 0;
    for (p = front; p != NULL; p = p->link) count++;
    return count;
}
// ����� ť�� ���� ����
void enqueue(Element e ) { // main �Լ��� �Ű����� (i �� e) 
    Node* p = (Node*)malloc(sizeof(Node));  // ��� ���� �Ҵ�
    p->data = e;    // data �ʵ� �ʱ�ȭ
    p->link = NULL; // link �ʵ� �ʱ�ȭ 

    if (is_empty()) front = rear = p;
    else {
        rear->link = p;
        rear = p;
    }
}
//  ����� ť�� ���� ����
Element dequeue() {
    Node* p;
    Element e;

    if (is_empty())
        error("ť ���� ����");

    p = front;  // front�� ����Ű�� ��� a�� p�� ����Ű�� �Ѵ� 
    front = front->link;    // front�� ���� ��� b�� ����Ű���� �Ѵ�
    if (front == NULL) rear = NULL; // ��尡 �ϳ����϶� front �� NULL �̸�  rear �� NULL �� ������ش�
    e = p->data;    // p�� �׸� ���� -> ��� �κп� dequeue �� ������־�� �ϱ⶧���� �ڵ� ����
    free(p);    // p ���� ����
    return e;   // ����� �׸� ��ȯ
}
// peek �Լ�. ������ �˻��ϰ� ���������� front �� ������ �ʵ带 ��ȯ��
Element peek()
{
    if (is_empty())
        error("ť ���� ����");
    return front->data;
}

// ����� ť�� ��� ��带 �������� �����ϴ� �Լ�. ������°� �ƴҶ����� dequeue ���� ����
void destroy_queue()
{
    while (is_empty() == 0)
        dequeue();
}

// ť�� ��� ������ ȭ�鿡 ����ϴ� �Լ�. front ���� ���
void print_queue(char* msg)
{
    Node* p;
    print("%s[%2d]= ", msg, size());
    for (p = front; p != NULL; p = p->link)
        printf("%2d", p->data);
    printf("\n");
}