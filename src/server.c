/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/27 00:37:35 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	close_reception(t_sbuild **sb, int pid)
{
	char	*str;

	str = ft_sb_build(*sb);
	ft_sbclear(sb);
	if (!str)
		return ;
	if (!ft_strncmp(str, "exit", 4))
	{
		sb = NULL;
		free (str);
		exit(0);
	}
	ft_printf(MSG_SRC, GREY, GREY_B, GREY, pid, GREY);
	ft_printf(PRINT_MSG, GREY_B, GREY, str);
	if (kill(pid, SIGUSR2))
		ft_printf(ERROR_RCPTN, RED, GREY, pid);
	else
		ft_printf(VALID_PID, GREEN);
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
		oct |= 128 >> count;
	count++;
	if (kill(siginfo->si_pid, SIGUSR1))
		ft_printf(ERROR_SIGNAL, RED, GREY);
	if (count < 8)
		return ;
	ft_sb_addstr(&sb, (char *)&oct, 1);
	if (!oct)
		close_reception(&sb, siginfo->si_pid);
	oct = 0b0;
	count = 0;
}

int	main(void)
{
	static int	sigs[2] = {SIGUSR1, SIGUSR2};

	ft_printf(SERVER_INFO, GREY, GREY_B, GREY, getpid(), GREY);
	init_signals(2, sigs, sig_handler);
	while (1)
		pause();
	return (0);
}
