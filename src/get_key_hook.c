/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:59:00 by aalliot           #+#    #+#             */
/*   Updated: 2016/12/13 15:13:50 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void		cmd_delone(void *content, size_t size)
{
	(void)size;
	free(content);
	content = NULL;
}

static void		delete_on_cursor()
{
	ft_tputs("dc");
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

int			delete(int key)
{
	if (key == K_DELETE)
		delete_on_cursor();
	else
		delete_before_cursor();
	return (1);	
}

int			move_cursor_termination(int key)
{
	if (key == K_HOME || key == K_CTRL_A)
		move_cursor_home();
	else if (key == K_END || key == K_CTRL_E)
		move_cursor_end();
	return (1);
}

int			get_key_hook()
{
	int		key;
	t_term	*term;

	term = ft_term();
	while (42)
	{
		key = 0;
		read(0, &key, sizeof(int));
		// printf("%d\n", key);
		if (ft_isprint(key))
			printable_key_hook(key);
		else if (key == K_LEFT)
			arrow_left_hook();
		else if (key == K_RIGHT)
			arrow_right_hook();
		else if (key == K_RETURN)
		{
			// refresh_line_from_cursor();
			// printf("\n%zd | %d\n", term->cursor_padd, term->winsize.ws_col);
		}
		else if (key == K_DELETE || key == K_BACKSPACE)
			delete(key);
		else if (key == K_HOME || key == K_CTRL_A || key == K_END || key == K_CTRL_E)
			move_cursor_termination(key);
		// else if (key == K_CTRL_D)
		// 	exit(0);
		// 	t_lstd	*lst = term->cmd.first;

		// 	while (lst->content != NULL)
		// 	{
		// 		ft_putchar(((char *)(lst->content))[0]);
		// 		lst = lst->next;
		// 	}
		// 	return (1);
		// }
		// else if (key[0] == K_ESC)
		// 	break;
	}
	return (-1);
}
