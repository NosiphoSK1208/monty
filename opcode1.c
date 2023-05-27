#include "monty.h"

/**
 * _add - Adds the top two values of a stack_t linked list.
 * @dbl: hdn of the linked list
 * @lnm: line number
 * Description: The result is stored in the second value node
 * from the top and the top value  is removed.
 */
void _add(stack_t **dbl, unsigned int lnm)
{
	int p = 0;
	stack_t *xp = NULL;

	xp = *dbl;

	for (; xp != NULL; xp = xp->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", lnm);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	xp = (*dbl)->next;
	xp->n += (*dbl)->n;
	_pop(dbl, lnm);
}

/**
 * _nop - doesn't do anything
 * @dbl: linked list hdn
 * @lnm: line number
 */
void _nop(stack_t **dbl, unsigned int lnm)
{
	(void)dbl;
	(void)lnm;
}
/**
 * _sub - Subtracts 2nd value from the top of stack_t linked list by top value.
 * @hdn: the hdn node
 * @lnm: the line number
 * Description: The result is stored in the second value node
 * from the top and the top value is removed.
 */

void _sub(stack_t **hdn, unsigned int lnm)
{
	int p = 0;
	stack_t *a_curr;

	a_curr = *hdn;

	for (; a_curr != NULL; a_curr = a_curr->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", lnm);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	a_curr = (*hdn)->next;
	a_curr->n -= (*hdn)->n;
	_pop(hdn, lnm);
}

/**
 *_div -Divides 2nd value from the top of stack_t linkedlist by the top value.
 * @dbl: hdn of the linked list
 * @lnm: line number;
 * Return: no return
 */

void _div(stack_t **dbl, unsigned int lnm)
{
	int p = 0;
	stack_t *xp = NULL;

	xp = *dbl;

	for (; xp != NULL; xp = xp->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", lnm);
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
	xp->n /= (*dbl)->n;
	_pop(dbl, lnm);
}

/**
 *_mul -Multiplies 2nd value from the top of stack_t linked list by top value.
 * @hdn: the hdn node
 * @lnm: the line number
 * info:The result is stored in the 2nd value node
 * from the top and top value removed.
 */

void _mul(stack_t **hdn, unsigned int lnm)
{
	int p = 0;
	stack_t *a_curr;

	a_curr = *hdn;

	for (; a_curr != NULL; a_curr = a_curr->next, p++)
		;

	if (p < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", lnm);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	a_curr = (*hdn)->next;
	a_curr->n *= (*hdn)->n;
	_pop(hdn, lnm);
}
