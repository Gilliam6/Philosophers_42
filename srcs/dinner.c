#include "../includes/philo.h"

void philo_routine(sum_args *args)
{
	while (1)
	{
		pthread_mutex_lock(&(args)->forks[args->nerds->left_fork]);
		pthread_mutex_lock(&(args)->forks[args->nerds->right_fork]);
		ft_putnbr_fd(args->nerds->position, 1);
		ft_putstr_fd(" philosopher has taken a fork\n", 1));
		ft_putnbr_fd(args->nerds->position, 1);
		ft_putstr_fd(" philosopher is eating\n", 1));
		usleep(args->set.time_to_eat);
		pthread_mutex_unlock(&(args)->forks[args->nerds->left_fork]);
		pthread_mutex_unlock(&(args)->forks[args->nerds->left_fork]);
		ft_putnbr_fd(args->nerds->position, 1);
		ft_putstr_fd(" philosopher is sleeping\n", 1));
		usleep(args->set.time_to_sleep);

	}
}

int	create_dinner(t_settings set)
{
	pthread_t	threads[set.num_phil];
	t_nerds		nerds[set.num_phil];
	sum_args	args[set.num_phil];
	uint64_t	index;

	nerds = philo_fabrik(nerds, set.num_phil);
	args->nerds = nerds;
	args->set = set;
	forks_mute_init(&args[], set.num_phil);
	index = 0;
	while (index < set.num_phil)
	{
		pthread_create(&threads[index], NULL, philo_routine, &args[index]);
		index++;
	}
	index = 0;
	while (index < set.num_phil)
	{
		pthread_join(&threads[index], NULL);
		index++;
	}
	return (0);
}