#include <21sh.h>

int	tputc(int c)
{
	t_term	*term;

	term = ft_term();
	return ((int)write(term->fd, &c, 1));
}