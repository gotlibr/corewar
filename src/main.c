#include <stdio.h>
#include "../includes/func.h"

void	live(t_process *proc)
{
	if (proc->program_counter + 4 == proc->player_id)
		proc->live_executions += 1;
	proc->program_counter = proc->program_counter->next;
}

t_process	*newproc()
{
	t_process *proc;

	proc = (t_process *)ft_memalloc(sizeof(t_process));
	proc->carry = 0;
	proc->live_executions = 0;
	proc->memory = (unsigned char *)ft_memalloc(sizeof(unsigned char) * REG_NUMBER);
	proc->next = NULL;
	return (proc);
}

void	fork(t_process *proc)
{
	t_process *head;
	t_process *new;

	new = (t_process *)ft_memalloc(sizeof(t_process));
	new->carry = proc->carry;
	new->player_id = proc->player_id;
	new->program_counter = (proc->program_counter + 1) % IDX_MOD;
	new->live_executions = proc->live_executions;
	new->memory = proc->memory;
	head = proc;
	while (proc->next)
		proc = proc->next;
	proc->next = new;
	proc = head;
}

unsigned char *get_adr(unsigned char *adr, int ind)
{
	int moved;
	int delta;

	moved = 0;
	delta = (ind >= 0) ? 1 : -1;
	while (moved != ind)
	{
		if (adr + delta)
			adr += delta;
		else
			adr += (delta > 0) ? -MEM_SIZE : MEM_SIZE;
		moved += delta;
	}
	return (adr);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}