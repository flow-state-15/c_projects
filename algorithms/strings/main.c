#include <stdio.h>

char *reverse_string(char *str);
int len_string(char *str);

int main(void) {
    const char *test = "hello";
    printf("test: %s\n", test);
    printf("len: %d\n", len_string(test));
    return 0;
}

int len_string(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}
