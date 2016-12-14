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

int			get_key_hook()
{
	int		key;
	t_term	*term;

	term = ft_term();
	while (42)
	{
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
			printf("\n%zd | %d\n", term->cursor_padd, term->winsize.ws_col);
		}
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
		key = 0;
	}
	return (-1);
}
