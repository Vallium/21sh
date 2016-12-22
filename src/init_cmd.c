/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:19:02 by aalliot           #+#    #+#             */
/*   Updated: 2016/12/13 12:20:17 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		init_cmd(void)
{
	t_term	*term;

	term = ft_term();
	term->cmd.first = NULL;
	if (!(term->cmd.cursor = ft_lstdnew(NULL, sizeof(int))))
		return (-1);
	term->cmd.last = term->cmd.cursor;
	return (1);
}
