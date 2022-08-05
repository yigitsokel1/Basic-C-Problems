#include<stdio.h>

int main(){
	int selection=0;
	int row, column;
	int i,j,zeroCount=0;
	int counter=0;
	int max=1;
	
	while(selection!=3){
		printf("\nMenu:\n(1) Sparse Matrix to Compressed Matrix\n(2) Compressed Matrix to Sparse Matrix\n(3) Exit\n");
		scanf("%d",&selection);
		if(selection==1){
			//Get informations of matrix			
			printf("\nEnter the dimensions of the matrix (Row, Column):");
			scanf("%d %d",&row,&column);
			int sparse[row][column];
			printf("\nEnter the elements of matrix\n");
			for(i=0;i<row;i++){
				for(j=0;j<column;j++){
					printf("Matrix[%d][%d]: ",i,j);
					scanf("%d",&sparse[i][j]);
				}
			}
			//Creating matrix for elements different from 0
			for(i=0;i<row;i++){
				for(j=0;j<column;j++){
					if(sparse[i][j]!=0){
						zeroCount++;
					}
				}
			}
			int compressed[zeroCount][3];
			
			//The values of the elements other than 0 are mapped to the created matrix.
			for(i=0;i<row;i++){
				for(j=0;j<column;j++){
					if(sparse[i][j]!=0){
						compressed[counter][0]=i;
						compressed[counter][1]=j;
						compressed[counter][2]=sparse[i][j];
						counter++;
					}
				}
			}
			//Print compressed matrix on the screen			
			printf("\nCompressed Matrix\n");
			printf("\nRow\tColumn\tValue");
			for(i=0;i<zeroCount;i++){
				printf("\n%d\t%d\t%d",compressed[i][0],compressed[i][1],compressed[i][2]);
			}
			printf("\n");
		}
		else if(selection==2){
			
			//Get information of matrix
			printf("How many non-0 elements are in the matrix (Number of rows in a compressed matrix)?\n");
			scanf("%d",&row);
			int compressed[row][3];
			printf("Row and Column starts at 0!!*\n");
			
			//The values of the elements other than 0 are mapped to the created matrix.
			for(i=0;i<row;i++){
				printf("Enter row, column and value for %d.element\n",i+1);
				scanf("%d %d %d",&compressed[i][0],&compressed[i][1],&compressed[i][2]);
			}
			//Determining the number of rows and columns of a sparse matrix
			printf("\nCompressed Matrix\n");
			for(i=0;i<row;i++){
				printf("\n%d\t%d\t%d",compressed[i][0],compressed[i][1],compressed[i][2]);
				if(compressed[i][0]>max){
					max=compressed[i][0];
				}
				else if(compressed[i][1]>max){
					max=compressed[i][1];
				}
			}
			int newSparse[max+1][max+1];
			for(i=0;i<max+1;i++){
				for(j=0;j<max+1;j++){
					newSparse[i][j]=0;
				}
			}
			//Elements are assigned to sparse matrix
			for(i=0;i<row;i++){
				newSparse[compressed[i][0]][compressed[i][1]]=compressed[i][2];
			}
			//Print the sparse matrix on the screen
			printf("\n\nSparse Matrix: \n\n");
			for(i=0;i<max+1;i++){
				for(j=0;j<max+1;j++){
					printf("%d ",newSparse[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}
		else if(selection==3){
			printf("Exit..\n");
		}
		else{
			printf("Wrong value! Try Again\n");
		}
		
	}
	return 0;
}
