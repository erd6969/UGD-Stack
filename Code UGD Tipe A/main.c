#include "header.h"

int main(int argc, char *argv[]) {
	int menu;
	string kata;
	string operasi;
	Stack s;
	init(&s);
	Stack2 s2;
	init2(&s2);
	
	do{
		system("cls");
		printf("\n\t\t===--- MODUL 3 STACK ARRAY ---===");
		printf("\n\n\t[1]. Input Kata");
		printf("\n\t[2]. Modifikasi Kata");
		printf("\n\n\t\t==-- [BONUS] --==");
		printf("\n\t[3]. Operasi Postfix [Bonus]");
		printf("\n\t[0]. EXIT");
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1 : 
				printf("\n\tMasukkan Sebuah Kata : "); fflush(stdin); gets(kata);
					while(strlen(kata)==0 || errorHandling(kata)==-1){
						if(errorHandling(kata)==-1){
							printf("\n\t[!] Input Tidak Boleh Terdiri Dari Angka !!!");
						}else{
							printf("\n\t[!] Input Tidak Boleh Kosong !!!");
						}
						printf("\n\tMasukkan Sebuah Kata : "); fflush(stdin); gets(kata);
					}
				printf("\n\t[+] Berhasil Input kata");
			break;
			
			case 2 :
				if(cekKata(s, kata)==-1){
					printf("\n\tKata Awal	: %s", kata);
					printf("\n\n\t\t[!] Modifikasi Kata Tidak Tervalidasi");
				}else{
					printf("\n\t\t[*] Modifikasi Kata Berhasil Tervalidasi Dengan Baik");
				}
			break;
			
			case 3 :
				printf("\n\tMasukkan Operasi Postfix	: "); fflush(stdin); gets(operasi);
					while(strlen(operasi)==0 || strlen(operasi)>10){
						if(strlen(operasi)==0){
							printf("\n\t\t[!] Operasi Tidak Boleh Kosong");
						}else{
							printf("\n\t\t[!] Operasi Tidak Boleh Lebih Dari 10 Baris");
						}
						
						printf("\n\tMasukkan Operasi Postfix	: "); fflush(stdin); gets(operasi);
					}
				printf("\n\tHasil = %d", evaluasiPostFix(s2, operasi));
			break;
			
			case 0 :
				printf("\n\t\tNama Lengkap - NPM - Kelas");
			break;
			
			default : 
				printf("\n\t\tTidak Tersedia [!]");
			break;
		}getch();
	}while(menu!=0);
	
	return 0;
}
