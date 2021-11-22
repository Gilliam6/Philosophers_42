#include "../includes/philo.h"

void table_mute_init(t_tables *tables, uint64_t len)
{
	uint64_t	i;

	i = 0;
	while ()
}

t_nerds	*philo_fabrik(t_nerds *nerds, uint64_t len)
{
	uint64_t	i;

	i = 0;
	while (i < len)
	{
		nerds[i].position = i;
		nerds[i].left_fork = i;
		nerds[i].right_fork = (i + 1) % len;
		i++;
	}
	return (nerds);
}