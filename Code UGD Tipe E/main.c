#include "header.h"

int main(int argc, char *argv[]) {
	int menu, index, jumlah, i;
	string judul, kode, status;
	string operasi;
	float harga;
	Data d[5];
	Stack s;
	
	init(&s);
	initData(d);
	Stack2 s2;
	Stack3 s3;
	init2(&s2);
	init3(&s3);
	
	do{
		system("cls");
		printf("\n\t\t===--- MODUL 3 STACK ARRAY ---===");
		printf("\n\n\t[1]. Input Data");
		printf("\n\t[2]. Show Data");
		printf("\n\t[3]. Cek Palindrom");
		printf("\n\n\t\t==-- [BONUS] --==");
		printf("\n\t[4]. Operasi Prefix [Bonus]");
		printf("\n\t[0]. EXIT");
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1 : 
				if(findEmptyArray(d)!=-1){
					index = findEmptyArray(d);
					printf("\n\tMasukkan Judul Buku		: "); fflush(stdin);gets(judul);
						while(strcmpi(judul, "")==0 || strcmpi(judul, "-")==0){
							printf("\n\t\t[!] Judul Tidak Boleh Kosong");
							printf("\n\tMasukkan Judul Buku	: "); fflush(stdin);gets(judul);
						}
					printf("\n\tMasukkan Kode Buku		: "); fflush(stdin); gets(kode);
						while(kodeException(kode)==-1){
							if(kodeException(kode)==-1){
								printf("\n\t\t[!] Kode Tidak Boleh Mengandung Angka");
							}
							printf("\n\tMasukkan Kode Buku		: "); fflush(stdin); gets(kode);
						}
					printf("\n\tMasukkan Harga Buku		: "); scanf("%f", &harga);
						while(harga <= 0){
							printf("\n\t\t[!] Harga Harus Lebih Besar Dari 0");
							printf("\n\tMasukkan Harga Buku		: "); scanf("%f", &harga);
						}
					inputData(d, index, judul, kode, harga);
					printf("\n\t\t[+] Data Berhasil Terinput");
				}else{
					printf("\n\t\t[!] Data Sudah Penuh");
				}
			break;
			
			case 2 :
				if(d[0].harga != 0){
					show(d);
				}else{
					printf("\n\t\t[!] Data Masih Kosong");
				}
			break;
			
			case 3 :
				if(d[0].harga != 0){
					for(i = 0; i < 5; i++){
						if(d[i].harga!=0){
							if(isPalindrom(s, d, i)==1 && strcmp(d[i].status, "Price On SALE 25%% !!!")!=0){
								d[i].harga = d[i].harga - d[i].harga * 25/100;
								strcpy(d[i].status, "Price On SALE 25%% !!!");
							}
						}
					}
					printf("\n\t\t[+] Check Success");
				}else{
					printf("\n\t\t[!] Data Masih Kosong");
				}
			break;
			
			case 4 :
				printf("\n\tMasukkan Operasi Prefix	: "); fflush(stdin); gets(operasi);
					while(strlen(operasi)==0){
						printf("\n\t\t[!] Operasi Tidak Boleh Kosong");
						printf("\n\tMasukkan Operasi Prefix	: "); fflush(stdin); gets(operasi);
					}
				reverseString(s2, operasi);
				printf("\n\tHasil = %d", evaluasiPrefix(s3, operasi));
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
