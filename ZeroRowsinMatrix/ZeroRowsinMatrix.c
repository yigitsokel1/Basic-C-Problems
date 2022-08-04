#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int main(){
	
	int i, j;
	int n,m, control, count=0;;
	int matrix[SIZE][SIZE];
	int empty[SIZE];
	
	//Get the information of the matrix
	printf("Enter the number of rows and then columns of the matrix:");
	scanf("%d %d",&n,&m);
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("Matrix[%d][%d](Enter 0 or 1)=",i+1,j+1);
			scanf("%d",&matrix[i][j]);
		}
	}
	
	//Print the matrix on the screen
	printf("\nInput N=%d M=%d\n",n,m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t",matrix[i][j]);
		}
		printf("\n");
	}
	
	//Detect which rows consist of 0
	i=0;
	while(i<n){
		control = 0;
		for(j=0;j<m;j++){
			if(matrix[i][j]==1){
				control = 1;
			}
		}
		if(control == 0)
			empty[count++] = i+1;
		i++;	
	}
	
	//Print the rows consist of 0
	printf("\nOutput:");
	for(i=0;i<count-1;i++){
		printf("%d,",empty[i]);
	}
	printf("%d",empty[i]);
	
	return 0;
	
}
