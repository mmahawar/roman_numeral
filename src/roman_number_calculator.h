#ifndef NUMERALS_H
#define NUMERALS_H
#include <stdbool.h>

#define NUL '\0'

extern const int MAX_LIMIT;

extern const int BAD_RESULT;
extern const int BAD_INPUT_PARAMETER;


extern const int MAX_LIMIT_FAILURE;
extern const int SUCCEEDED;

extern const int ROMAN_TABLE_SIZE;


int add(const char *firstOperand, const char *secondOperand, char *output);
int substract(const char *firstOperand, const char *secondOperand, char *output);

int toNumericDigit(char romanDigit);
int toNumeric(const char *operand);
void toRoman(int sum, char *output);
int findClosetIndexInRomanTable(int sum);

#endif
