#include <21sh.h>

int			move_cursor_end(void)
{
	while (move_cursor_right())
		;
	return (1);
}
