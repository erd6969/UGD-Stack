#include "header.h"

int main(int argc, char *argv[]) {
	int menu;
	string op;
	string operasi;
	Stack s;
	init(&s);
	Stack2 s2;
	Stack3 s3;
	init2(&s2);
	init3(&s3);
	
	do{
		system("cls");
		printf("\n\t\t===--- UGD TIPE D STACK ARRAY ---===");
		printf("\n\n\t[1]. Input Skor Pertandingan");
		printf("\n\t[2]. Hitung Skor Akhir");
		printf("\n\n\t\t==-- [BONUS] --==");
		printf("\n\t[3]. Operasi Prefix [Bonus]");
		printf("\n\t[0]. EXIT");
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1 : 
				printf("\n\tMasukkan Skor Pertandingan	: "); fflush(stdin); gets(op);
					while(exceptionPoint(op)==-1 || strlen(op)==0){
						if(strlen(op)==0){
							printf("\n\t\t[!] Input Tidak Boleh Kosong");
						}else{
							printf("\n\t\t[!] Input User Tidak Valid");
						}
						printf("\n\tMasukkan Skor Pertandingan	: "); fflush(stdin); gets(op);
					}
				printf("\n\t[+] Berhasil Input Skor");
			break;
			
			case 2 :
				if(strlen(op)!=0){
					printf("\n\tSkor Pertandingan	: %s", op);
					printf("\n\n\tSkor Akhirnya Adalah	: %d", point(s, op));
				}else{
					printf("\n\t\t[!] Anda Belum Memasukkan Skor Pertandingan");
				}
			break;
			
			case 3 :
				printf("\n\tMasukkan Operasi Prefix	: "); fflush(stdin); gets(operasi);
					while(strlen(operasi)==0){
						printf("\n\t\t[!] Operasi Tidak Boleh Kosong");
						printf("\n\tMasukkan Operasi Prefix	: "); fflush(stdin); gets(operasi);
					}
				reverseString(s2, operasi);
				printf("\n\tHasil = %d", evaluasiPrefix(s3, operasi));
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
