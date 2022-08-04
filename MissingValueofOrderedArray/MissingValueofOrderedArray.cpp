#include <stdio.h>
#define SIZE 10000

int main(int argc, char** argv) {
  	
        int A[SIZE], x, b;
        int i, n;   
        
		printf("Enter the number of elements of the array = ");
    	scanf("%d", &n);
                       
        for(i = 0; i < n; i++){
        printf("Enter the value of %d.index = ", i+1);
            scanf("%d", &A[i]);
	    }
	    x=0;
		b=1;
	    
		while(A[b] - A[x] == 1 && b <= n){
			x++;
			b++;
		}
		
		if((b == n) && (A[n-1]- A[n-2] == 1)){
			printf("No Missing Value!");
		}else{
			printf("Missing Value : %d ", A[x]+1);
		}	            
        
	return 0;

}
  	
