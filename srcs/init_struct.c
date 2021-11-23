#include "../includes/philo.h"

static uint64_t	ft_atoi_uint_64(char *argv)
{
	uint64_t	result;
	uint64_t	tmp;

	result = 0;
	while (*argv)
	{
		tmp = result;
		result *= 10;
		result += *argv - '0';
		if (result < tmp)
			custom_exit("Error: Overfitting\n");
		argv++;
	}
	return (result);
}

int	init_struct(t_settings *set, int argc, char **argv)
{
	if (check_args(argc, argv))
		return (1);
	set->num_phil = ft_atoi_uint_64(argv[1]);
	set->dead = 0;
	set->time_to_die = ft_atoi_uint_64(argv[2]);
	set->time_to_eat = ft_atoi_uint_64(argv[3]);
	set->time_to_sleep = ft_atoi_uint_64(argv[4]);
	if (argc == 6)
		set->num_repeat = ft_atoi_uint_64(argv[5]);
	else
		set->num_repeat = 0;
	return (0);
}

