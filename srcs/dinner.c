#include "../includes/philo.h"

void philo_routine(sum_args *args)
{
	uint64_t	time;

	while (!args->set.dead)
	{
		pthread_mutex_lock(&(*args).table->forks[args->nerds->left_fork]);
		pthread_mutex_lock(&(*args).table->forks[args->nerds->right_fork]);
		printf("%llu philosopher has taken a left fork\n",
			   args->nerds->position);
		printf("%llu philosopher has taken a right fork\n",
			   args->nerds->position);
		printf("%llu philosopher is eating\n", args->nerds->position);
		usleep(args->set.time_to_eat);
		time = get_time();
		pthread_mutex_unlock(&(args->table->forks)[args->nerds->left_fork]);
		pthread_mutex_unlock(&(args->table->forks)[args->nerds->right_fork]);
		printf("%llu philosopher is sleep\n", args->nerds->position);
		usleep(args->set.time_to_sleep);
		printf("%llu philosopher thinking\n", args->nerds->position);
		time = (get_time() - time) * 100;
//		printf("%llu TIMe\n", time);
		if (!args->set.dead && time > args->set.time_to_die)
		{
			printf("%llu philosopher is dead\n", args->nerds->position);
			args->set.dead = 1;
			break;
		}
	}
//	pthread_detach(pthread_self());
}

int	create_dinner(t_settings set)
{
	pthread_t			threads[set.num_phil];
	uint64_t			index;
	sum_args			*args;

	args = args_fabrik(set);
	index = 0;
	while (index < set.num_phil)
	{
		pthread_create(&threads[index], NULL, (void *(*)(void *))
		philo_routine, &args[index]);
		index++;
	}
	index = 0;
	while (index < set.num_phil)
	{
		pthread_join(threads[index], NULL);
		index++;
	}
	return (0);
}