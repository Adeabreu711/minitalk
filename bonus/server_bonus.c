/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/27 01:16:13 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#define SERVER_CLOSED "\n\n[system : server closed]\n"

int	free_all(t_style **style, char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	if (*style)
	{
		free (*style);
		*style = NULL;
	}
	return (0);
}

void	close_reception(t_sbuild **sb, t_style **style, int pid)
{
	char	*str;

	str = ft_sb_build(*sb);
	ft_sbclear(sb);
	if (!str)
		return ;
	if (display_msg(style, str, pid) == -1)
	{
		ft_printf(SERVER_CLOSED);
		free_all(style, str);
		exit (0);
	}
	if (kill(pid, SIGUSR2))
		style_print(*style, 5, pid, "");
	else
		style_print(*style, 4, 0, "");
	free (str);
}

void	sig_handler(int sig, siginfo_t *siginfo, void *empty)
{
	static t_style			*style;
	static int				count = 0;
	static unsigned char	oct = 0b0;
	static t_sbuild			*sb = NULL;

	(void)empty;
	if (!style)
		style = init_style();
	if (!sb)
		sb = ft_sbnew("");
	if (sig == SIGUSR2)
		oct |= 128 >> count;
	count++;
	if (kill(siginfo->si_pid, SIGUSR1))
		style_print(style, 6, 0, "");
	if (count < 8)
		return ;
	ft_sb_addstr(&sb, (char *)&oct, 1);
	if (!oct)
		close_reception(&sb, &style, siginfo->si_pid);
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
