#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main(){

	int randomNumber, digit, i, pos, neg, j, count, control = 0;
	int number = 0, random[5], numberDig[5];
	
	//Random number is generated
	
	while(control == 0){
		srand(time(NULL));
		randomNumber = 1000 + rand() % 9000;
		digit = randomNumber;
		control = 1;
		//Digits are kept in array
		i=3;
		while(i >= 0){
			random[i] = digit % 10;
			digit = digit - random[i];
			digit = digit / 10;
			i--;
		}
		for(i=0;i<4;i++){
			for(j=i+1;j<4;j++){
				if(random[i] == random[j])
					control = 0;
			}
		}
	}
	
	printf("Number : %d\n", randomNumber);

	while(number != randomNumber){
		pos = 0;
		neg = 0;
		printf("Enter guess = ");
		scanf("%d",&number);
		count++;
		digit = number;
		i = 3;
		while(i >= 0){
		numberDig[i] = digit % 10;
		digit = digit / 10;
		i--;
		}
		for(i = 0; i<4; i++){
			for(j = 0; j<4; j++){
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
	 
	printf("Congrats :) You did it! number of total predictions: %d\n", count);
	
	return 0;

}
