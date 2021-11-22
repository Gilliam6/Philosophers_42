#include "../includes/philo.h"

void	custom_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_settings		set;
	t_nerds			*nerds;

	if (argc < 5 || argc > 6)
		custom_exit("Wrong number of arguments\n");
	if (init_struct(&set, argc, argv))
		custom_exit("Not valid arguments\n");
	create_dinner(set);
	return (0);
}