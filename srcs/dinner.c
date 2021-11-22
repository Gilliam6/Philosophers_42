#include "../includes/philo.h"

int	create_dinner(t_settings set)
{
	pthread_t	threads[set.num_phil];
	t_nerds		nerds[set.num_phil];
	t_tables	table;
	sun_args	args;

	table.forks = malloc(sizeof(table.forks) * set.num_phil);
	if (!table.forks)
		return (1);
	nerds = philo_fabrik(nerds, set.num_phil);
	table_mute_init(&table, set.num_phil);
	args->nerds = nerds;
	args->table = table;

	return (0);
}