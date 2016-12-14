/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:38:14 by aalliot           #+#    #+#             */
/*   Updated: 2016/12/13 15:14:44 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		main()
{
	t_term	*term;

	init_hook();
	term = ft_term();
	winsize();
	while (42)
	{
		char *prompt = ft_strdup("21sh>");
		ft_putstr(prompt);
		term->cursor_padd = ft_strlen(prompt);
		if (get_key_hook() == -1)
			break ;
	}
	tcsetattr(0, TCSADRAIN, &(term->default_term));
	return (0);
}
