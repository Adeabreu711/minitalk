/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:27 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/11 17:54:53 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include <signal.h>

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
	int	i;
	unsigned char	mask;

	i = -1;
	mask = 0b10000000;
	while (++i < 8)
	{
		if (mask <= c)
		{
			c -= mask;
			kill(pid, SIGUSR2);
			printf("1");
		}
		else
		{
			kill(pid, SIGUSR1);
			printf("0");
		}
		mask >>= 1;
	}
	printf("\n");
}

int	main (int argc, char *argv[])
{
	int	pid;

	if (argc < 3)
		return (0);

	pid = ft_atoi(argv[1]);
	send_bit(*argv[2], pid);
	printf ("\nclient PID : %i", pid);
	kill(pid, SIGUSR1);
	return (0);
}
