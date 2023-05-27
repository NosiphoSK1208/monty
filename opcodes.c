#include "monty.h"
/**
 * _push - pushes an element to the stack
 *
 * @dbl: head of the linked list
 * @lnm: line number
 * Return: no return
 */
void _push(stack_t **dbl, unsigned int lnm)
{
	int k, c;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", lnm);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (c = 0; vglo.arg[c] != '\0'; c++)
	{
		if (!isdigit(vglo.arg[c]) && vglo.arg[c] != '-')
		{
			dprintf(2, "L%u: ", lnm);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	k = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(dbl, k);
	else
		add_dnodeint_end(dbl, k);
}

/**
 * _pall - prints all values on the stack
 *
 * @dbl: head of the linked list
 * @lnm: line numbers
 * Return: no return
 */
void _pall(stack_t **dbl, unsigned int lnm)
{
	stack_t *xp;
	(void)lnm;

	xp = *dbl;

	while (xp)
	{
		printf("%d\n", xp->n);
		xp = xp->next;
	}
}


/**
 * _pint - prints the value at the top of the stack
 *
 * @dbl: head of the linked list
 * @lnm: line number
 * Return: no return
 */
void _pint(stack_t **dbl, unsigned int lnm)
{
	(void)lnm;

	if (*dbl == NULL)
	{
		dprintf(2, "L%u: ", lnm);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*dbl)->n);
}

/**
 * _pop - removes the top element of the stack
 *
 * @dbl: head of the linked list
 * @lnm: line number
 * Return: no return
 */
void _pop(stack_t **dbl, unsigned int lnm)
{
	stack_t *xp;

	if (dbl == NULL || *dbl == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", lnm);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	xp = *dbl;
	*dbl = (*dbl)->next;
	free(xp);
}


/**
 * _swap - swaps the top two elements of the stack
 *
 * @dbl: head of the linked list
 * @lnm: line number
 * Return: no return
 */
void _swap(stack_t **dbl, unsigned int lnm)
{
	int b = 0;
	stack_t *xp = NULL;

	xp = *dbl;

	for (; xp != NULL; xp = xp->next, b++)
		;

	if (b < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", lnm);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	xp = *dbl;
	*dbl = (*dbl)->next;
	xp->next = (*dbl)->next;
	xp->prev = *dbl;
	(*dbl)->next = xp;
	(*dbl)->prev = NULL;
}
