
#include <21sh.h>

int		move_cursor_right(void)
{
	t_term	*term;

	term = ft_term();
	if ((term->cmd.cursor)->next != NULL)
	{
		term->cmd.cursor = (term->cmd.cursor)->next;
		ft_tputs("nd");
	}
	return (1);
}