#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    INT,
    CHAR,
    FLOAT,
} ValueType;

typedef struct Array
{
    ValueType type;
    size_t size;
    void *array;
    struct Array * (*fill)(struct Array *, void *, size_t);
    void (*print)(struct Array *);
} Array;

void genericPrint(ValueType type)
{
    switch (type)
    {
    case INT:
        printf("value type INT: %d\n", type);
        break;
    case CHAR:
        printf("value type CHAR: %d\n", type);
        break;
    case FLOAT:
        printf("value type FLOAT: %d\n", type);
        break;
    default:
        printf("value type default case\n");
        break;
    }
}

void printArray(Array *arr)
{
    printf("printing arr: [ ");
    size_t i = 0;
    while (i < arr->size)
    {
        switch (arr->type)
        {
        case INT:
        {
            int *intArr = (int *)arr->array;
            printf("%d, ", intArr[i]);
            break;
        }
        case CHAR:
        {
            char *charArr = (char *)arr->array;
            printf("%c, ", charArr[i]);
            break;
        }
        case FLOAT:
        {
            float *floatArr = (float *)arr->array;
            printf("%f, ", floatArr[i]);
            break;
        }
        default:
            printf("printArray default case\n");
            break;
        }
        i++;
    }
    printf("]\n");
}

Array *fill_array(Array *xs, void *elements, size_t target_size)
{
    // todo: memcpy only works for flattened data structures?
    if (xs->size != target_size) {
        printf("fill_array target size invalid\n");
        return NULL;
    }
    memcpy(xs->array, elements, xs->size);
    return xs;
}

Array *new_array(ValueType type, size_t size)
{
    Array *arr = (Array *)malloc(sizeof(Array));
    if (arr == NULL)
    {
        printf("malloc failure for Array.\n");
        return NULL;
    }

    arr->type = type;
    arr->size = size;
    arr->fill = fill_array;
    arr->print = printArray;

    switch (arr->type)
    {
    case INT:
    {
        arr->array = (int *)malloc(sizeof(int) * size);
        break;
    }
    case CHAR:
    {
        arr->array = (char *)malloc(sizeof(char) * size);
        break;
    }
    case FLOAT:
    {
        arr->array = (float *)malloc(sizeof(float) * size);
        break;
    }
    default:
        printf("Invalid type field for Array type\n");
        return NULL;
    }

    if (arr->array == NULL)
    {
        printf("malloc failure for array.\n");
        return NULL;
    }
    return arr;
}

int main(void)
{
    // Array *xs = new_array(CHAR, 5);
    // xs->print(xs);
    // xs->fill(xs, (char[]){'h', 'e', 'l', 'l', 'o'}, 5);
    // xs->print(xs);

    // free(xs->array);
    // free(xs);
    // char c;
    // printf("press key for code: \n");
    // scanf("%s", &c);
    // printf("key input -> %s\n", c);
    char  number;

		printf("Type in a number \n");
		scanf("%d", &number);
		printf("The number you typed was %d\n", number);
    return 0;
}
