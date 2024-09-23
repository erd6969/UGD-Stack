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

void push(Stack *s, char kurung){
	(*s).top++;
	(*s).kurung[(*s).top] = kurung;
}

char pop(Stack *s){
	char temp;
	
	temp = (*s).kurung[(*s).top];
	(*s).top--;
	return temp;
}

void show(Stack s){
	int i;
	
	printf("\n\tHasil Akhir kurung	: ");
	for(i = s.top; i !=-1; i--){
		printf("%c", s.kurung[i]);
	};
	printf("\n\n");
}

int errorHandling(string kurung){
	int i;
	
	for(i = 0; i < strlen(kurung); i++){
		if(kurung[i] != '(' && kurung[i] != ')' && kurung[i] != '[' && kurung[i] != ']' && kurung[i] != '{' && kurung[i] != '}'){
			return -1;
		}
	}
	return 1;
}

int cekkurung(Stack s, string kurung){
	int i;
	
	for(i = 0; i < strlen(kurung); i++){
		if(kurung[i] == '(' || kurung[i] == '{' || kurung[i] == '['){
			push(&s, kurung[i]);
		}else{
			if(isEmpty(s)){
				return -1;
			}else if(!cekPasangan(pop(&s), kurung[i])){
				return -1;		
			}
		}
	}
	
	if(isEmpty(s)){
		return 1;
	}else{
		return -1;
	}
}

bool cekPasangan(char kurung1, char kurung2){
    if (kurung1 == '(' && kurung2 == ')'){
    	return 1;
	} else if (kurung1 == '{' && kurung2 == '}'){
		return 1;
	}else if (kurung1 == '[' && kurung2 == ']'){
		return 1;
	}else{
		return 0;
	}
}

//Bonus
int findMax(Stack s, string kurung){
	int i;
	int res = 0;

	for(i = 0; i < strlen(kurung); i++){
		if(kurung[i] == '('){
			push(&s, kurung[i]);
		}else{
			if(!isEmpty(s) && s.kurung[s.top] == '('){
				pop(&s);
				
				int length = i - s.top;
				if(length > res){
					res = length;
				}
			}else{
				push(&s, kurung[i]);
			}
		}
	}
	
	return res;
}

int errorHandling2(string kurung){
	int i;
	
	for(i = 0; i < strlen(kurung); i++){
		if(kurung[i] != '(' && kurung[i] != ')'){
			return -1;
		}
	}
	return 1;
}
