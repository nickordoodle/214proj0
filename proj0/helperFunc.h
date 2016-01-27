/*(word token consists of an alphabetic character followed by any number of alphanumeric
characters. Some word tokens are “hi” “stufF” “ThinGs” “a1231” “C0MP14IN”
A decimal integer is a digit character followed by any number of digit characters: “12” “8” “2”
An octal integer is a '0' character followed by any number of octal digits (0-7).
A hexadecimal integer is “0x” (or “0X”) followed by any number of hexadecimal digits (0-9, af,
A-F).
A floating point*/

int isWord(char *wordToCheck);

int isDecimal(char *wordToCheck);

int isOctal(char *wordToCheck);

int isHex(char *wordToCheck);

int isFloat(char *wordToCheck);


