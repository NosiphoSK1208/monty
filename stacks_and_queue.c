#include "monty.h"

/**
 * _queue - sets format of data to queue(FIFI/LILO)
 * @dbl: head of linked list
 * @lnm: line number
 */
void _queue(stack_t **dbl, unsigned int lnm)
{
	(void)dbl;
	(void)lnm;

	vglo.lifo = 0;
}

/**
 * _stack - sets format of data to stack (LIFO/FILO)
 * @dbl: linked list head
 * @lnm: line number
 */
void _stack(stack_t **dbl, unsigned int lnm)
{
	(void)dbl;
	(void)lnm;

	vglo.lifo = 1;
}
