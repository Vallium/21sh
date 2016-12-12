/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:38:14 by aalliot           #+#    #+#             */
/*   Updated: 2016/12/12 18:58:04 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

int		init_term(void)
{
	t_term	*term;
	int		success;

	term = ft_term();
	if ((term->fd = open(ttyname(STDIN_FILENO), O_WRONLY)) == -1)
		return (-1); // TODO : Print Error
	term->name = getenv("TERM");
	if (term->name == NULL)
		return (-1); // TODO : Print Error
	success = tgetent(0, term->name);
	if (success < 0)
		return (-1); // TODO : Print Error
	else if (success == 0)
		return (-1); // TODO : Print Error
	if (tcgetattr(0, &(term->term)) == -1 ||
			tcgetattr(0, &(term->default_term)) == -1) // TODO : Peut etre save une copie
		return (-1); // TODO : Print Error
	term->term.c_lflag &= ~(ICANON | ECHO);
	//term->term.c_oflag &= OPOST;
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &(term->term));
	return (0);
}

int		main()
{
	t_term	*term;

	if (init_term() == -1)
		exit(EXIT_FAILURE);
	term = ft_term();
	while (42)
	{
		ft_putstr("21sh>");
	}
	tcsetattr(0, TCSADRAIN, &(term->default_term));
	return (0);
}
