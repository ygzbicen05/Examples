/*
* Not optimized yet...
* May contain bugs
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void printMatrix(float*, int, int);
void addMatrices(float*, float*, float*, int, int);
void multiplyMatrices(float*, float*, float*, int, int, int);

int main(){
	/*
	[2 3 5]   vector      } 1-D array
	[[2 3 5]] row vect.      } 2-D
	[[2],[3],[5]] column vec.} 2-D (matrix)
	[[1 2],[3 4],[5 6]]      } 2-D
	
	float A[2][3] = {{1,2,3}, {4,5,6}};
	printMatrix(A, 2, 3);
	*/
	
	int i, j, m1, n1, m2, n2;
	printf("Dimensions of the first: ");
	scanf("%d%d", &m1, &n1);
	float temp, *M1 = (float*) malloc(m1 * n1 * sizeof(float));
	for(i = 0; i < m1; i++){
		for(j = 0; j < n1; j++){
			scanf("%f", &temp);
			M1[i * n1 + j] = temp;
		}
	}
	//printMatrix(M1,m1,n1);
	
	printf("Dimensions of the second: ");
	scanf("%d%d", &m2, &n2);
	float *M2 = (float*) malloc(m2 * n2 * sizeof(float));
	for(i = 0; i < m2; i++){
		for(j = 0; j < n2; j++){
			scanf("%f", &temp);
			M2[i * n2 + j] = temp;
		}
	}
	
	printf("========== Matrix 1 ==========\n");
	printMatrix(M1, m1, n1);
	printf("========== Matrix 2 ==========\n");
	printMatrix(M2, m2, n2);
	
	if(m1 == m2 && n1 == n2){
		printf("======= Sum of Matrices =======\n");
		float *SUM = (float*) malloc(m1 * n1 * sizeof(float));
		addMatrices(M1, M2, SUM, m1, n2);
		printMatrix(SUM, m2, n1);
	}
	
	if(n1 == m2){
		printf("===== Product of Matrices =====\n");
		float *PRODUCT = (float*) malloc(m1 * n2 * sizeof(float));
		multiplyMatrices(M1, M2, PRODUCT, m1, n2, n1);
		printMatrix(PRODUCT, m1, n2);
	}
	
	getch();
	return 0;
}

void printMatrix(float *M, int rows, int columns){
	int i, j;
	for(i = 0; i < rows; i++){
		for(j = 0; j < columns; j++){
			printf("%f\t", M[i * columns + j]);
		}
		printf("\n");
	}
}

void addMatrices(float *M1, float *M2, float *R, int rows, int columns){
	int i, j;
	for(i = 0; i < rows; i++){
		for(j = 0; j < columns; j++){
			R[i * columns + j] = M1[i * columns + j] + M2[i * columns + j];
		}
	}
}

void multiplyMatrices(float *M1, float *M2, float *R, int rows, int columns, int mid){
	int i, j, k;
	for(i = 0; i < rows; i++){
		for(j = 0; j < columns; j++){
			R[i * columns + j] = 0.0;
			for(k = 0; k < mid; k++){
				R[i * columns + j] += M1[i * mid + k] * M2[j + k * columns];
			}
		}
	}
}
