#include "monty.h"

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 * @dbl: head of the linked list
 * @lnm: line number;
 * Return: no return
 * info:The result is stored in 2nd value node from the top
 * and top value removed.
 */

void _mod(stack_t **dbl, unsigned int lnm)
{
	int p = 0;
	stack_t *xp = NULL;

	xp = *dbl;

	for (; xp != NULL; xp = xp->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", lnm);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*dbl)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", lnm);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	xp = (*dbl)->next;
	xp->n %= (*dbl)->n;
	_pop(dbl, lnm);
}
/**
 * _pstr - prints the string of the stack
 *
 * @dbl: head of the linked list
 * @lnm: line number;
 * Return: no return
 */
void _pstr(stack_t **dbl, unsigned int lnm)
{
	stack_t *xp;
	(void)lnm;

	xp = *dbl;

	while (xp && xp->n > 0 && xp->n < 128)
	{
		printf("%c", xp->n);
		xp = xp->next;
	}

	printf("\n");
}
/**
 * _pchar - print the char value of the first element
 *
 * @dbl: head of the linked list
 * @lnm: line number;
 * Return: no return
 */
void _pchar(stack_t **dbl, unsigned int lnm)
{
	if (dbl == NULL || *dbl == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", lnm);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*dbl)->n < 0 || (*dbl)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", lnm);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*dbl)->n);
}
