#include <21sh.h>

static void		cmd_delone(void *content, size_t size)
{
	(void)size;
	free(content);
	content = NULL;
}

static void		delete_on_cursor()
{
	t_term	*term;
	t_lstd	*del;

	term = ft_term();
	if (term->cmd.cursor && term->cmd.cursor->content)
	{
		del = term->cmd.cursor;
		term->cmd.cursor = term->cmd.cursor->next;
		ft_lstddelone(&del, cmd_delone);
		refresh_line_from_cursor(CURSOR_DEF);
	}
}

static void		delete_before_cursor()
{
	t_term	*term;

	term =	 ft_term();
	if (term->cmd.cursor->prev)
	{
		ft_lstddelone(&(term->cmd.cursor->prev), cmd_delone);
		refresh_line_from_cursor(CURSOR_PREV);
	}
}

int				cursor_delete(int key)
{
	if (key == K_DELETE)
		delete_on_cursor();
	else
		delete_before_cursor();
	return (1);	
}