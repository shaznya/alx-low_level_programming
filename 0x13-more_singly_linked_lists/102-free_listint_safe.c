#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

typedef struct listint_s {
    int n;
    struct listint_s *next;
} listint_t;

size_t free_listint_safe(listint_t **h);
void print_list(listint_t *head);

size_t free_listint_safe(listint_t **h) {
    size_t count = 0;
    listint_t *current = *h;
    listint_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        count++;
        current = next;
    }

    *h = NULL;
    return count;
}

void print_list(listint_t *head) {
    while (head != NULL) {
        printf("[%p] %d\n", (void *)head, head->n);
        head = head->next;
    }
}

int main() {
    
    listint_t *head = malloc(sizeof(listint_t));
    head->n = 0;
    head->next = malloc(sizeof(listint_t));
    head->next->n = 1;
    head->next->next = malloc(sizeof(listint_t));
    head->next->next->n = 2;
    head->next->next->next = NULL;

    
    printf("Before freeing:\n");
    print_list(head);

    
    size_t freed_count = free_listint_safe(&head);
    printf("Freed %zu nodes\n", freed_count);

    
    printf("After freeing:\n");
    print_list(head);

    return 0;
}

