// #ifndef ARRAY_H_
// #define ARRAY_H_
// #include "log.h"
// #include <stdio.h>

// typedef enum
// {
//     SUCCESS = 0,
//     FAILURE
// } ArrayOpResult;

// typedef enum
// {
//     FIXED,
//     DYNAMIC
// } ArrayVariant;
// typedef struct
// {
//     int *elems;
//     size_t cap;
//     size_t length;
//     ArrayVariant variant;
// } Array;

// #define __ARRAY_EXTRACT_SIZE__(xs) xs, sizeof(xs) / sizeof(xs[0])
// #define __ARRAY_BIND_SIZE__(sz) ((int[sz]){0}), sz

// #define ARRAY_INIT(V, xs) array_init(V, __ARRAY_EXTRACT_SIZE__(xs));
// Array array_init(ArrayVariant v, int *, size_t);

// #define ARRAY_NEW(V, sz) array_new(V, __ARRAY_BIND_SIZE__(sz));
// Array array_new(ArrayVariant, int *, size_t);

// void array_log(const Array *);
// ArrayOpResult array_push(Array *, int);

// #ifdef ARRAY_IMPL
// void array_print(const Array *xs)
// {
//     TRACE_FUNCTION_NAME;
//     printf("{ ");
//     if (xs->length == 0)
//         printf("EMPTY");
//     else
//         for (size_t n = 0; n < xs->length; n++)
//         {
//             printf("%d%s", xs->elems[n], (n < xs->length - 1) ? ", " : "\0");
//         }
//     printf(" }\n");
// }

// Array array_new(ArrayVariant v,int *xs, size_t sz)
// {
//     return (Array){.cap = sz, .length = 0, .elems = xs, .variant = v};
// }

// Array array_init(ArrayVariant v, int *xs, size_t sz)
// {
//     return (Array){.cap = sz, .length = sz, .elems = xs, .variant = v};
// }

// ArrayOpResult array_push(Array *xs, int x)
// {   
//     if (xs->variant != FIXED) return FAILURE;
//     if (xs->length >= xs->cap)
//         return FAILURE;
//     xs->elems[xs->length++] = x;
//     return SUCCESS;
// }

// ArrayOpResult

// #endif // ARRAY_IMPL
// #endif // ARRAY_H_
