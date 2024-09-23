#include "header.h"

int main(int argc, char *argv[]) {
	string kode, operasi;
	int menu, i;
	Data d;
	Stack s, temp, temp2, history;
	init(&s);
	init(&temp);
	init(&temp2);
	init(&history);
	
	do{
		system("cls");
		printf("\n\t===--- UGD TIPE C ---===");
		printf("\n\n\t[1]. Input Barang");
		printf("\n\t[2]. Show Barang");
		printf("\n\t[3]. Undo");
		printf("\n\t[4]. Redo");
		printf("\n\t[5]. Drop Database	[BONUS]");
		printf("\n\t[6]. History		[BONUS]");
		printf("\n\t[0]. EXIT");
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu){
			
			case 1 :
				if(!isFull(s)){
					init(&temp);
					printf("\n\tMasukkan Nama Barang	: "); fflush(stdin); gets(d.nama);
						while(strlen(d.nama)==0 || strcmpi(d.nama, "-")==0){
							printf("\n\t\t[!] Nama Barang Tidak Boleh Kosong");
							printf("\n\tMasukkan Nama Barang	: "); fflush(stdin); gets(d.nama);
						}
					printf("\n\tMasukkan Kode Barang	: "); fflush(stdin); gets(d.kode);
						while(strlen(d.kode)==0 || strcmpi(d.kode, "-")==0 || strlen(d.kode)!=5 || exceptionKode(d.kode)==-1){
							if(exceptionKode(d.kode)==-1){
								printf("\n\t\t[!] Kode Barang Tidak Boleh Terdiri Dari Angka");
							}else{
								printf("\n\t\t[!] Kode Barang Tidak Boleh Kurang Dari 5 / Kosong");
							}
							printf("\n\tMasukkan Kode Barang	: "); fflush(stdin); gets(d.kode);
						}
					printf("\n\tMasukkan Harga Barang	: "); scanf("%f", &d.harga);
						while(d.harga <= 0){
							printf("\n\t\t[!] Harga Tidak Boleh Kurang Dari 0");
							printf("\n\tMasukkan Harga Barang	: "); scanf("%f", &d.harga);
						}
					push(&s, d);
					printf("\n\t[+] Data Berhasil Dimasukkan Ke Database");
				}else{
					printf("\n\t\t[!] Database Sudah Penuh");
				}
			break;
			
			case 2 :
				if(!isEmpty(s)){
					show(s);
				}else{
					printf("\n\t\t[!] Database Masih Kosong");
				}
			break;
			
			case 3 :
				if(!isEmpty(s)){
					push(&temp, pop(&s));
					printf("\n\t[-] Undo Success");
				}else{
					printf("\n\t\t[!] Nothing to Undo");
				}
			break;
			
			case 4 :
				if(!isEmpty(temp)){
					push(&s, pop(&temp));
					printf("\n\t[-] Redo Success");
				}else{
					printf("\n\t\t[!] Nothing to Redo");
				}
			break;
			
			case 5 :
				if(!isEmpty(s)){
					while(!isEmpty(s)){
						if(isFull(history)){
							for(i = 0; i < 4; i++){
								push(&temp2, pop(&history));
							}
							
							pop(&history);
							
							for(i = 0; i < 4; i++){
								push(&history, pop(&temp2));
							}
							
							push(&history, pop(&s));
							
						}else{
							push(&history, pop(&s));
						}
					}
					printf("\n\t[+] Berhasil Drop Database");
				}else{
					printf("\n\t\t[!] Database Masih Kosong");
				}
			break;
			
			case 6 :
				if(!isEmpty(history)){
					show(history);
				}else{
					printf("\n\t\t[!] History Masih Kosong");
				}
			break;
			
			case 0 :
				printf("\n\t\tGood Luck Have Fun :D");
				printf("\n\t\tNama Lengkap - NPM - Kelas");
			break;
			
			default : 
				printf("\nTidakj Tersedia [!]");
			break;
		}getch();
	}while(menu!=0);
	
	return 0;
}
