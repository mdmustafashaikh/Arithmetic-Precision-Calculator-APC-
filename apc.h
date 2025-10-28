#ifndef APC_H
#define APC_H

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;
typedef struct node
{
    struct node *prev;
    data_t data;
    struct node *next;
} Dlist;

int insert_at_end(Dlist **head, Dlist **tail, data_t data);

void display_list(Dlist *head);

void print_list(Dlist *head);

int addition(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

int subtraction(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

int multiplication(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

int division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);

int string_to_list(const char *str, Dlist **head, Dlist **tail);

int compare_lists(Dlist *head1, Dlist *head2);

void subtract_lists(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);

Dlist* copy_list(Dlist *head, Dlist **tail);

#endif
