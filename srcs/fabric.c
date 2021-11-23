#include "../includes/philo.h"

void forks_mute_init(sum_args **args, uint64_t len)
{
	uint64_t	i;

	i = 0;
	(*args)->forks = malloc(sizeof((*args)->forks) * len);
	if (!(*args)->forks)
	{
		free((*args)->nerds);
		custom_exit("Error Malloc\n");
	}
	while (i < len)
	{
		pthread_mutex_init(&(*args)->forks[i], NULL);
		i++;
	}
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