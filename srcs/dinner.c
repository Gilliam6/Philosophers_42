#include "../includes/philo.h"

void philo_routine(sum_args *args)
{
	uint64_t	time;

	while (1)
	{
		pthread_mutex_lock(&(*args).table->forks[args->nerds->left_fork]);
		pthread_mutex_lock(&(*args).table->forks[args->nerds->right_fork]);
		printf("%llu philosopher has taken a fork\n", args->nerds->position);
		printf("%llu philosopher is eating\n", args->nerds->position);
		sleep(args->set.time_to_eat);
		time = get_time();
		pthread_mutex_unlock(&(args->table->forks)[args->nerds->left_fork]);
		pthread_mutex_unlock(&(args->table->forks)[args->nerds->right_fork]);
		printf("%llu philosopher is sleep\n", args->nerds->position);
		sleep(args->set.time_to_sleep);
		time = get_time() - time;
		if (time > args->set.time_to_die)
		{
			printf("%llu philosopher is dead\n", args->nerds->position);
			pthread_cancel(pthread_self());
			usleep(200);
		}
	}
}

int	create_dinner(t_settings set)
{
	pthread_t			threads[set.num_phil];
	uint64_t			index;
	sum_args			*args;

	args = args_fabrik(set);
//	for (uint64_t i = 0; i < set.num_phil; i++)
//	{
//		printf("args index | %llu, args philo pos | %llu, args forks | %llu "
//			   "%llu || set num %llu || set time %llu \n", i, args[i]
//			   .nerds->position, args[i]
//			   .nerds->left_fork,
//			   args[i].nerds->right_fork, args[i].set.num_phil, args[i].set
//			   .time_to_sleep);
//	}
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