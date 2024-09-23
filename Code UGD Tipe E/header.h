#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_stack 100

typedef char string[100];

typedef struct{
	string judul;
	string kode;
	float harga;
	string status;
}Data;

typedef struct{
	int top;
	char kata[max_stack];
}Stack;

int isEmpty(Stack s);
int isFull(Stack s);

void init(Stack *s);
void push(Stack *s, char kata);

char pop(Stack *s);

void show(Data d[]);

void initData(Data d[]);
int kodeException(string kode);
void inputData(Data d[], int index, string judul, string kode, float harga);
int findEmptyArray(Data d[]);
int nbData(Data d[]);
int isPalindrom(Stack s, Data d[], int index);

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
