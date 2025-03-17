/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:15:31 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/17 20:33:17 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	init_signals(int sig_c, int sigs[], void(*f)(int, siginfo_t *, void *))
{
	int					i;
	struct sigaction	s_sa;

	i = 0;
	s_sa.sa_sigaction = f;
	s_sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&s_sa.sa_mask);
	while (i < sig_c)
	{
		sigaddset(&s_sa.sa_mask, sigs[i]);
		sigaction(sigs[i++], &s_sa, 0);
	}
}

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
