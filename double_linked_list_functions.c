#include "monty.h"

/**
 *add_dnodeint_end - add a note at the end of the doubly link list
 *@ahd: first position of linked list
 *@x: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **ahd, const int x)
{
	stack_t *tmpo, *ax;

	if (ahd == NULL)
		return (NULL);
	tmpo = malloc(sizeof(stack_t));
	if (!tmpo)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmpo->n = x;
	/*Careful with the first time*/
	if (*ahd == NULL)
	{
		tmpo->next = *ahd;
		tmpo->prev = NULL;
		*ahd = tmpo;
		return (*ahd);
	}
	ax = *ahd;
	while (ax->next)
		ax = ax->next;
	tmpo->next = ax->next;
	tmpo->prev = ax;
	ax->next = tmpo;
	return (ax->next);
}

/**
 *add_dnodeint - add a note at the begining of the doubly link list
 *@ahd: first position of linked list
 *@x: data to store
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **ahd, const int x)
{
	stack_t *tmpo;

	if (ahd == NULL)
		return (NULL);
	tmpo = malloc(sizeof(stack_t));
	if (!tmpo)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmpo->n = x;
	/*Careful with the first time*/
	if (*ahd == NULL)
	{
		tmpo->next = *ahd;
		tmpo->prev = NULL;
		*ahd = tmpo;
		return (*ahd);
	}
	(*ahd)->prev = tmpo;
	tmpo->next = (*ahd);
	tmpo->prev = NULL;
	*ahd = tmpo;
	return (*ahd);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @ahd: head of the list
 * Return: no return
 */
void free_dlistint(stack_t *ahd)
{
	stack_t *tmpo;

	while ((tmpo = ahd) != NULL)
	{
		ahd = ahd->next;
		free(tmpo);
	}
}
