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

int		refresh_line_from_cursor(int cursor_pos)
{
	t_term	*term;
	t_lstd	*cmd;

	term = ft_term();
	cmd = term->cmd.cursor;
	if (cmd->prev)
		cmd = cmd->prev;
	if (cursor_pos == CURSOR_PREV)
	{
		if (cmd && cmd->next)
			cmd = cmd->next;
		ft_tputs("le");
	}
	tputs(SAVE_CURSOR, 0, tputc);
	tputs(ERASE_DOWN, 0, tputc);
	while (cmd && cmd->content != NULL)
	{
		tputs(cmd->content, 0, tputc);
		cmd = cmd->next;
	}
	tputs(RESTORE_CURSOR, 0, tputc);
	if (cursor_pos == CURSOR_NEXT)
		ft_tputs("nd");
	return (1);
}
