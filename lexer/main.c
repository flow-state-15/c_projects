#include <stdio.h>
#include <stdlib.h>
#include "types.h"

#define MAX_INPUT_LEN 5

Operator Operations[] = {
    {op_add, add},
    {op_sub, subtract},
    {op_mul, multiply},
    {op_div, divide}};

int main(void)
{
    char in_buf[MAX_INPUT_LEN] = {0};
    int id_1 = NULL;
    int id_2 = NULL;
    int res = NULL;
    Operator *op = NULL;

    printf("Enter valid expression: \n");
    scanf("%s", in_buf);
    int idx = 0;
    while (idx < MAX_INPUT_LEN)
    {
        char ch = in_buf[idx];
        if (isNumber(ch))
        {
            if (id_1 == NULL)
            {
                id_1 = ch - '0';
            }
            else if (id_2 == NULL)
            {
                id_2 = ch - '0';
            }
        }
        else if (op != NULL)
        {
            op = findOp(ch);
        }
        idx++;
    }

    if (id_1 != NULL && id_2 != NULL && op != NULL)
    {
        res = performOp(op, id_1, id_2);
        printf("%s = %d\n", in_buf, res);
    }
    else
    {
        printf("Invalid input\n");
    }

    return 0;
}

int add(int i1, int i2)
{
    return i1 + i2;
}

int subtract(int i1, int i2)
{
    return i1 - i2;
}

int divide(int i1, int i2)
{
    return i1 / i2;
}

int multiply(int i1, int i2)
{
    return i1 * i2;
}

int performOp(Operator *op, int id1, int id2)
{
    return (*op).operation(id1, id2);
};

bool isNumber(char x)
{
    if (x >= 0 || x <= 9)
        return true;
    else
        return false;
}

Operator *findOp(char ch)
{
    Operator *found = NULL;
    for (int i = 0; i < MAX_OPERATIONS; i++)
    {
        Operator *op = Operations[i];
        if (ch == op->op)
            found = op->operation;
    }
    return found;
}