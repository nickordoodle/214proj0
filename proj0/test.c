
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct TokenizerT_ {

	char *inputString;
	int currIndex;
	int inputSize;

}; typedef struct TokenizerT_ TokenizerT;

int main(int argc, char **argv) {

	char *operatorsArray[20] = {'(', ')', '[', ']', '*', '&', '-', '!'};
		
	TokenizerT *tk = malloc(sizeof(TokenizerT));
	tk->inputString = "abcdefg";
	tk->currIndex = 4;
	int startIndex = 1
	char *newString = 0;
	
	char *inputString = tk->inputString;
	char *currentChar = inputString[tk->currIndex];
	
	printf("%c\n", currentChar);
	
	strncpy( newString, inputString[currIndex] + startIndex, (currIndex - startIndex))	
	printf("%s\n", newString);
	
	tk->currIndex = tk->currIndex + 1;
	printf("%c\n", currentChar);

	return 0;

}	
