/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/11 17:58:56 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include <signal.h>

// char	get_bit(int signum)
// {
// 	int	i;

// 	i = 0;
// }

void	signal_handler(int signum)
{
	int	i;

	i = 0;



	if (signum == SIGUSR1)
	{
		ft_printf("MESSAGE 0 RECEIVED\n", signum);

	}
	else if (signum == SIGUSR2)
	{
		ft_printf("MESSAGE 1 RECEIVED\n", signum);
	}
	exit(0);
}

int	main (int argc, char *argv[])
{
	ft_printf("PID : %i\n", getpid());

	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);

	while (1)
	{
		pause();
	}
	return (0);
}
