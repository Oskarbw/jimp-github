#include "gauss.h"
#include <math.h>


void zamien(double** a, double** b)
{
	double* c = *a;
	*a = *b;
	*b = c;
}

void wyborElementu (Matrix* mat, Matrix* b, int i)
{
	double max = 0;
	int nrMax = 0;
	int nrWier = i;
	for (i;i<mat->r;i++)
	{
		if(fabs(mat->data[i][nrWier])>max)
		{
			nrMax = i;
			max = fabs(mat->data[i][nrWier]);
		}
	}

	zamien(&mat->data[nrMax], &mat->data[nrWier]);
	zamien(&b->data[nrMax], &b->data[nrWier]);
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	for (int i=0; i < mat->c && i < mat->r; i++){
		wyborElementu(mat,b,i);
		if (mat->data[i][i] == 0.0) /* macierz osobliwa, dzielenie przez 0 */
			return 1;
		for (int j=i+1; j < mat->r; j++){
			double dziel = mat->data[j][i] / mat->data[i][i];
			for (int k=0; k < mat->c; k++){
				mat->data[j][k] -= dziel * mat->data[i][k];
			}
			b->data[j][0] -= dziel * b->data[i][0];
		}
	}
	return 0;
}
