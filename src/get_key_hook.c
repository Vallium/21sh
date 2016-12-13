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
	char	key[1];

	while (42)
	{
		read(0, key, sizeof(int));
		if (ft_isprint(key[0]))
			printable_key_hook(key);
		else if (key[0] == K_RETURN)
		{
			t_lstd	*lst = term->cmd.cmd;
			t_lstd	*first = term->cmd.cmd;

			while (lst->next != NULL)
			{
				ft_putchar(((char *)(lst->content))[0]);
				lst = lst->next;
			}
			return (1);
		}
		else if (key[0] == K_ESC)
			break;
	}
	return (-1);
}
