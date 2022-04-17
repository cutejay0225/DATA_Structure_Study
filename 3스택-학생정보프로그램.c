#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef struct Student {
	int id;
	char name[32];
	char dept[32];
}Student;
typedef Student Element;
Element data[MAX_STACK_SIZE];
int top;

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}
void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }

void push(Element e)
{
	if (is_full())
		error("스택 포화 에러");
	data[++top] = e;
}
Element pop()
{
	if (is_empty())
		error("스택 공백 에러");
	return data[top--];
}
Element peek()
{
	if (is_empty())
		error("스택 공백 에러");
	return data[top];
}

void print_stack(char msg[])
{
	int i;
	printf("%s[%2d]= ")
}
