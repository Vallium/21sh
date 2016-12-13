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

void		init_cmd(void)
{
	t_term	*term;

	term = ft_term();
	term->cmd.cmd = NULL;
	term->cmd.cursor = NULL;
	term->cmd.len = 0;
}
