#ifndef VALIDATORS_H
#define VALIDATORS_H

#include <stdbool.h>

#define NUL '\0'

extern const int MAX_LIMIT;
extern const int BAD_RESULT;
extern const int BAD_INPUT_PARAMETER;
extern const int MAX_LIMIT_FAILURE;
extern const int SUCCEEDED;

bool validateOperand(const char *operand);
bool validateResult(int total);

bool isNull(const char *operand);
bool hasExceededRomanLimit(const int operand);
bool notARomanNumber(const char *operand);
bool isARomanNumber(const char *operand);
bool isResultNegative(int number);

#endif
