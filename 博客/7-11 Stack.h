#if 0

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Stack
{
	int array[100];
	//int capacity;
	int top; //size;
} Stack;

//³õÊ¼»¯
void StackInit(Stack *s)
{
	s->top = 0;
}

//
void StackPush(Stack *s)
{
	s->array[s->top++];
}

int StackPop(Stack *s)
{
	assert(s->top > 0);

	return s->array[--s->top];
}

int StackTop(Stack *s)
{
	assert(s->top > 0);
	return s->array[s->top - 1];
}

int StackSize(Stack *s)
{
	return s->top;
}

int StackIsEmpty(Stack *s)
{
	return s->top == 0 ? 1 : 0;
}
#endif