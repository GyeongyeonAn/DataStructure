#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char element;

typedef struct stackNode
{
	element data;
	stackNode* link;
}stackNode;

stackNode* top;

void push(element item)	// ��� ����
{
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

element pop()	// ��� ��ȯ
{
	element item;
	stackNode* temp = top;
	if (top == NULL)
	{
		printf("\n\n Stack is empty \n");
		return 0;
	}
	else
	{
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}

void del()	// ���� ���� ��� ����
{
	stackNode* temp;
	if (top == NULL)
	{
		printf("\n\n Stack is empty \n");
	}
	else
	{
		temp = top;
		top = top->link;
		free(temp);
	}
}

element peek()	// ���� �˻�
{
	element item;
	if (top == NULL)
	{
		printf("\n\n Stack is Empty \n");
		return 0;
	}
	else
	{
		item = top->data;
		return item;
	}
}

void printStack()
{
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("] ");
}

int testPair(const char* exp)
{
	char symbol, open_pair;
	int i, length = strlen(exp);
	top = NULL;
	for (i = 0; i < length; i++)
	{
		symbol = exp[i];
		switch (symbol)
		{
		case '(':
		case '{':
		case '[':
			push(symbol);	break;
		case ')':
		case '}':
		case ']':
			if (top == NULL)	return 0;
			else
			{
				open_pair = pop();
				if ((open_pair == '(' && symbol != ')') ||
					(open_pair == '{' && symbol != '}') ||
					(open_pair == '[' && symbol != ']'))
					return 0;
				else break;
			}
		}
	}
	if (top == NULL) return 1;
	else return 0;
}

void main()
{
	const char* express = "{(A + B) - 3}*5 + [{cos(x + y) + 7} - 1] * 4";
	printf("%s", express);
	if (testPair(express) == 1)
		printf("\n\n ������ ��ȣ�� �°� ���Ǿ����ϴ�.");
	else
		printf("\n\n ������ ��ȣ�� Ʋ�Ƚ��ϴ�.");
	return;
}