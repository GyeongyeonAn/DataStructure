#include<stdio.h>
#include<stdlib.h>
#define STACK_SIZE 100

typedef int element; // int를 스택 element의 자료형으로 정의
element stack[STACK_SIZE];
int top = -1;

void push(element item)	// 요소 삽입
{
	if (top >= STACK_SIZE - 1)
	{
		printf("\n\n Stack is FULL \n");
		return;
	}
	else stack[++top] = item;
}

element pop()	// 요소 반환
{
	if (top == -1)
	{
		printf("\n\n Stack is Empty \n");
		return 0;
	}
	else return stack[top--];
}	

void del()	// 리턴 없이 요소 제거
{
	if (top == -1)
	{
		printf("\n\n Stack is Empty \n");
		exit(1);
	}
	else top--;
}

element peek()	// 원소 검색
{
	if (top == -1)
	{
		printf("\n\n Stack is Empty \n");
		exit(1);
	}
	else return stack[top];
}

void printStack()
{
	int i;
	printf("\n STACK [ ");
	for (i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("] ");
}

void main()
{
	int item;
	printStack();
	push(1);
	printStack();
	push(2);
	printStack();
	push(3);
	printStack();

	item = peek();
	printStack();
	printf("peek top => %d", item);

	del();
	printStack();

	item = pop();
	printStack();
	printf("\t pop top => %d", item);
	return;
}