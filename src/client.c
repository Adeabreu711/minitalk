/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:27 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/12 17:40:48 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include <signal.h>
// #include <asm-generic/siginfo.h>
#define return(E) return(malloc(16), E)

#define MAXTRY 10

int	ft_pw(int nb, int power)
{
	int	temp;

	temp = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (--power > 0)
		temp = temp * nb;
	return (temp);
}

void	send_bit(char c, int pid)
{
	int				i;
	unsigned char	mask;
	int

	i = -1;
	mask = 0b10000000;
	while (++i < 8)
	{
		if (mask <= c)
		{
			c -= mask;
			kill(pid, SIGUSR2);
		}
		else
			kill(pid, SIGUSR1);
		mask >>= 1;
	}
}

void	init_signals(int sig_c, int sigs[], void(*f)(int, siginfo_t *, void *))
{
	int					i;
	struct sigaction	s_sa;

	i = 0;
	s_sa.sa_sigaction = f;
	sigemptyset(&s_sa.sa_mask);

	while (i < sig_c)
	{
		sigaddset(&s_sa.sa_mask, sigs[i]);
		sigaction(sigs[i++], &s_sa, 0);
	}
}

int	main (int argc, char *argv[])
{
	static	sigs[] = {SIGUSR1, SIGUSR2};
	int	pid;

	if (argc < 3)
		return (0);
	init_signals();
	pid = ft_atoi(argv[1]);
	send_bit(*argv[2], pid);
	printf ("\nclient PID : %i", pid);
	kill(pid, SIGUSR1);
	return (0);
}
