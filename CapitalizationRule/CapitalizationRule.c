#include<stdio.h>
#include<stdlib.h>
#define MAX 5000

int main(){
	char text[MAX];
	int i=0;
	
	//User is prompted to enter text
	printf("Input: ");
	gets(text);

	//First character check
	if(((97 <= text[i]) && (122 >= text[i]))){
			text[i] = text[i] - 32;
		}
	//If first character is space, edit the next character
	else if(text[i]==32){
		text[i+1] = text[i+1] - 32;
	}
	//editing characters after dot to end of text
	while(text[i] != '\0'){
		if(text[i] == 46 && ((97 <= text[i+1]) && (122 >= text[i+1]))){
			text[i+1] = text[i+1] - 32;
		}
		else if(text[i] == 46 && text[i+1] == 32){
			if(((97 <= text[i+2]) && (122 >= text[i+2]))){
				text[i+2] = text[i+2] - 32;
			}
		}
		i++;
	}
	
	printf("Output: %s\n", text);
	
	return 0;

	
}


