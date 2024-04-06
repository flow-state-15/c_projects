#include "stdint.h"

#define ARRAY_IMPL // header-only library
#include "array.h"

int main(void)
{
    printf("sizeof array literl: %zu\n", sizeof((int64_t[]){1, 2, 3}));

    Array xs = ARRAY_INIT(FIXED, ((int[]){1, 2, 3, 4, 5}))
        array_print(&xs);
    Array ys = ARRAY_NEW(FIXED, 10)
        array_print(&ys);

    return 0;
}
