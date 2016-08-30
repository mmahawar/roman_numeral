#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <errno.h>
#include <regex.h>        

#include "roman_number_calculator.h"
#include "roman_number_validator.h"

const int ROMAN_TABLE_SIZE = 13;

struct {
	int numericValue;
	char romanDigits[3];
} romanTable[] = { { 1000, "M" }, 
                   { 900, "CM" }, 
                   { 500, "D" }, 
                   { 400, "CD" }, 
                   { 100, "C" }, 
                   { 90, "XC" }, 
                   { 50, "L" }, 
                   { 40, "XL" }, 
                   { 10, "X" }, 
                   { 9, "IX" }, 
                   { 5, "V" }, 
                   { 4, "IV" }, 
                   { 1, "I" } };

int add(const char *firstOperand, const char *secondOperand, char *output) {
	
    if(! (validateOperand(firstOperand)))
    	return BAD_INPUT_PARAMETER;

	if(! (validateOperand(secondOperand)))
    	return BAD_INPUT_PARAMETER;
	
	int sum = toNumeric(firstOperand) + toNumeric(secondOperand);
    
    if(!validateResult(sum))
    	return BAD_RESULT;

   	toRoman(sum, output);
	
	return SUCCEEDED;
}

int substract(const char *firstOperand, const char *secondOperand,
		char *output) {

	if(! (validateOperand(firstOperand)))
    	return BAD_INPUT_PARAMETER;

	if(! (validateOperand(secondOperand)))
    	return BAD_INPUT_PARAMETER;
	
	int difference = toNumeric(firstOperand) - toNumeric(secondOperand);
	
	if(!validateResult(difference))
    	return BAD_RESULT;

	toRoman(difference, output);
	return SUCCEEDED;
}

void toRoman(int sum, char *output) {
	int roamnTableIndex = 0;
	while (sum) {
		roamnTableIndex = findClosetIndexInRomanTable(sum);
		while (sum >= romanTable[roamnTableIndex].numericValue) {
			strcat(output, romanTable[roamnTableIndex].romanDigits);
			sum -= romanTable[roamnTableIndex].numericValue;
		}
	}
}

int toNumericDigit(char romanDigit) {
	int valueInInt, index = 0;
    
	for (index = 0; index < ROMAN_TABLE_SIZE; ++index) {
		// filter elements which are single digit only
		if( strlen(romanTable[index].romanDigits) > 1){
			continue;
		} 
         
		if(romanDigit == romanTable[index].romanDigits[0]){
           valueInInt = romanTable[index].numericValue;
           break;
        }
	}
	return valueInInt;
}

int toNumeric(const char *operand) {
	int firstVal, secondVal = 0;
	int i = 0;
	int sum = 0;
	for (i = 0; i < strlen(operand);) {
		firstVal = toNumericDigit(operand[i]);
		secondVal = toNumericDigit(operand[i + 1]);

		if (secondVal > firstVal) {
			sum += (secondVal - firstVal);
			i += 2;
		} else {
			sum += firstVal;
			i += 1;
		}
	}
	return sum;
}

int findClosetIndexInRomanTable(int sum) {
	int indexOfRomanTable = 0;
	while (sum < romanTable[indexOfRomanTable].numericValue)
		indexOfRomanTable++;

	return indexOfRomanTable;
}