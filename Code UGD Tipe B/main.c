#include "header.h"

int main(int argc, char *argv[]) {
	int menu;
	string kurung;
	Stack s;
	init(&s);
	
	do{
		system("cls");
		printf("\n\t\t===--- UGD TIPE B STACK ARRAY ---===");
		printf("\n\n\t[1]. Input kurung");
		printf("\n\t[2]. Cek kurung");
		printf("\n\t\t==-- [BONUS] --==");
		printf("\n\t[3]. Count Longest Parentheses [Bonus]");
		printf("\n\t[0]. EXIT");
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1 : 
				init(&s);
				printf("\n\tMasukkan Kurung [Maks 10 Char] : "); fflush(stdin); gets(kurung);
					while(strlen(kurung)==0 || errorHandling(kurung)==-1){
						if(strlen(kurung)==0){
							printf("\n\t[!] Input Tidak Boleh Kosong !!!");
						}else{
							printf("\n\t[!] Tidak Boleh Mengandung Selain Kurung !!!");
						}
						printf("\n\tMasukkan Kurung [Maks 10 Char] : "); fflush(stdin); gets(kurung);
					}
				printf("\n\t[+] Berhasil Input kurung");
			break;
			
			case 2 :
				if(cekkurung(s, kurung)==-1){
					printf("\n\tInput Kurung User	 : %s", kurung);
					printf("\n\n\t[!] Kurung Tidak Tervalidasi Seimbang");
				}else{
					printf("\n\tInput Kurung User	 : %s", kurung);
					printf("\n\n\t[*] Kurung Berhasil Tervalidasi Seimbang");
				}
			break;
			
			case 3 :
				printf("\n\tMasukkan Kurung [Maks 10 Char] : "); fflush(stdin); gets(kurung);
					while(errorHandling2(kurung)==-1 || strlen(kurung)==0 || strlen(kurung) > 10){
						if(strlen(kurung) > 10){
							printf("\n\t[!] Input Overload !!!");
						}else if(strlen(kurung)==0){
							printf("\n\t[!] Input Tidak Boleh Kosong !!!");
						}else{
							printf("\n\t[!] Tidak Boleh Mengandung Selain Kurung () !!!");
						}
						printf("\n\tMasukkan Kurung [Maks 10 Char] : "); fflush(stdin); gets(kurung);
					}
					printf("\n\tPanjang dari kurung yang tervalidasi adalah : %d", findMax(s, kurung));
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
