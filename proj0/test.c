
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct TokenizerT_ {

	char *inputString;
	int *currIndex;
	int inputSize;

}; typedef struct TokenizerT_ TokenizerT;

int main(int argc, char **argv) {

	//char *operatorsArray[20] = {'(', ')', '[', ']', '*', '&', '-', '!'};

	
	TokenizerT *tk = malloc(sizeof(TokenizerT));
	tk->inputString = malloc(sizeof(char *));


	int *currIndex = tk->currIndex;	
	int number = 4;
	tk->inputString = "abcdefg";
	currIndex = &number;
	
	(*currIndex)++;
	

	char *ptr = tk->inputString;
	
	int result = strcmp(*(ptr), 'x');
	printf("%d\n", result);


	return 0;

}	
