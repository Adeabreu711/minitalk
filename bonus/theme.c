/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:15:29 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/27 00:55:20 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#define THM_CHANGED "\n\n[system : theme turned to %s]"
#define THM_RESET "\n\n[system : theme not found, reset to %s]"

#define DASH_1 1
#define DASH_2 2
#define SRV_INFO_TITLE 3
#define SRV_INFO_PID 4
#define MSG_RCVD 5
#define MSG_RCVD_PID 6
#define MSG_TITLE 7
#define MSG 8
#define SENDIND_SUCCESS 9
#define ERROR 10
#define ERROR_MSG 11

char	*t_default(int i)
{
	if (i == DASH_1)
		return (GREY);
	else if (i == DASH_2)
		return (GREY);
	else if (i == SRV_INFO_TITLE)
		return (GREY_B);
	else if (i == SRV_INFO_PID)
		return (GREY);
	else if (i == MSG_RCVD)
		return (GREY);
	else if (i == MSG_RCVD_PID)
		return (GREY_B);
	else if (i == MSG_TITLE)
		return (GREY_B);
	else if (i == MSG)
		return (GREY);
	else if (i == SENDIND_SUCCESS)
		return (GREEN);
	else if (i == ERROR)
		return (RED);
	else if (i == ERROR_MSG)
		return (GREY);
	return (GREY);
}

char	*t_candy(int i)
{
	if (i == DASH_1)
		return (YELLOW);
	else if (i == DASH_2)
		return (YELLOW);
	else if (i == SRV_INFO_TITLE)
		return (PURPLE_B);
	else if (i == SRV_INFO_PID)
		return (PURPLE);
	else if (i == MSG_RCVD)
		return (PURPLE);
	else if (i == MSG_RCVD_PID)
		return (YELLOW_B);
	else if (i == MSG_TITLE)
		return (PURPLE_B);
	else if (i == MSG)
		return (YELLOW);
	else if (i == SENDIND_SUCCESS)
		return (YELLOW);
	else if (i == ERROR)
		return (PURPLE);
	else if (i == ERROR_MSG)
		return (YELLOW);
	return (GREY);
}

char	*t_hacker(int i)
{
	if (i == DASH_1)
		return (GREEN);
	else if (i == DASH_2)
		return (GREEN);
	else if (i == SRV_INFO_TITLE)
		return (GREEN_B);
	else if (i == SRV_INFO_PID)
		return (GREEN_B);
	else if (i == MSG_RCVD)
		return (GREEN_B);
	else if (i == MSG_RCVD_PID)
		return (GREEN_B);
	else if (i == MSG_TITLE)
		return (GREEN_B);
	else if (i == MSG)
		return (GREEN);
	else if (i == SENDIND_SUCCESS)
		return (GREEN);
	else if (i == ERROR)
		return (GREEN_B);
	else if (i == ERROR_MSG)
		return (GREEN);
	return (GREY);
}

char	*t_black(int i)
{
	if (i == DASH_1)
		return (BLACK);
	else if (i == DASH_2)
		return (BLACK);
	else if (i == SRV_INFO_TITLE)
		return (BLACK_B);
	else if (i == SRV_INFO_PID)
		return (BLACK);
	else if (i == MSG_RCVD)
		return (BLACK);
	else if (i == MSG_RCVD_PID)
		return (BLACK_B);
	else if (i == MSG_TITLE)
		return (BLACK_B);
	else if (i == MSG)
		return (WHITE);
	else if (i == SENDIND_SUCCESS)
		return (BLACK);
	else if (i == ERROR)
		return (BLACK_B);
	else if (i == ERROR_MSG)
		return (WHITE);
	return (GREY);
}

char	*(*get_theme(char *command))(int)
{
	if (!ft_strncmp(command, "theme:default", 13))
		return (ft_printf(THM_CHANGED, "default"), t_default);
	else if (!ft_strncmp(command, "theme:candy", 11))
		return (ft_printf(THM_CHANGED, "candy"), t_candy);
	else if (!ft_strncmp(command, "theme:hacker", 12))
		return (t_hacker);
	else if (!ft_strncmp(command, "theme:black", 11))
		return (t_black);
	else if (!ft_strncmp(command, "theme:init", 10))
		return (t_default);
	return (ft_printf(THM_RESET, "default"), t_default);
}
