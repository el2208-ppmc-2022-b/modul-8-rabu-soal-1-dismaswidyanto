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
// Returns length of the longest path beginning with mat[i][j].
// This function mainly uses lookup table dp[n][n]

int max(int x, int y) {
	return (x > y)*x + (x <= y)*y;
}

int findLongestFromACell(int i, int j, int mat[n][n], int dp[n][n])
{
	if (i < 0 || i >= n || j < 0 || j >= n)
		return 0;
 
	// If this subproblem is already solved
	if (dp[i][j] != -1)
		return dp[i][j];
 
	// To store the path lengths in all the four directions
	int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN;
 
	// Since all numbers are unique and in range from 1 to n*n,
	// there is atmost one possible direction from any cell
	if (j < n - 1 && ((mat[i][j] + 1) == mat[i][j + 1]))
		x = 1 + findLongestFromACell(i, j + 1, mat, dp);
 
	if (j > 0 && (mat[i][j] + 1 == mat[i][j - 1]))
		y = 1 + findLongestFromACell(i, j - 1, mat, dp);
 
	if (i > 0 && (mat[i][j] + 1 == mat[i - 1][j]))
		z = 1 + findLongestFromACell(i - 1, j, mat, dp);
 
	if (i < n - 1 && (mat[i][j] + 1 == mat[i + 1][j]))
		w = 1 + findLongestFromACell(i + 1, j, mat, dp);
 
	// If none of the adjacent fours is one greater we will take 1
	// otherwise we will pick maximum from all the four directions
	return dp[i][j] = max(x, max(y, max(z, max(w, 1))));
}

// Returns length of the longest path beginning with any cell
int finLongestOverAll(int mat[n][n])
{
	int result = 1; // Initialize result
 
	// Create a lookup table and fill all entries in it as -1
	int dp[n][n];
	memset(dp, -1, sizeof dp);
 
	// Compute longest path beginning from all cells
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == -1)
				findLongestFromACell(i, j, mat, dp);
 
			// Update result if needed
			result = max(result, dp[i][j]);
		}
	}
 
	return result;
}

int main(void) {
	char filename[256];
	int matrix[5][5];

	int i, j;


	// Inisialisasi file eksternal
	printf("Nama file yang akan dibaca: ");
	scanf("%s", filename);
	FILE* fp = fopen(filename, "r");

	for(j=0; j<5; j++) {
		for(i=0; i<5; i++) {
			if(fscanf(fp, "%d", &matrix[j][i]) != 1) {
				exit(1);
			}
		}  
	}
	fclose(fp);

	printf("Panjang jalur terpanjang: %d", finLongestOverAll(matrix));
	return 0;
}
