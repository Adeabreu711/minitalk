/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/17 22:27:56 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	compare_commands(char *str, int pid)
{
	return (1);
}

void	close_reception(t_sbuild **sb, int pid)
{
	char	*str;

	str = ft_sb_build(*sb);
	ft_sbclear(sb);
	if (!str)
		return ;
	ft_printf("message received from PID[%i]!\n", pid);
	// if (compare_commands(str, pid))
	ft_printf("%s\n", str);
	ft_printf("sending reception...\n", pid);
	if (kill(pid, SIGUSR2))
		ft_printf("aborting : cannot send reception to PID[%i]\n", pid);
	else
		ft_printf("reception sent with success.\n");
	free (str);
}

void	sig_handler(int sig, siginfo_t *siginfo, void *empty)
{
	static int				count = 0;
	static unsigned char	oct = 0b0;
	static t_sbuild			*sb = NULL;

	(void)empty;
	if (!sb)
		sb = ft_sbnew("");
	if (sig == SIGUSR2)
		oct |= 128>>count;
	count++;
	if (kill(siginfo->si_pid, SIGUSR1))
		ft_printf("error : signal cannot be sent to client.\n");
	if (count < 8)
		return ;
	ft_sb_addstr(&sb, &oct, 1);
	printf("char : %i\n", oct);
	if (!oct)
		close_reception(&sb, siginfo->si_pid);
	oct = 0b0;
	count = 0;
}

int	main (int argc, char *argv[])
{
	static	int sigs[2] = {SIGUSR1, SIGUSR2};
	t_sbuild	*sb;

	sb = ft_sbnew("");
	ft_printf("PID : %i\n",  getpid());
	init_signals(2, sigs, sig_handler);
	while (1)
		pause();
	return (0);
}
