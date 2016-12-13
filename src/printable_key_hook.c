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

int		add_key_to_cmd(char *key)
{
	t_term	*term;
	t_lstd	*tmp;

	term = ft_term();
	if (!(tmp = ft_lstdnew(key, sizeof(char *))))
		return (-1);
	ft_lstdadd(&(term->cmd.cursor), tmp);
	term->cmd.cursor = tmp;
	if (term->cmd.cmd == NULL)
		term->cmd.cmd = tmp;
	term->cmd.len++;
	return (1);
}

int		printable_key_hook(char *key)
{
	if (add_key_to_cmd(key) == -1)
		exit(EXIT_FAILURE);
	ft_putchar(key[0]);
	return (1);
}
