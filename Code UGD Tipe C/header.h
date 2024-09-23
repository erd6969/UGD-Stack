#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max_stack 5

typedef char string[100];

typedef struct{
	string nama;
	string kode;
	float harga;
}Data;

typedef struct{
	int top;
	Data d[max_stack];
}Stack;

int isEmpty(Stack s);
int isFull(Stack s);

void init(Stack *s);
void push(Stack *s, Data data);

Data pop(Stack *s);

void show(Stack s);

int exceptionKode(string kode);
