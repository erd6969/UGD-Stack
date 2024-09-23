#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_stack 100

typedef char string[100];

typedef struct{
	int top;
	int kata[max_stack];
}Stack;

int isEmpty(Stack s);
int isFull(Stack s);

void init(Stack *s);
void push(Stack *s, char kata);

int pop(Stack *s);

int exceptionPoint(string op);
int point(Stack s, string op);

//Bonus

//Untuk reverse string
typedef struct{
	int top;
	char operasi[max_stack];
}Stack2;

void init2(Stack2 *s);

char pop2(Stack2 *s);

void push2(Stack2 *s, char operasi);

//Untuk prefix
typedef struct{
	int top;
	int operasi[max_stack];
}Stack3;

void init3(Stack3 *s);

int pop3(Stack3 *s);

void push3(Stack3 *s, char operasi);

int evaluasiPrefix(Stack3 s, string operasi);
