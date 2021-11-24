#include "../includes/philo.h"

void	take_fork(sum_args *args)
{
	pthread_mutex_lock(&(*args).table->forks[args->nerds->left_fork]);
	pthread_mutex_lock(&(*args).table->forks[args->nerds->right_fork]);
	printf("%d dead? | %llu philosopher has taken a left fork\n",
		   args->table->is_dead, args->nerds->position);
	printf("%llu philosopher has taken a right fork\n",
		   args->nerds->position);
}

uint64_t	eat_spaghetti(sum_args *args)
{
	printf("%llu philosopher is eating\n", args->nerds->position);
	usleep(args->set.time_to_eat);
	pthread_mutex_unlock(&(args->table->forks)[args->nerds->left_fork]);
	pthread_mutex_unlock(&(args->table->forks)[args->nerds->right_fork]);
	return (get_time());
}

void	sleep_well(sum_args *args)
{
	printf("%llu philosopher is sleep\n", args->nerds->position);
	usleep(args->set.time_to_sleep);
}

uint64_t	reflexing(sum_args *args)
{
	printf("%llu philosopher thinking\n", args->nerds->position);
	return (get_time());
}
