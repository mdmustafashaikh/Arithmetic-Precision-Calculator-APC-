/************************************************************
 * Name        : Md Mustafa
 * Roll Number : 25008_052
 * File        : main.c
 * Purpose     : Driver function for big integer operations
 ************************************************************/
/**************************************************************************************************************************************************************
 * Title       : main function (Driver function)
 * Description : This function is used as the driver function for all big integer operations
\ ***************************************************************************************************************************************************************/

#include <stdio.h>
#include "apc.h"
#include <stdlib.h>

int printline();
int main(int argc, char *argv[])
{
    printline();
	printf("\t\t   Welcome to the Large Number Calculator\n");
	printline();

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
    char operator;

    if (argc != 4)
    {
        printf("Should must be : %s  operand1 <operator> <operand2>\n", argv[0]);
        return FAILURE;
    }
    if (argv[2][1] != '\0' || (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != '/'))
    {
        printf("Error: Operator must be a single character (+, -, x, /)\n");
        return FAILURE;
    }

    operator = argv[2][0];

    if (string_to_list(argv[1], &head1, &tail1) == FAILURE || string_to_list(argv[3], &head2, &tail2) == FAILURE)
    {
        printf("Error: Failed to convert input to list\n");
        return FAILURE;
    }

    switch (operator)
    {
        case '+':
            if (addition(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
            {
                printf("\t\t\t  Addition successfull\n");
                printline();
                printf("Result: ");
                display_list(headR);
                printf("\n");
                 printline();
            }
            break;
        case '-':
        {
            int neg = subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            if (neg == -1)
            {
                printf("Error in subtraction\n");
                return FAILURE;
            }
            printf("\t\t\t  Subtraction successfull\n");
			printline();
            printf("Result: ");
            if (neg == 1)
                printf("-");
            display_list(headR);
            printf("\n");
             printline();
        }
            break;
        case 'x':
            if (multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR) == SUCCESS)
            {
                printf("\t\t\t  Multiplication successfull\n");
			    printline();
                printf("Result: ");
                display_list(headR);
                printf("\n");
                printline();
            }
            break;
        case '/':
        {
            int div_status = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
            if (div_status == FAILURE)
            {
                printf("Error: Division by zero is not allowed\n");
                return FAILURE;
            }
            printf("\t\t\t  Division successfull\n");
			printline();
            printf("Result: ");
            display_list(headR);
            printf("\n");
            printline();
        }
            break;
        default:
            printf("Invalid operator: %c\n", operator);
            return FAILURE;
    }

    return SUCCESS;
}

int printline() {
	printf("=============================================================================\n");
}
