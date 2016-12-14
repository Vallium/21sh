
#include <21sh.h>

int		move_cursor_right(void)
{
	t_term	*term;

	term = ft_term();
	if ((term->cmd.cursor)->next != NULL)
	{
		term->cmd.cursor = (term->cmd.cursor)->next;
		ft_tputs("nd");
		term->cursor_padd++;
		if (term->cursor_padd > term->winsize.ws_col)
		{
			term->cursor_padd = 0;
			// ft_tputs("nw");
		}
	}
	return (1);
}