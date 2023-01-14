#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ������ �̿��� ���� ǥ��� ���� �˰���

typedef int element;

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

element evalPostfix(const char* exp)	// ���� ǥ����� ����
{
	int opr1, opr2, value, i = 0;
	int length = strlen(exp);
	char symbol;
	top = NULL;
	for (i = 0;i < length;i++)
	{
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/')
		{
			value = symbol - '0';
			push(value);
		}
		else
		{
			opr2 = pop();
			opr1 = pop();
			switch (symbol)
			{
			case '+': push(opr1 + opr2); break;
			case '-': push(opr1 - opr2); break;
			case '*': push(opr1 * opr2); break;
			case '/': push(opr1 / opr2); break;
			}
		}
	}
	return pop();
}

void main()
{
	int result;
	const char* express = "35*62/-";
	printf("����ǥ��� : %s", express);
	result = evalPostfix(express);
	printf("\n\n ������ => %d", result);
	return;
}