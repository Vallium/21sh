/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:42:03 by aalliot           #+#    #+#             */
/*   Updated: 2016/12/12 18:45:27 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

t_term		*ft_term(void)
{
	static t_term	term;

	return (&term);
}
