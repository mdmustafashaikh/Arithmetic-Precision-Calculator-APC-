#include "apc.h"
#include <stddef.h>
#include <stdlib.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR){
	Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;  
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry != 0)
    {
        int sum = carry;
        if (temp1 != NULL)
        {
            sum += temp1->data;
            temp1 = temp1->prev;
        }

        if (temp2 != NULL)
        {
            sum += temp2->data;
            temp2 = temp2->prev;
        }

        carry = sum / 10;
        sum = sum % 10;

        Dlist *newnode = malloc(sizeof(Dlist));
        if (newnode == NULL)
        {
            return FAILURE;
        }
        newnode->data = sum;
        newnode->prev = NULL;
        newnode->next = *headR;

        if (*headR != NULL){
            (*headR)->prev = newnode;
        }else{
            *tailR = newnode;
        }
        *headR = newnode;
    }
    return SUCCESS;
}
