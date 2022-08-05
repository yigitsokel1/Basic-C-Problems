#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main(){
	
	int **matrix;
	int size;
	int i, j;
	srand(time(NULL));
	
	//Get size of matrix
	printf("Enter the size of the matrix(Square Matrix): ");
	scanf("%d", &size);
	
	//Allocate space for matrix in memory
	matrix = (int**)malloc(size*sizeof(int*));
	for(i=0; i<size; i++){
		matrix[i] = (int*)malloc(size*sizeof(int));
	}
	//Random values ??to the matrix
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			matrix[i][j] = 1 + rand() % 100;
		}
	}
	//Print Matrix on screen	
	printf("\nMatrix\n");
	for(i=0; i<size; i++){
		for(j=0; j<size; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	//Increases the number of rows and columns of the matrix dynamically
	matrix = (int**)realloc(matrix, sizeof(int*)*(size+1));
	for(i=0; i<size; i++){
		matrix[i] = (int*)realloc(matrix[i], sizeof(int)*(size+1));
		matrix[i][size] = 0;
	}
	matrix[i] = (int*)calloc((size+1),sizeof(int));
	
	//Sums values ??in row and column
	for(i=0; i<size;i++){
		for(j=0; j<size; j++){
			matrix[i][size] += matrix[i][j];
			matrix[size][i] += matrix[j][i];
		}
	}
	for(i=0; i<size; i++){
		matrix[size][size] += matrix[size][i];
		matrix[size][size] += matrix[i][size];
	}
	//Print Special Matrix on the screen
	printf("\nSpecial Matrix\n");
	for(i=0; i<size+1; i++){
		for(j=0; j<size+1; j++){
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
	
	//Free up memory space
	for(i=0; i<size+1; i++)
		free(matrix[i]);
	free(matrix);
	
	return 0;
}
