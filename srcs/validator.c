#include "../includes/philo.h"

int	check_digits(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

int check_args(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (check_digits(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

