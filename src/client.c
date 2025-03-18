/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:27 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/18 18:50:27 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
// #include <asm-generic/siginfo.h>

#define MAX_TIME 100

int g_countdown = MAX_TIME;

void	send_bit(int sig, int pid)
{
	if (kill(pid, sig))
	{
		ft_printf("error : the given PID [%i] must be valid\n", pid);
		exit(0);
	}
	while (--g_countdown > 0)
		usleep(100);
	if (g_countdown == 0)
	{
		ft_printf("error : timeout, client waited [%i]ms", MAX_TIME * 100);
		exit(0);
	}
	usleep(100);
	g_countdown = MAX_TIME;
}

void	send_char(unsigned char c, int pid)
{
	int				sig;
	int				i;
	unsigned char	mask;

	i = -1;
	mask = 0b10000000;
	while (++i < 8)
	{
		if (mask <= c)
		{
			c -= mask;
			send_bit(SIGUSR2, pid);
		}
		else
			send_bit(SIGUSR1, pid);
		mask >>= 1;
	}
}

void	send_str(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_char(str[i], pid);
	send_char(0, pid);
}

void	sig_handler(int sig, siginfo_t *siginfo, void *empty)
{
	(void)empty;
	(void)siginfo;

	if (sig == SIGUSR1)
		g_countdown = -1;
	else if (sig == SIGUSR2)
	{
		ft_printf("message received.\n");
		exit(0);
	}
	return ;
}

int	main (int argc, char *argv[])
{
	static	int sigs[2] = {SIGUSR1, SIGUSR2};
	int	pid;

	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	init_signals(2, sigs, sig_handler);
	send_str(argv[2], pid);
	sleep(1);
	return (0);
}
