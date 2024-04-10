#include <stdio.h>

typedef struct
{
    int *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct
{
    Node *head;
    size_t length;
} LinkedList;

LinkedList list_create(void) {
    LinkedList ll = { .head = NULL };
    return ll;
}

#define ADD_NODE(list, nn) \

void *add_node() {

}

int main(void)
{
    LinkedList ll = list_create();
    Node nn = { .data = 1, .next = NULL, .prev = NULL };

    if (ll.head) ll.head = &nn;

    return 0;
}
