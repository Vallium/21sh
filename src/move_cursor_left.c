#include <21sh.h>

int		move_cursor_left(void)
{
	t_term	*term;

	term = ft_term();
	if ((term->cmd.cursor)->prev != NULL)
	{
		term->cmd.cursor = (term->cmd.cursor)->prev;
		term->cursor_padd--;
		if (term->cursor_padd < 1)
		{
			term->cursor_padd = term->winsize.ws_col;
			ft_tputs("up");
			tputs(tgoto(tgetstr("ch", NULL), 0, term->winsize.ws_col - 1), 1, tputc);
		}
		else
			ft_tputs("le");
	}
	return (1);
}