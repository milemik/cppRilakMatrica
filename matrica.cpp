#include "stdio.h"
#include "stdlib.h"
#define MAX 100
void popunjavanjeMatrice (int m, int n, int a[][MAX]) {
	// Inicijalizacija pocetne vrednosti matrice - odnosno njenog prvog elementa na lokaciji A[0][0]
	int firstValue = 1;
	int endRowIndex = m;
	int endColumnIndex = n;
	/* 
		rowIndex - pocetni index reda
		endRowIndex - zavrsni index reda
		columnIndex - pocetni index kolone
		endColumnIndex - zavrsni index kolone
	*/
	// Inicijalizacija rowIndex i coulmnIndex
	int rowIndex = 0, columnIndex = 0;
	
	while(rowIndex < endRowIndex && columnIndex < endColumnIndex) {
		
		// Prvi red od ostalih redova
		for(int i = columnIndex; i < endColumnIndex; i++) {
			a[rowIndex][i] = firstValue++;
		}
		rowIndex++;
		// 	Zadnja kolona od ostalih kolona
		for (int i = rowIndex; i < endRowIndex; i++) {
			a[i][endColumnIndex-1] = firstValue++;
		}
		endColumnIndex--;
		// Poslednji red od preostalih redova
		if(rowIndex < endRowIndex) {
			for(int i = endColumnIndex - 1; i>=1; i--) {
				a[endRowIndex-1][i] = firstValue++;
			}
			endRowIndex--;
		}
		// Poslednju kolonu od preostalih kolona
		if( columnIndex < endColumnIndex) {
			/* 
			endRowIndex - 1?????? Smanjo si matricu za jedan element
			treba da bude samo endRowIndex
			*/
			for(int i = endRowIndex; i>=rowIndex; i--) {
				a[i][columnIndex] = firstValue++;
			}
			columnIndex++;
		}
	}
}
int main() {
	int m, n;
	printf("Unesi M i N");
	scanf("%d%d",&m,&n);
	int a[MAX][MAX];
	popunjavanjeMatrice(m,n,a);
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			printf("%d \t",a[i][j]);
		}
	printf("\n");
	}
}
