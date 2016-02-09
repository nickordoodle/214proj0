/*
 * tokenizer.c
 *
 * Nicholas Scherer, nds63
 * Griffin Wood,  gbw15
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

typedef enum {WORD, DEC, HEX, FLOAT, OCTAL} token_type;


struct TokenizerT_ {

	char *inputString;
	int currIndex;
	int inputSize;

}; typedef struct TokenizerT_ TokenizerT;

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

	if( ts == NULL || *(ts[0]) == '\0'){
		return 0;
	
	}
	/* Make copies of tokenizer and its properties, initialize all to 0 */
	char *inputString = 0;
	int currIndex = 0;
	int inputSize = 0;
	TokenizerT *tokenizer = 0;

	/* Allocate memory for the tokenizer and its fields */
	inputString = (char *)malloc(sizeof(ts));
	tokenizer = malloc(sizeof(TokenizerT));

	/* Check NULL or empty string and free local variables and return NULL 
		if true, otherwise copy string */
	strcpy(inputString, ts);	
	inputSize = strlen(inputString);
	

	/* Set new tokenizer field values */
	tokenizer->inputString = inputString;
	tokenizer->currIndex = currIndex;
	tokenizer->inputSize = inputSize;
	
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

	free(tk->inputString);
	free(tk->currIndex);
	free(tk->inputSize);
	free(tk);
}

int isDelimiter (char c){
	switch (c){
		case ' ':
			return 1;
			break;
		case '\t':
			return 1;
			break;
		case '\v':
			return 1;
			break;
		case '\f':
			return 1;
			break;
		case '\n':
			return 1;
			break;
		case '\r':
			return 1;
			break;
		default:
			return 0;
			break;
	}
}

/* ( ) [ ]  ->
function array element structure member structure pointer
UNARY OPERATORS ---------------------------------------- RIGHT TO LEFT
* & - ! ~ ++ -- sizeof ( )
indirect address minus negate 1’s comp inc dec cast
BINARY OPERATORS --------- decreasing precedence ---------- LEFT TO RIGHT
* multiply / divide % modulus
+ add - subtract
>> shift right << shift left
< less than > greater than <= less or equal >= greater or equal
== equals != not equals
& bitwise and
^ bitwise exclusive or
| bitwise or
&& logical and || logical or
CONDITIONAL EXPRESSION ---------------------------------------- RIGHT TO LEFT
Condition ? true : false
ASSIGNMENT OPERATORS ---------------------------------------- RIGHT TO LEFT
- += -= *= /= %= >>= <<= &= ^= |= see BINARY OPERATORS
COMMA OPERATOR ---------------------------------------- LEFT TO RIGHT
, discards value of left expression */

int isOperator (char c){
	
	char *operatorsArray[25] = { '(', ')', '[', ']', '*', '&', '-', '!' }
	
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

int hasNextToken(TokenizerT *tk){
	
	char *inputString = tk->inputString;
	int nextIndex = tk->currIndex + 1;
	if(!tk || inputString[nextIndex] == '\0'){
		return 0;
	} 
	
	return 1;

}
char *TKGetNextToken( TokenizerT * tk ) {

	/*Build current token based on inputString and iterate
	  until delimiter found, new type, or end of array.
	  The BuildFunctions will take the tokenizer parameter and the newToken
	  string as arguments and finish iterating through until no more of their type is
       found.  Each new character that is still of the same type is added
       to the newToken String.*/
		
	char *inputString = tk->inputString;
	
	/* Increment tokenizer struct index and continue function.*/
	while(isDelimiter( inputString[tk->currIndex]) ){
		tk->currIndex++;
	}

	/* Allocate memory for new token, will reallocate later */
	char *newToken = malloc(sizeof(tk->inputString));
	newToken = 0;
	
	char currChar = *(inputString[tk->currIndex]);
	
	if(isalpha(currChar)){
		//BuildWord( TokenizerT *tk );
	} else if(currChar == 0) {
		if(strcmpi(tk->(currIndex*nextIndex == 'x' || *nextIndex == 'X'){
			//BuildHex( TokenizerT *tk);
		} else { 
			//BuildOctal( TokenizerT *tk);
		}

	} else if(isdigit(currChar)){
		//BuildDecimal(TokenizerT *tk);
	} else if(currChar == '.'){
		//BuildFloat( TokenizerT *tk);
	} else if(isOperator(currChar)){
		newToken = currChar;
	}
		
	/*add '\0' to end of array*/
	return 0;
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

	TokenizerT *tokenizer = TKCreate(argv[1]);

	/* Iterates loop until end of array */
	while( hasNextToken(tokenzier) ){
		TKGetNextToken(tokenizer);
	}
	
	TKDestroy(tokenizer);
	

}	