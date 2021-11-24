#include "../includes/philo.h"

t_nerds	*create_nerds(t_settings set)
{
	t_nerds		*nerds;
	uint64_t	i;

	nerds = (t_nerds *)malloc(sizeof(t_nerds) * set.num_phil);
	if (!nerds)
		return (0);
	i = 0;
	while (i < set.num_phil)
	{
		nerds[i].left_fork = i;
		nerds[i].right_fork = (i + 1) % set.num_phil;
		nerds[i].position = i;
		i++;
	}
	return (nerds);
}

t_table	*create_table(t_settings set)
{
	t_table	*table;
	uint64_t i;

	table = malloc(sizeof(table));
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * set.num_phil);
	if (!table->forks)
		return (0);
	table->is_dead = 0;
	i = 0;
	while (i < set.num_phil)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->mute_nerds, NULL);
	return (table);
}

sum_args	*args_fabrik(t_settings set)
{
	sum_args	*args;
	t_table		*table;
	t_nerds 	*nerds;
	uint64_t	i;

	args = (sum_args *)malloc(sizeof(sum_args) * set.num_phil);
	if (!args)
		custom_exit("Malloc Error\n");
	table = create_table(set);
	nerds = create_nerds(set);
	i = 0;
	while (i < set.num_phil)
	{
		args[i].set = set;
		args[i].table = table;
		args[i].nerds = &nerds[i];
		i++;
	}
	return (args);
}