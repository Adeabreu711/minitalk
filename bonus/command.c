/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:13:09 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/27 01:24:37 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	check_command(t_style **style, char *str)
{
	if (!ft_strncmp("language:", str, 9))
		(*style)->lng = get_language(str);
	else if (!ft_strncmp("theme:", str, 6))
		(*style)->thm = get_theme(str);
	else if (!ft_strncmp("info", str, 4))
	{
		style_print(*style, 1, getpid(), "");
		return (0);
	}
	else if (!ft_strncmp("exit", str, 4))
		return (-1);
	return (1);
}

int	display_msg(t_style **style, char *str, int pid)
{
	int	com_type;
	int	i;

	com_type = 0;
	i = 0;
	while ((str[i] > 7 && str[i] < 13) || str[i] == ' ')
		i++;
	if (str[i++] != '/')
	{
		style_print(*style, 2, pid, 0);
		style_print(*style, 3, 0, str);
		return (1);
	}
	com_type = check_command(style, str + i);
	if (com_type == -1)
		return (-1);
	if (com_type)
	{
		style_print(*style, 2, pid, 0);
		style_print(*style, 7, 0, str);
	}
	return (0);
}
