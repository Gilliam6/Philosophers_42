#ifndef PHILO_H
# define PHILO_H
# include "../includes/libft.h"
# include <pthread.h>
# include <sys/time.h>
# define FORKS = 1
# define EAT = 2
# define SLEEP = 3
# define THINK = 4
pthread_mutex_t die_mute;
typedef struct	s_timing
{
	uint64_t		num_phil;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t 		time_to_think;
	uint64_t 		time_to_die;
	uint64_t		num_repeat;
	unsigned char	dead;
}				t_settings;

typedef struct	s_philosofers
{
	uint64_t		position;
	uint64_t		left_fork;
	uint64_t		right_fork;
}				t_nerds;

typedef  struct s_table
{
	pthread_mutex_t *forks;
	pthread_mutex_t mute_nerds;
	unsigned char	is_dead;
}				t_table;

typedef struct	s_args
{
	t_settings		set;
	t_nerds			*nerds;
	t_table			*table;
}				sum_args;

sum_args	*args_fabrik(t_settings set);
uint64_t	get_time(void);

int		init_struct(t_settings *set, int argc, char **argv);
int		check_args(int argc, char **argv);
void	custom_exit(char *str);
int		create_dinner(t_settings set);

void	take_fork(sum_args *args);
uint64_t	eat_spaghetti(sum_args *args);
void	sleep_well(sum_args *args);
uint64_t	reflexing(sum_args *args);

#endif
