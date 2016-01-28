/*
 * tokenizer.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "helperFunc.h" 
#include "helperFunc.c"


/*
 * Tokenizer type.  You need to fill in the type as part of your implementation.
 * Input String will contain the whole input. CurrentIndex is what position the program
 * is in while iterating through the string.  delimPositions will be an array of indexes
 * that refer to the indices where a delimiter exists in the inputString.
 */


struct TokenizerT_ {

	char *inputString;
	int *currIndex;
	char *delimPositions;
	
};

typedef struct TokenizerT_ TokenizerT;

struct Token_ {

	char *string;
	
	
};

typedef struct Token_ Token;


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

	

  return NULL;
}

/*
 * TKDestroy destroys a TokenizerT object.  It should free all dynamically
 * allocated memory that is part of the object being destroyed.
 *
 * First, free all allocated properties/elements of the TokenizerT struct. 
 * Then free the pointer to the struct itself
 */

void TKDestroy( TokenizerT * tk ) {

	free(tk->inputString);
	free(tk->currIndex);
	free(tk->delimPositions);
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
	  until delimiter found, new type, or end of array*/

	while (isDelimiter == 0 || tk->inputString != '\0'){


		
	}
	/*add '\0' to end of array*/
	return 0;
}


/*used to print out tokens in left-right order*/
void printTokens(){
	
	/*list is not empty is the condition*/
	while(TKGetNextToken){

		
		/*increment list*/

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


	/*NO ARGUMENTS, EXIT PROGRAM*/
	if(argc == 0){
		return 0;
	}	
	
	

 	return 0;
}	
