#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

int compare_lists(Dlist *head1, Dlist *head2)
{
    int len1 = 0, len2 = 0;
    Dlist *t1 = head1, *t2 = head2;
    while (t1) { 
        len1++; t1 = t1->next; 
    }
    while (t2) { 
        len2++; t2 = t2->next; 
    }
    if (len1 > len2) 
    return 1;
    if (len1 < len2)
     return -1;
    t1 = head1; t2 = head2;
    while (t1 && t2) {
        if (t1->data > t2->data) 
        return 1;
        if (t1->data < t2->data) 
        return -1;
        t1 = t1->next; t2 = t2->next;
    }
    return 0;
}


int string_to_list(const char *str, Dlist **head, Dlist **tail)
{
    if (str == NULL)  
        return FAILURE;

    *head = NULL;    
    *tail = NULL;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return FAILURE;

        data_t digit = str[i] - '0';

        Dlist *newnode = (Dlist *)malloc(sizeof(Dlist));
        if (newnode == NULL)
            return FAILURE;

        newnode->data = digit;
        newnode->next = NULL;
        newnode->prev = *tail;   

        if (*tail != NULL)
        {
            (*tail)->next = newnode;
        }
        else
        {
            *head = newnode;
        }
        *tail = newnode;
    }
    return SUCCESS;
}
void display_list(Dlist *head)
{
    Dlist *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}
