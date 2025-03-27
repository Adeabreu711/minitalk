/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:15:31 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/27 00:38:02 by alde-abr         ###   ########.fr       */
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
