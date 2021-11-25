#include "../includes/philo.h"

void	take_fork(sum_args *args)
{
//	pthread_mutex_lock(&(*args).table->anti_deadlock);
//	pthread_mutex_lock(&(*args).table->forks[args->nerds->left_fork]);
//	pthread_mutex_lock(&(*args).table->forks[args->nerds->right_fork]);
//	pthread_mutex_unlock(&(*args).table->anti_deadlock);
	say_something(args, " has taken a fork\n");
	say_something(args, " has taken a fork\n");
	say_something(args, " is eating\n");
}

void	eat_spaghetti(sum_args *args)
{
//	say_something(args, " is eating\n");
	args->nerds->last_eat = get_time();
	usleep(args->set.time_to_eat * 1000);
	pthread_mutex_unlock(&(args->table->forks)[args->nerds->left_fork]);
	pthread_mutex_unlock(&(args->table->forks)[args->nerds->right_fork]);
}

void	sleep_well(sum_args *args)
{
	say_something(args, " is sleeping\n");
	usleep(args->set.time_to_sleep * 1000);
}

void	reflexing(sum_args *args)
{
	say_something(args, " is thinking\n");
}

void	say_something(sum_args *args, char *str)
{
	pthread_mutex_lock(&(*args).table->mute_nerds);
	ft_putnbr_fd(get_time() - args->nerds->timestamp, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(args->nerds->position, 1);
	ft_putstr_fd(str, 1);
	pthread_mutex_unlock(&(*args).table->mute_nerds);
}

void	dead(sum_args *args)
{
	say_something(args, " is dead\n");
//			pthread_mutex_lock(&(*args).table->is_dead);
	args->table->dead = 1;
	pthread_mutex_lock(&(*args).table->mute_nerds);
}