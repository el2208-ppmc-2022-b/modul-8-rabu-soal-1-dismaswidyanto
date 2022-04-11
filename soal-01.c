/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 8 - Advanced Algorithms
*Percobaan        : -
*Hari dan Tanggal : Rabu, 13 April 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define n 5


int main(void) {
	char filename[256];
	int matrix[5][5];
	char line[5];
	char *token;
	char delim[] = " ";
	int i, j;


	// Inisialisasi file eksternal
	printf("Nama file yang akan dibaca: ");
	scanf("%s", ...);
	FILE* fp = fopen(..., "r");

	for(j=0; j<5; j++) {
		for(i=0; i<5; i++) {
			if(fscanf(fp, "%d", &matrix[j][i]) != 1) {
				exit(1);
			}
		}  
	}
	fclose(fp);
	/*
	for(j=0; j<5; j++)
			for(i=0; i<5; i++)
				printf("%d ", matrix[j][i]); 
	*/
	printf("Panjang jalur terpanjang: %d", ...);
	return 0;
}
