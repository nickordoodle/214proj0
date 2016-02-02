/*
 * tokenizer.c
 *
 * Nicholas Scherer, nds63
 * Griffin Wood, 
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 * Input String will contain the whole input. CurrentIndex is what position the program
 * is in while iterating through the string.  delimPositions will be an array of indexes
 * that refer to the indices where a delimiter exists in the inputString.
 */

typedef enum {	WORD, DEC, HEX, FLOAT, OCTAL} token_type;


/* Token struct to keep program more modular, keep together its token string
   and its type of token.  Uses linked list format to keep track of 
   other tokens */
struct Token_ {

	char *string;
	token_type tokenType;
	Token *nextToken;
	Token *prevToken;
	
	
}; typedef struct Token_ Token;


struct TokenizerT_ {

	Token *head;
	char *inputString;
	int *currIndex;
	int *nextIndex;
	int *inputSize;

}; typedef struct TokenizerT_ TokenizerT;


/*Called when TKGetNextToken determines that a word has started.  Purpose of this
is to build the word until a new type of token is found, then we can return the
function */

char *createWordToken(TokenizerT *tk){
	
	int curr = tk->inputString[currIndex];

	while(isalpha(curr) || isdigit(curr)){
		

	}
}
/*
 * TKCreate creates a new TokenizerT object for a given token stream
 * (given as a string).
 * 
 * TKCreate should copy the arguments so that it is not dependent on
 * them staying immutable after returning.  (In the future, this may change
 * to increase efficiency.)
 *
 * If the function succeeds, it returns a non-NULL TokenizerT.
 * Else it returns NULL.
 *
 * You need to fill in this function as part of your implementation.
 */

TokenizerT *TKCreate( char * ts ) {

	/* Make copies of tokenizer and its properties, initialize all to 0 */
	Token *headCopy = 0;
	char *inputStringCopy = 0;
	int *currIndexCopy = 0;
	int *inputSizeCopy = 0;
	TokenizerT *tokenizer = 0;

	/* Allocate memory for the tokenizer and its fields */
	headCopy = malloc(sizeof(ts->head));
	inputStringCopy = (char *)malloc(sizeof(ts->inputString));
	currIndexCopy = (int *)malloc(sizeof(ts->currIndexCopy));
	inputSizeCopy = (int *)malloc(sizeof(ts->inputSize));
	tokenizer = malloc(sizeof(ts));

	/* check NULL or empty string and free local variables and return NULL 
		if true, otherwise copy string */
	if( ts == NULL || *(ts[0]) == '\0'){
		free(headCopy);
		free(inputStringCopy);
		free(currIndexCopy);
		free(inputSizeCopy);
		free(tokenizer);
		return NULL;
	} else {
		inputSizeCopy = strlen(ts);
		strncpy(inputStringCopy, ts, inputSizeCopy);	
	}

	/* Set new tokenizer field values */
	tokenizer->head = headCopy;
	tokenizer->inputString = inputStringCopy;
	tokenizer->currIndex = currIndexCopy;
	tokenizer->nextIndex = currIndexCopy + 1;
	tokenizer->inputSize = inputSizeCopy;
	
	/* If successful, give a tokenizer with initialized fields */
	return tokenizer;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * First, free all allocated properties/elements of the TokenizerT struct. 
 * Then free the pointer to the struct itself
 */

void TKDestroy( TokenizerT * tk ) {

	if(tk->head != NULL){	

		Token *temp = tk->head;

		while((temp = tk->head) != NULL){
			tk->head = tk->head->nextToken;
			free(temp);
		}
	}
	free(tk->inputString);
	free(tk->currIndex);
	free(tk->nextIndex);	
	free(tk->inputSize);
	free(tk);
}

/*
 * TKGetNextToken returns the next token from the token stream as a
 * character string.  Space for the returned token should be dynamically
 * allocated.  The caller is responsible for freeing the space once it is
 * no longer needed.
 *
 * If the function succeeds, it returns a C string (delimited by '\0')
 * containing the token.  Else it returns 0.
 *
 * Algorithm: If first token is character/letter, then we have a word always. 
 * Word, Hex, Octal, Dec, Float
 */

char *TKGetNextToken( TokenizerT * tk ) {

	/*Build current token based on inputString and iterate
	  until delimiter found, new type, or end of array.
	  The BuildFunctions will take the tokenizer parameter and the newToken
	  string as arguments and finish iterating through until no more of their type is
       found.  Each new character that is still of the same type is added
       to the newToken String.*/
	
	char *curr = tk->inputString[currIndex];

	/*Reached end of array and/or last index*/
	if(tk->*(inputString[currIndex]) == '\0' 	
					||
	   tk->currIndex == strlen(tk->inputString) - 1){
		return 0;
	
	}

	/*Check if current index is at a delimiter, if so, move on to next token*/
	if(isDelimiter(*curr)){
		currIndex++;
		TKGetNextToken(tk);

	}

	/*Allocate memory for new token, will reallocate later*/
	char *newToken = malloc(sizeof(tk->inputString));
	newToken = 0;

	
	//NOTE: might not need loop here
	//while (newToken){

		if(isalpha(*curr)){
			//BuildWord();
		} else if(*curr == 0) {
			if(*nextIndex == 'x' || *nextIndex == 'X'){
				//BuildHex();
			} else { 
				//BuildOctal();
			}

		} else if(isdigit(*curr)){
			//BuildDecimal();
		} else if(*curr == '.'){
			//BuildFloat();
		} else if(isOperator(*curr)){
			newToken = *curr;
		}
		
	//}
	/*add '\0' to end of array*/
	return 0;
}

/* Gives String value of enum tokentype */
const char* getTokenType(token_type tokenType) {

   switch (tokenType) {
      case WORD: return "word";
      case DEC: return "decimal";
      case HEX: return "hexidecimal";
      case FLOAT: return "float";
      case OCTAL: return "octal";
 
   }
}

/*used to print out tokens in left-right order*/
void printTokens(TokenizerT *tk){
	
	Token *curr = tk->head;

	/* List is not empty is the condition*/
	while(curr != NULL){

		/* Print current token and its type*/
		printf("%s", getTokenType(curr->tokenType));
		printf("%s", curr->string);

		/* Go to next token in linked list */
		curr = curr->nextToken;

		/* Start new line */
		printf("\n");
	}

	/*free each token from tkgetnexttoken after it is used*/
}

/*

 * main will have a string argument (in argv[1]).
 * The string argument contains the tokens.
 * Print out the tokens in the second string in left-to-right order.
 * Each token should be printed on a separate line.
 */


/*
 Token Examples: 1234ab is 2 tokens
			  12340b  is 2 tokens

		       12340x is 2 tokens (BE GREEDY IN CURRENT TOKEN)
			  dddddN  --> decimals and numbers

			0 8 can be bad token or two numbers
			
			01234 is definitely octal

			0x213 is hex

			0129820x123 is best interpreted as decimal and a word


	JUST SHOW EVERYTHING WITH DOCUMENTATION AND MAKE ASSUMPTIONS/RULES
	BASED ON SMALL AMBIGUITIES.  "ROOM FOR INTERPRETATION"
*/
int main(int argc, char **argv) {

	TokenizerT *tokenizer = 0;

	/*NO ARGUMENTS, EXIT PROGRAM*/
	if(argc == 0){
		return 0;
	}	

	TokenizerT = TKCreate(argv[1]);

	/* Cycle through getNextTokens here */

	printTokens(tokenizer);
}	
