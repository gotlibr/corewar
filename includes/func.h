
#ifndef FUNC_H
# define FUNC_H
# define T_REG					1
# define T_DIR					2
# define T_IND					4
typedef struct			s_op
{
	char				*name;
	char				args_num;
	char				arg[3];
	char				opcode;
	int					cycles;
	int					codage;
	int					carry;
	int					lable_size;
}						t_op;

typedef struct			s_process
{
	char				player_id;
	unsigned char		*memory;
	unsigned char		*program_counter;
	int					carry;
	unsigned int		live_executions;
	struct s_process	*next;
}						t_process;

t_op    op_tab[17] =
{
		{"live", 1, {T_DIR}, 1, 10, 0, 0, 4},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 1, 0, 4},
		{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 1, 0, -1},
		{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 1, 0, -1},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 1, 0, -1},
		{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6, 1, 0, 4},
		{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6, 1, 0, 4},
		{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6, 1, 0, 4},
		{"zjmp", 1, {T_DIR}, 9, 20, 0, 1, 2},
		{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25, 1, 1, 2},
		{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25, 1, 1, 2},
		{"fork", 1, {T_DIR}, 12, 800, 0, 1, 2},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 1, 0, 4},
		{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50, 1, 1, 2},
		{"lfork", 1, {T_DIR}, 15, 1000, 0, 1, 2},
		{"aff", 1, {T_REG}, 16, 2, 1, 0, -1},
		{0, 0, {0}, 0, 0, 0, 0, 0, -1}
};

#endif