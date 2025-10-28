#include "apc.h"
#include <stdlib.h>
#include <stddef.h>


int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int negative = 0;
    int cmp = compare_lists(*head1, *head2);
    Dlist *temp1, *temp2;
    if (cmp < 0) {
        temp1 = *tail2;
        temp2 = *tail1;
        negative = 1;
    } else {
        temp1 = *tail1;
        temp2 = *tail2;
    }
    int borrow = 0;
    *headR = NULL;
    *tailR = NULL;
    while (temp1 != NULL || temp2 != NULL)
    {
        int digit1 = 0;
        int digit2 = 0;

        if (temp1 != NULL)
        {
            digit1 = temp1->data;
        }
        if (temp2 != NULL)
        {
            digit2 = temp2->data;
        }

        int diff = digit1 - borrow - digit2;

        if (diff < 0)
        {
            diff = diff + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        Dlist *newnode = malloc(sizeof(Dlist));
        if (newnode == NULL)
        {
            return -1;
        }
        newnode->data = diff;
        newnode->prev = NULL;
        newnode->next = *headR;

        if (*headR != NULL)
        {
            (*headR)->prev = newnode;
        }
        else
        {
            *tailR = newnode;
        }

        *headR = newnode;

        if (temp1 != NULL)
        {
            temp1 = temp1->prev;
        }
        if (temp2 != NULL)
        {
            temp2 = temp2->prev;
        }
    }
    while (*headR != NULL)
    {
        if ((*headR)->data != 0)   
            break;

        if ((*headR)->next == NULL) 
            break;

 
        Dlist *zero = *headR;
        *headR = zero->next;
        (*headR)->prev = NULL;
        free(zero);
    }

    return negative;
}
