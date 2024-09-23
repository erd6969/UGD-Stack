#include "header.h"

void init(Stack *s){
	(*s).top=-1;
}

int isFull(Stack s){
	return s.top==max_stack-1;
}

int isEmpty(Stack s){
	return s.top==-1;
}

void push(Stack *s, Data data){
	(*s).top++;
	(*s).d[(*s).top] = data;
}

Data pop(Stack *s){
	Data temp;
	
	temp = (*s).d[(*s).top];
	(*s).top--;
	return temp;
}

void show(Stack s){
	int i;
	
	for(i = s.top; i !=-1; i--){
		printf("\n\t[%d]. Nama\t: %s", i+1, s.d[i].nama);
		printf("\n\t     Kode\t: %s", s.d[i].kode);
		printf("\n\t     Harga\t: Rp%.2f", s.d[i].harga);
		printf("\n");
	};
}

int exceptionKode(string kode){
	int i;
	
	for(i = 0; i < 5; i++){
		if(isdigit(kode[i])){
			return -1;
		}
	}
	return 1;
}
