#include <stdbool.h>

#ifndef MAX_INPUT_LEN
#define MAX_INPUT_LEN 3
#endif // MAX_INPUT_LEN
#ifndef MAX_OPERATIONS
#define MAX_OPERATIONS 4
#endif // MAX_OPERATIONS

#ifndef TYPES_H
#define TYPES_H

enum ValidOperator {
    op_add = '+',
    op_sub = '-',
    op_mul = '*',
    op_div = '/',
};

typedef struct Operator
{
    ValidOperator op;
    int (*operation)(int, int);
} Operator;

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);
bool isNumber(char);
int performOp(Operator, int, int);
Operator *findOp(char);

#endif // TYPES_H