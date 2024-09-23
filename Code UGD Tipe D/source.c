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

int pop(Stack *s){
	int temp;
	
	temp = (*s).kata[(*s).top];
	(*s).top--;
	return temp;
}

int exceptionPoint(string op){
	int i;
	
	for(i = 0; i < strlen(op); i++){
		if(!isdigit(op[i])){
			if(op[i] != 'F' && op[i] != 'f' && op[i] != 'H' && op[i] != 'h' && op[i] != '+'){
				return -1;
			}
		}
	}
	return 1;
}

int point(Stack s, string op){
	int val1, val2, temp;
	int sum = 0;
	int i;
	
	for(i = 0; i < strlen(op); i++){
		if(op[i] == 'F' || op[i] == 'f'){
			pop(&s);
		}else if(op[i] == 'H' || op[i] == 'h'){
			temp = s.kata[s.top]*2;
			push(&s, temp);
		}else if(op[i] == '+'){
			val1 = s.kata[s.top];
			pop(&s);
			val2 = s.kata[s.top];
			push(&s, val1);
			push(&s, val1 + val2);
		}else{
			push(&s, op[i] - '0');
		}
	}
		while(!isEmpty(s)){
			sum += s.kata[s.top];
			pop(&s);
		}
		
	return sum;
}

//Bonus

//Untuk reverse string

void init2(Stack2 *s){
	(*s).top=-1;
}

int isEmpty2(Stack2 s){
	return s.top==-1;
}

void push2(Stack2 *s, char operasi){
	(*s).top++;
	(*s).operasi[(*s).top] = operasi;
}

char pop2(Stack2 *s){
	int temp;
	
	temp = (*s).operasi[(*s).top];
	(*s).top--;
	return temp;
}

void reverseString(Stack2 s, string operasi){
	int i;
	
	for(i = 0; i < strlen(operasi); i++){
		push2(&s, operasi[i]);
	}
	
	for(i = 0; i < strlen(operasi); i++){
		operasi[i] = pop2(&s);
	}
}

//Untuk prefix

void init3(Stack3 *s){
	(*s).top=-1;
}

int isEmpty3(Stack3 s){
	return s.top==-1;
}

void push3(Stack3 *s, char operasi){
	(*s).top++;
	(*s).operasi[(*s).top] = operasi;
}

int pop3(Stack3 *s){
	int temp;
	
	temp = (*s).operasi[(*s).top];
	(*s).top--;
	return temp;
}

int evaluasiPrefix(Stack3 s, string operasi){
	int i;

	for(i = 0; i < strlen(operasi); i++){
		if(isdigit(operasi[i])){
			push3(&s, operasi[i] - '0');
		}else{
			int var1 = pop3(&s);
			int var2 = pop3(&s);
			
			if(operasi[i] == '+'){
				push3(&s, var1 + var2);
			}else if(operasi[i] == '-'){
				push3(&s, var1 - var2);
			}else if(operasi[i] == '*'){
				push3(&s, var1 * var2);
			}else if(operasi[i] == '/'){
				push3(&s, var1 / var2);
			}
		}
	}
	return pop3(&s);
}
