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

void push(Stack *s, char kata){
	(*s).top++;
	(*s).kata[(*s).top] = kata;
}

void pop(Stack *s){
	(*s).top--;
}

void show(Stack s){
	int i;
	
	printf("\n\tHasil Akhir Kata	: ");
	for(i = s.top; i !=-1; i--){
		printf("%c", s.kata[i]);
	};
	printf("\n\n");
}

int errorHandling(string kata){
	int i;
	
	for(i = 0; i < strlen(kata); i++){
		if(kata[i] == '1' || kata[i] == '2' || kata[i] == '3' || kata[i] == '4' || kata[i] == '5' || kata[i] == '6' || kata[i] == '7' || kata[i] == '8' || kata[i] == '9' || kata[i] == '0'){
			return -1;
		}
	}
	return 1;
}

int cekKata(Stack s, string kata){
	int i;
	
	for(i = 0; i < strlen(kata); i++){
		if(kata[i] != 'a' && kata[i] != 'i' && kata[i] != 'u' && kata[i] != 'e' && kata[i] != 'o' && kata[i] != 'A' && kata[i] != 'I' && kata[i] != 'U' && kata[i] != 'E' && kata[i] != 'O'){
			push(&s, kata[i]);
		}else{
			if(isEmpty(s)){
				return -1;
			}else{
				pop(&s);
				push(&s, kata[i]);	
			}					
		}	
	}
	
	if(isEmpty(s)){
		return -1;
	}else{
		printf("\n\tKata Awal		: %s", kata);
		show(s);
		return 1;
	}
}

//Bonus
void init2(Stack2 *s){
	(*s).top=-1;
}

void push2(Stack2 *s, char operasi){
	(*s).top++;
	(*s).operasi[(*s).top] = operasi;
}

int pop2(Stack2 *s){
	int temp;
	
	temp = (*s).operasi[(*s).top];
	(*s).top--;
	return temp;
}

int evaluasiPostFix(Stack2 s, string operasi){
	int i;
	
	for(i = 0; i < strlen(operasi); i++){
		if(isdigit(operasi[i])){
			push2(&s, operasi[i] - '0');
		}else{
			int var1 = pop2(&s);
			int var2 = pop2(&s);
			
			if(operasi[i] == '+'){
				push2(&s, var1 + var2);
			}else if(operasi[i] == '-'){
				push2(&s, var2 - var1);
			}else if(operasi[i] == '*'){
				push2(&s, var1 * var2);
			}else if(operasi[i] == '/'){
				push2(&s, var1 / var2);
			}
		}
	}
	return pop2(&s);
}
