/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:16:31 by aalliot           #+#    #+#             */
/*   Updated: 2016/12/13 12:17:20 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <21sh.h>

void	init_hook(void)
{
	init_signals();
	init_term();
	init_cmd();
}
