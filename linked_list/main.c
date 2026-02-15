#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    // Memory allocation
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    if (!head || !second || !third)
    {
        printf("Insufficient memory!");
        return 1;
    }

    head->value = 7;
    head->next = second;

    second->value = 3;
    second->next = third;

    third->value = 12;
    third->next = NULL;

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d | next address: %d", temp->value, temp->next);
        temp = temp->next;
    }
    printf("\nNULL\n");

    temp = head;
    while (temp != NULL)
    {
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }

    printf("Freed memory!");

    return 0;
}