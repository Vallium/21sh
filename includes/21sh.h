/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:37:05 by aalliot           #+#    #+#             */
/*   Updated: 2016/12/13 12:22:45 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _21SH_H
# define _21SH_H

# include <libft.h>
# include <stdlib.h>
# include <fcntl.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <unistd.h>

# define K_UP 4283163
# define K_DOWN 4348699
# define K_LEFT 4479771
# define K_RIGHT 4414235
# define K_ESC 27
# define K_RETURN 10
# define K_SPACE 32
# define K_DELETE 2117294875
# define K_BACKSPACE 127
# define K_CTRL_D 4

typedef struct termios t_termios;

typedef struct		s_cmd
{
	t_lstd			*first;
	t_lstd			*cursor;
	t_lstd			*last;
}					t_cmd;

typedef struct		s_term
{
	t_termios		term;
	t_termios		default_term;
	t_cmd			cmd;
	int				fd;
	char			*name;
}					t_term;

t_term		*ft_term(void);
int			get_key_hook(void);
int			printable_key_hook(int key);

void		ft_tputs(char *id);
int	tputc(int c);

int	arrow_left_hook(void);
int	arrow_right_hook(void);

int		move_cursor_left(void);
int		move_cursor_right(void);

void		init_hook(void);
int			init_cmd(void);
int			init_term(void);

#endif
