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
	(*s).kata[(*s).top]=kata;
}

char pop(Stack *s){
	char temp;
	
	temp = (*s).kata[(*s).top];
	(*s).top--;
	return temp;
}

void show(Data d[]){
	int i;
	
	for(i = 0; i < 5; i++){
		if(d[i].harga !=0){
			printf("\n\t\tBuku [%d]", i+1);
			printf("\n\tJudul	: %s", d[i].judul);
			printf("\n\tKode	: %s", d[i].kode);
			printf("\n\tHarga	: Rp%.2f", d[i].harga);
			printf("\n\tStatus	: %s", d[i].status);
			printf("\n\n");
		}
	}
}

int kodeException(string kode){
	int i;
	
	for(i = 0; i < strlen(kode); i++){
		if(isdigit(kode[i])){
			return -1;
		}
	}
	return 1;
}

void initData(Data d[]){
	int i;
	
	for(i = 0; i < 5; i++){
		strcpy(d[i].judul, "");
		strcpy(d[i].kode, "");
		d[i].harga = 0;
		strcpy(d[i].status, "");
	}
}

int findEmptyArray(Data d[]){
	int i;
	
	for(i = 0; i < 5; i++){
		if(d[i].harga == 0){
			return i;
		}
	}
	return -1;
}

void inputData(Data d[], int index, string judul, string kode, float harga){
	strcpy(d[index].judul, judul);
	strcpy(d[index].kode, kode);
	d[index].harga = harga;
	strcpy(d[index].status, "Standard Price");
}

int nbData(Data d[]){
	int i;
	
	for(i = 0; i < 5; i++){
		if(d[i].harga == 0){
			return i+1;
		}
	}
}

int isPalindrom(Stack s, Data d[], int index){
	int i;
	
	for(i = 0; i < strlen(d[index].kode); i++){
		push(&s, d[index].kode[i]);
	}
	
	for(i = 0; i < strlen(d[index].kode); i++){
		if(pop(&s) != d[index].kode[i]){
			return -1;
		}
	}
	return 1;
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
