#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <errno.h>
#include <regex.h>        

#include "roman_number_validator.h"
#include "roman_number_calculator.h"

const int MAX_LIMIT = 3999;
const int BAD_RESULT = -3;
const int BAD_INPUT_PARAMETER = -2;
const int MAX_LIMIT_FAILURE = -1;
const int SUCCEEDED = 0;

bool validateResult(int total){
	if(hasExceededRomanLimit(total))
   	 return false;

   	if(isResultNegative(total))
   		return false;

   	return true;
}

bool validateOperand(const char *operand){

   if(isNull(operand))
   	 return false;

   if(!isARomanNumber(operand))
   	 return false;

   if(hasExceededRomanLimit(toNumeric(operand)))
   	 return false;

   if(isResultNegative(toNumeric(operand)))
   		return false;

   return true;
}

bool isNull(const char *operand){
	return !operand;
}

bool hasExceededRomanLimit(const int operand){
	return operand > MAX_LIMIT;
}

bool isARomanNumber(const char *operand){
	regex_t regex;
	int reti;
	char msgbuf[100];

	/* Compile regular expression */
	reti = regcomp(&regex, "^[MDCLXVI]", 0);
	if (reti) {
	    fprintf(stderr, "Could not compile regex\n");
	    return false;
	}

	reti = regexec(&regex, operand, 0, NULL, 0);
	if (!reti) {
	    // Not sure what to do here...
	}
	else if (reti == REG_NOMATCH) {
		// confident that generating memomry leak here 
	    return false;
	}
	else {
	    regerror(reti, &regex, msgbuf, sizeof(msgbuf));
	    fprintf(stderr, "Regex match failed: %s\n", msgbuf);
	    // confident that generating memomry leak here 
	    return false;
	}
	/* Free memory allocated to the pattern buffer by regcomp() */
	regfree(&regex);

	return true;
}

bool isResultNegative(int number){
	return number <= 0;
}