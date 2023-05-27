#include "monty.h"
void (*f)(stack_t **stack, unsigned int lnumber);
global_t vglo;
/**
 * free_vglo - frees the global variables
 *
 * Return: no return
 */
void free_vglo(void)
{
	free_dlistint(vglo.head);
	free(vglo.buffer);
	fclose(vglo.fd);
}

/**
 * start_vglo - initializes the global variables
 *
 * @f_des: file descriptor
 * Return: no return
 */
void start_vglo(FILE *f_des)
{
	vglo.lifo = 1;
	vglo.cont = 1;
	vglo.arg = NULL;
	vglo.head = NULL;
	vglo.fd = f_des;
	vglo.buffer = NULL;
}

/**
 * check_input - checks if the file exists and if the file can
 * be opened
 *
 * @agc: argument count
 * @agv: argument vector
 * Return: file struct
 */
FILE *check_input(int agc, char *agv[])
{
	FILE *f_des;

	if (agc == 1 || agc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	f_des = fopen(agv[1], "r");

	if (f_des == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", agv[1]);
		exit(EXIT_FAILURE);
	}

	return (f_des);
}

/**
 * main - Entry point
 *
 * @agc: argument count
 * @agv: argument vector
 * Return: 0 on success
 */
int main(int agc, char *agv[])
{
	FILE *f_des;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	f_des = check_input(agc, agv);
	start_vglo(f_des);
	nlines = getline(&vglo.buffer, &size, f_des);
	while (nlines != -1)
	{
		lines[0] = _strtoky(vglo.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", vglo.cont);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_vglo();
				exit(EXIT_FAILURE);
			}
			vglo.arg = _strtoky(NULL, " \t\n");
			f(&vglo.head, vglo.cont);
		}
		nlines = getline(&vglo.buffer, &size, f_des);
		vglo.cont++;
	}

	free_vglo();

	return (0);
}
