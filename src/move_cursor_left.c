#include <21sh.h>

int		move_cursor_left(void)
{
	t_term	*term;

	term = ft_term();
	if ((term->cmd.cursor)->prev != NULL)
	{
		term->cmd.cursor = (term->cmd.cursor)->prev;
		ft_tputs("le");
	}
	return (1);
}