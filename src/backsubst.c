#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
			

	if(mat->r!=mat->c){ return 2; }	
	if(mat->r!=b->r){ return 2; }	
	if(mat->r!=x->r){ return 2; }

	double tmp;
	for (int i=mat->r-1; i>=0 ;i--){
	
		tmp=b->data[i][0];
		for (int j=mat->c-1;j>=i+1;j--){
			tmp-= mat->data[i][j] * x->data[j][0];
		}
		if (mat->data[i][i]==0){ printf("DZIELENIE PRZEZ ZERO!! \n"); return 1;} //sprawdzamy czy nie dzieli przez zero
		x->data[i][0]= tmp / mat->data[i][i];
	}

	return 0;
}


