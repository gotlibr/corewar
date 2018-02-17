#include <stdio.h>

void	live(t_process *proc)
{
	if (proc->program_counter + 4 == proc->player_id)
		proc->live_executions += 1;
	proc->program_counter = proc->program_counter->next;
}

unsigned char *get_adr(unsigned char *adr, int ind)
{
	int moved;
	int delta;
	int meml;

	moved = 0;
	delta = (ind >= 0) ? 1 : -1;
	while (moved != ind)
	{
		if (adr + delta)
			adr += delta;
		else
			adr += (delta > 0) ? -meml : meml;
		moved += delta;
	}
	return (adr);
}

int main() {
    printf("Hello, World!\n");
    return 0;
}