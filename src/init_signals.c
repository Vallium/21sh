
#include <21sh.h>
#include <signal.h>

void	sig_winch(int i)
{
	(void)i;
	winsize();
}

void	init_signals(void)
{
	// signal(SIGINT, sig_exit);
	// signal(SIGQUIT, sig_exit);
	// signal(SIGABRT, sig_exit);
	// signal(SIGKILL, sig_exit);
	signal(SIGWINCH, sig_winch);
	// signal(SIGTSTP, sig_tstp);
	// signal(SIGCONT, sig_cont);
}