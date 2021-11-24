#include "../includes/philo.h"

void philo_routine(sum_args *args)
{
	uint64_t	time;

	while (!args->table->is_dead)
	{
		if (!args->table->is_dead)
			take_fork(args);
		if (!args->table->is_dead)
			time = eat_spaghetti(args);
		if (!args->table->is_dead)
			sleep_well(args);
		time = (reflexing(args) - time);
		if (!args->table->is_dead && time > args->set.time_to_die)
		{
			printf("%llu philosopher is dead\n", args->nerds->position);
			args->table->is_dead = 1;
			pthread_mutex_lock(&(*args).table->mute_nerds);
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
	pthread_mutex_init(&die_mute, NULL);
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