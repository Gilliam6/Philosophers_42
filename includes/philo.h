#ifndef PHILO_H
# define PHILO_H
# include "../includes/libft.h"
# include <pthread.h>
typedef struct s_timing
{
	uint64_t	num_phil;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t 	time_to_think;
	uint64_t 	time_to_die;
	uint64_t	num_repeat;
}				t_settings;

typedef struct s_philosofers
{
	uint64_t		position;
	unsigned char	left_fork;
	unsigned char	right_fork;
}				t_nerds;

typedef struct s_table
{
	pthread_mutex_t *forks;
}				t_tables;

typedef struct s_args
{
	t_nerds			*nerds;
	t_tables		*table;
}				sum_args;

int		init_struct(t_settings *set, int argc, char **argv);
int		check_args(int argc, char **argv);
void	custom_exit(char *str);
t_nerds	*philo_fabrik(t_nerds *nerds, uint64_t len);
int	create_dinner(t_settings set);
void table_mute_init(t_tables *tables, uint64_t len);

#endif
