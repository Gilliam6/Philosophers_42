#include "../includes/philo.h"

void philo_routine(sum_args *args)
{
	args->nerds->timestamp = get_time();
	args->nerds->last_eat = get_time();
//	pthread_detach(pthread_self());
	while (!args->table->dead)
	{
		if (args->nerds->last_eat && get_time() - args->nerds->last_eat < args->set
		.time_to_die)
		{
			pthread_mutex_lock(&(*args).table->forks[args->nerds->left_fork]);
			pthread_mutex_lock(&(*args).table->forks[args->nerds->right_fork]);
			if (get_time() - args->nerds->last_eat > args->set.time_to_die)
			{
				dead(args);
				break;
			}
			take_fork(args);
			eat_spaghetti(args);
			sleep_well(args);
			reflexing(args);
		}
		else
		{
			dead(args);
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
	void                *status;

	status = 0;
	args = args_fabrik(set);
	index = 0;
//	for (int i = 0; i < (int)args->set.num_phil; i++)
//		printf("%llu %llu forks\n", args[i].nerds->left_fork,
//			   args[i].nerds->right_fork);
	while (index < set.num_phil)
	{
		pthread_create(&threads[index], NULL, (void *(*)(void *))
		philo_routine, &args[index]);
		index++;
	}
	index = 0;

	while (index < set.num_phil)
	{
		pthread_join(threads[index], &status);
		if (status)
		{
			index = -1;
			while(++index < set.num_phil)
				pthread_detach(threads[index]);
		}
		index++;
	}
	return (0);
}