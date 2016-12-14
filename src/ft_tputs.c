#include <21sh.h>

void		ft_tputs(char *id)
{
	char *s;

	if ((s = tgetstr(id, NULL)) == NULL)
		ft_error("ft_select: error: Error on tgetstr");
	tputs(s, 0, tputc);
}