#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define max_stack 100

typedef char string[100];

typedef struct{
	int top;
	char kurung[max_stack];
}Stack;

int isEmpty(Stack s);
int isFull(Stack s);

void init(Stack *s);
void push(Stack *s, char kurung);

char pop(Stack *s);

void show(Stack s);

int errorHandling(string kurung);
bool cekPasangan(char kurung1, char kurung2);
bool cekPasangan(char kurung1, char kurung2);

//Bonus

int findMax(Stack s, string kurung);
int errorHandling2(string kurung);
