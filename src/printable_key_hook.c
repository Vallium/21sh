/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printable_key_hook.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 11:36:29 by aalliot           #+#    #+#             */
/*   Updated: 2016/12/13 11:47:30 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		add_key_to_cmd(int key)
{
	t_term	*term;
	t_lstd	*tmp;
	char	str[2];

	term = ft_term();
	str[0] = key;
	if (!(tmp = ft_lstdnew(ft_strdup(str), sizeof(char *))))
		return (-1);
	ft_lstdadd(&(term->cmd.cursor), tmp, 1);
	term->cursor_padd++;
	if (!tmp->prev)
		term->cmd.first = tmp;
	return (1);
}

int		printable_key_hook(int key)
{
	if (add_key_to_cmd(key) == -1)
		exit(EXIT_FAILURE);
	//ft_putchar(key);
	char str[2];
	str[0] = key;
	str[1] = 0;
	tputs(str, 0, tputc);
	return (1);
}
