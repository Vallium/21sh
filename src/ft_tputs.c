#include <21sh.h>

void		ft_tputs(char *id)
{
	char *s;

	if ((s = tgetstr(id, NULL)) == NULL)
		exit(0);
		// ft_error(ft_strreplace("%s", id, \
		// 	"ft_select: error: Error on tgetstr(\"$s\")", 0));
	tputs(s, 0, tputc);
}