#ifndef PHILO_H
# define PHILO_H
# include "../includes/libft.h"
# include <pthread.h>
# include <sys/time.h>
# define LEFT_FORK = "philosopher has taken a left fork\n"
# define RIGHT_FORK = "philosopher has taken a right fork\n"
# define EAT = "philosopher is eating\n"
# define THINK = "philosopher thinking\n"
# define SLEEP = "philosopher is sleeping\n"

typedef struct	s_timing
{
	uint64_t		num_phil;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t 		time_to_think;
	uint64_t 		time_to_die;
	uint64_t		num_repeat;
}				t_settings;

typedef struct	s_philosofers
{
	volatile uint64_t		timestamp;
	volatile uint64_t 		last_eat;
	uint64_t				position;
	uint64_t				left_fork;
	uint64_t				right_fork;
}				t_nerds;

typedef  struct s_table
{
	pthread_mutex_t *forks;
	pthread_mutex_t mute_nerds;
//	pthread_mutex_t	is_dead;
	pthread_mutex_t anti_deadlock;
	unsigned char 	dead;
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
void	say_something(sum_args *args, char *str);

void	take_fork(sum_args *args);
void	eat_spaghetti(sum_args *args);
void	sleep_well(sum_args *args);
void	reflexing(sum_args *args);
void	dead(sum_args *args);

#endif
