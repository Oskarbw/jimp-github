#include "gauss.h"
#include <math.h>

void change(double** a, double** b)
{
	double* c = *a;
	*a = *b;
	*b = c;
}

void chooseElement(Matrix* mat, Matrix* b, int i)
{
	double max = 0;
	int nMax = 0;
	int nWier = i;
	for (i;i<mat->r;i++)
	{
		if(fabs(mat->data[i][nrWier])>max)
		{
			nrMax = i;
			max = fabs(mat->data[i][nrWier]);
		}
	}

	change(&mat->data[nMax], &mat->data[nWier]);
	change(&b->data[nMax], &b->data[nWier]);
}

/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	for (int i=0; i < mat->c && i < mat->r; i++){
		chooseElement(mat,b,i);
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
