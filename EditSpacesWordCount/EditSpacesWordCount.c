#include<stdio.h>
#include<stdlib.h>
#define MAX 5000

int main(){
	FILE *fp;
	char text[MAX], editedText[MAX];
	int i=0, j=0, count=1;
	
	//Open File
	if((fp = fopen ("question.txt", "r")) == NULL){
		printf("File open error!");
		return -1;
	}
	
	//Assigns text from file to variable
	fgets(text, MAX-1, fp);
	printf("%s\n", text);
	

	//Removes extra spaces and edits text
	while(text[i] != '\0'){
		if((text[i] == 32) && (text[i+1] == 32)){
			i++;
		}
		else if((text[i] == 32) && (text[i+1] == '\0')){
			i++;
		}
		else{
			editedText[j] = text[i];
			i++;
			j++;
		}
	}
	
	//Calculates how many words are in the text
	i=0;
	while(editedText[i] != '\0'){
		if(editedText[i] == 32 && ((97 <= editedText[i+1]) && (122 >= editedText[i+1]))){
			count++;
		}
		i++;
	}
	printf("\nWord count = %d\n", count);
	printf("%s\n", editedText);
	
	return 0;
	
}


