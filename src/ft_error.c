#include <21sh.h>

void	ft_error(char *err)
{
	// ft_reset_term();
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
}

void	ft_error_init(char *err)
{
	ft_putendl_fd(err, 2);
	exit(EXIT_FAILURE);
}