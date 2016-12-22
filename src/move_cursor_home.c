#include <21sh.h>

int			move_cursor_home(void)
{
	while (move_cursor_left())
		;
	return (1);
}
