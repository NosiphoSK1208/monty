#include "monty.h"

/**
 * _rotl - rotates 1st element to the bottom and 2nd to the top
 * @dbl: linked list head
 * @lnm: line nummber
 */
void _rotl(stack_t **dbl, unsigned int lnm)
{
	stack_t *xp = NULL;
	stack_t *xpb = NULL;
	(void)lnm;

	if (*dbl == NULL)
		return;

	if ((*dbl)->next == NULL)
		return;

	xp = (*dbl)->next;
	xpb = *dbl;

	for (; xpb->next != NULL; xpb = xpb->next)
		;

	xp->prev = NULL;
	xpb->next = *dbl;
	(*dbl)->next = NULL;
	(*dbl)->prev = xpb;
	*dbl = xp;
}

/**
 * _rotr - reverse stack
 * @dbl: linked list head
 * @lnm: line number
 */
void _rotr(stack_t **dbl, unsigned int lnm)
{
	stack_t *ux = NULL;
	(void)lnm;

	if (*dbl == NULL)
		return;

	if ((*dbl)->next == NULL)
		return;

	ux = *dbl;

	for (; ux->next != NULL; ux = ux->next)
		;

	ux->prev->next = NULL;
	ux->next = *dbl;
	ux->prev = NULL;
	(*dbl)->prev = ux;
	*dbl = ux;
}

