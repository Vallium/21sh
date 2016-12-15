#include <21sh.h>

#define ERASE_DOWN		"\033[J"
#define SAVE_CURSOR 	"\033[s"
#define RESTORE_CURSOR	"\033[u"

void	ft_save_cursor()
{
	tputs(SAVE_CURSOR, 0, tputc);	
}

void	ft_restore_cursor()
{
	tputs(RESTORE_CURSOR, 0, tputc);
}

int		refresh_line_from_cursor()
{
	t_term	*term;
	t_lstd	*tmp;

	term = ft_term();
	tmp = term->cmd.cursor->prev;
	tputs(ERASE_DOWN, 0, tputc);
	ft_save_cursor();
	while (tmp->content)
	{
		tputs(tmp->content, 0, tputc);
		// if (term->cursor_padd > term->winsize.ws_col)
		// {
		// 	tmp = tmp->prev;
		// 	term->cursor_padd = 1;
		// 	ft_tputs("cr");	
		// 	ft_tputs("do");
		// 	ft_save_cursor();
		// }
		tmp = tmp->next;
	}
	if (term->cmd.cursor->content != NULL)
	{
		ft_restore_cursor();
		ft_tputs("nd");
	}
	return (1);
}

// int		printable_key_hook(int key)
// {
// 	char str[2];
// 	t_term	*term;

// 	if (add_key_to_cmd(key) == -1)
// 		exit(EXIT_FAILURE);
// 	term = ft_term();
// 	term->cursor_padd++;
// 	str[0] = key;
// 	str[1] = 0;
// 	tputs(str, 0, tputc);
// 	if (term->cursor_padd > term->winsize.ws_col)
// 	{
// 		term->cursor_padd = 1;
// 		ft_tputs("cr");	
// 		ft_tputs("do");
// 	}
// 	return (1);
// }