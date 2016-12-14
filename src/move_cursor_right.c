
#include <21sh.h>

int		move_cursor_right(void)
{
	t_term	*term;

	term = ft_term();
	if ((term->cmd.cursor)->next != NULL)
	{
		term->cmd.cursor = (term->cmd.cursor)->next;
		term->cursor_padd++;
		if (term->cursor_padd > term->winsize.ws_col)
		{
			term->cursor_padd = 1;
			ft_tputs("cr");	
			ft_tputs("do");	
		}
		else
			ft_tputs("nd");
	}
	return (1);
}