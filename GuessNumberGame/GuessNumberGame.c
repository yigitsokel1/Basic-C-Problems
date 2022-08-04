#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(){

	int randomNumber, digit, i=4, pos, neg, j;
	int number = 0, random[5], numberDig[5];
	
	//Random number is generated
	srand(time(NULL));
	randomNumber = 3000 + rand() % 1000;
	digit = randomNumber;
	
	//Digits are kept in array
	while(i  > 0){
		random[i] = digit % 10;
		digit = digit - random[i];
		digit = digit / 10;
		i--;
	}
	
	
	printf("Number : %d\n", randomNumber);
	

	while(number != randomNumber){
		pos = 0;
		neg = 0;
		printf("Enter guess = ");
		scanf("%d",&number);
		digit = number;
		i = 4;
		while(i > 0){
		numberDig[i] = digit % 10;
		digit = digit / 10;
		i--;
		}
		for(i = 1; i<5; i++){
			for(j = 1; j<5; j++){
				if(random[i]==numberDig[j]){
					if(i == j)
						pos++;
					else
						neg++;
				}
			}
		}
		printf("+%d -- -%d\n", pos, neg);
	}
	 
	printf("Correct result!!\n");
	
	return 0;

}
