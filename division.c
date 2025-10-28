#include "apc.h"
#include <stdlib.h>
#include <stddef.h>

void subtract_lists(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    int borrow = 0;
    while (temp2 != NULL)
    {
        int digit1 = temp1->data;
        int digit2 = temp2->data;
        int diff = digit1 - borrow - digit2;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        temp1->data = diff;
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }
    while (borrow && temp1)
    {
        int diff = temp1->data - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        temp1->data = diff;
        temp1 = temp1->prev;
    }

    while (*head1 && (*head1)->data == 0 && (*head1)->next)
    {
        Dlist *zero = *head1;
        *head1 = zero->next;
        (*head1)->prev = NULL;
        free(zero);
    }
}

Dlist* copy_list(Dlist *head, Dlist **tail)
{
    Dlist *newhead = NULL, *newtail = NULL;
    while (head)
    {
        Dlist *newnode = malloc(sizeof(Dlist));
        if (!newnode) return NULL;
        newnode->data = head->data;
        newnode->prev = newtail;
        newnode->next = NULL;
        if (newtail)
            newtail->next = newnode;
        else
            newhead = newnode;
        newtail = newnode;
        head = head->next;
    }
    if (tail) *tail = newtail;
    return newhead;
}

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR){
   
    if (*head2 == NULL || (*head2)->data == 0 && (*head2)->next == NULL){
        return FAILURE;
    }
    if (*head1 == NULL || (*head1)->data == 0 && (*head1)->next == NULL)
    {
        Dlist *newnode = malloc(sizeof(Dlist));
        if (!newnode) return FAILURE;
        newnode->data = 0;
        newnode->prev = newnode->next = NULL;
        *headR = *tailR = newnode;
        return SUCCESS;
    }

    Dlist *temp_head = copy_list(*head1, NULL);
    Dlist *temp_tail = NULL;
    Dlist *t = temp_head;
    while (t && t->next) t = t->next;
    temp_tail = t;

    int quotient = 0;
    while (compare_lists(temp_head, *head2) >= 0)
    {
        subtract_lists(&temp_head, &temp_tail, head2, tail2);
        quotient++;
    }

    Dlist *newnode = malloc(sizeof(Dlist));
    if (!newnode) {
     
        while (temp_head) {
            Dlist *next = temp_head->next;
            free(temp_head);
            temp_head = next;
        }
        return FAILURE;
    }
    newnode->data = quotient;
    newnode->prev = newnode->next = NULL;
    *headR = *tailR = newnode;

    while (temp_head) {
        Dlist *next = temp_head->next;
        free(temp_head);
        temp_head = next;
    }

    return SUCCESS;
}
