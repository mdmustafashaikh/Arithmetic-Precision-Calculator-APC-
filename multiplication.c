/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
			: tailR: Pointer to the last node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "apc.h"
#include <stdlib.h>
#include <stddef.h>

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR){
 
    if ((*head1 == NULL) || (*head2 == NULL)){
        return FAILURE;
    }
    if ((*head1)->data == 0 && (*head1)->next == NULL)
	 {
        Dlist *newnode = malloc(sizeof(Dlist));
        if (!newnode)
		{
			return FAILURE;
		}
        newnode->data = 0;
        newnode->prev = newnode->next = NULL;
        *headR = *tailR = newnode;
        return SUCCESS;
    }
    if ((*head2)->data == 0 && (*head2)->next == NULL)
	 {
        Dlist *newnode = malloc(sizeof(Dlist));
        if (!newnode)
		{
			return FAILURE;
		}
        newnode->data = 0;
        newnode->prev = newnode->next = NULL;
        *headR = *tailR = newnode;

        return SUCCESS;
    }

  
    int len1 = 0, len2 = 0;
    Dlist *curr1 = *head1, *curr2 = *head2;

    while (curr1) 
	{
		len1++;
		curr1 = curr1->next;
	}
    while (curr2)
	{
		len2++;
		curr2 = curr2->next;
	}
    int *product = calloc(len1 + len2, sizeof(int));
    if (!product) {
        return FAILURE;
    }
    int pos1 = 0;
    for (Dlist *n1 = *tail1; n1; n1 = n1->prev, pos1++) {
        int carry = 0;
        int pos2 = 0;
        for (Dlist *n2 = *tail2; n2; n2 = n2->prev, pos2++) {
            int mul = n1->data * n2->data + product[pos1 + pos2] + carry;
            product[pos1 + pos2] = mul % 10;
            carry = mul / 10;
        }
        if (carry){
            product[pos1 + pos2] += carry;
        }
    }

    int last = len1 + len2 - 1;
    while (last > 0 && product[last] == 0) 
    last--;
    for (int i = last; i >= 0; i--) {
        Dlist *newnode = malloc(sizeof(Dlist));
        if (!newnode) {
            free(product);
            return FAILURE;
        }
        newnode->data = product[i];
        newnode->prev = *tailR;
        newnode->next = NULL;

        if (*tailR){
            (*tailR)->next = newnode;
        }
        else{
            *headR = newnode;
        }
        *tailR = newnode;
    }

    free(product);
    return SUCCESS;
}
