#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_stack 100
#define max_stack2 10

typedef char string[100];

typedef struct{
	int top;
	char kata[max_stack];
}Stack;

int isEmpty(Stack s);
int isFull(Stack s);

void init(Stack *s);
void push(Stack *s, char kata);

void pop(Stack *s);

void show(Stack s);

int errorHandling(string kata);
int cekKata(Stack s, string kata);

//Bonus
typedef struct{
	int top;
	int operasi[max_stack2];
}Stack2;

void init2(Stack2 *s);

int pop2(Stack2 *s);

void push2(Stack2 *s, char operasi);

int evaluasiPostFix(Stack2 s, string operasi);
