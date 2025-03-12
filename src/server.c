/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/12 17:25:02 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include <signal.h>

void	signal_handler(int signum)
{
	// if (signum == SIGUSR1)
	// // else if(signum == SIGUSR2)
}

int	main (int argc, char *argv[])
{
	int	last_bit_c;
	t_sbuild	*sb;

	sb = ft_sbnew("");
	last_bit_c = 0;
	ft_printf("PID : %i\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
