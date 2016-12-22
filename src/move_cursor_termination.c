#include <21sh.h>

int			move_cursor_termination(int key)
{
	if (key == K_HOME || key == K_CTRL_A)
		move_cursor_home();
	else if (key == K_END || key == K_CTRL_E)
		move_cursor_end();
	return (1);
}