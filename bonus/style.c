/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 16:12:47 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/27 01:18:14 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

#define SRV_INFO_1 "%s------------\n\e[0m%s%s\n\e[0m"
#define SRV_INFO_2 "%sPID : %i\n\e[0m%s------------\n\e[0m"
#define MSG_RCVD_1 "\n%s---------------------------------\n\e[0m%s%s \e[0m"
#define MSG_RCVD_2 "%sPID[%i]\e[0m\n%s---------------------------------\n\e[0m"
#define MSG_DSPL "\n%s%s\n\e[0m%s\"%s\"\n\n\e[0m"
#define VALID_RCPT "%s%s\n\e[0m"
#define ERROR_RCPT "%s%s : \e[0m%s%s PID[%i].\n\e[0m"
#define ERROR_SIGNAL "%s%s : \e[0m%s%s\n\e[0m"
#define COMMAND_DSPL "\n%s%s\n\e[0m%s%s\n\n\e[0m"

t_style	*init_style(void)
{
	t_style	*style;

	style = ft_calloc(1, sizeof(t_style));
	if (!style)
		return (NULL);
	style->lng = get_language("language:init");
	style->thm = get_theme("theme:init");
	return (style);
}

void	style_print(t_style *stl, int txt_i, int pid, char *str)
{
	if (!stl->lng || !stl->thm)
		return ;
	if (txt_i == 1)
	{
		ft_printf(SRV_INFO_1, stl->thm(1), stl->thm(3), stl->lng(1));
		ft_printf(SRV_INFO_2, stl->thm(4), pid, stl->thm(1));
	}
	else if (txt_i == 2)
	{
		ft_printf(MSG_RCVD_1, stl->thm(2), stl->thm(5), stl->lng(2));
		ft_printf(MSG_RCVD_2, stl->thm(6), pid, stl->thm(2));
	}
	else if (txt_i == 3)
		ft_printf(MSG_DSPL, stl->thm(7), stl->lng(3), stl->thm(8), str);
	else if (txt_i == 4)
		ft_printf(VALID_RCPT, stl->thm(9), stl->lng(4));
	else if (txt_i == 5)
		ft_printf(ERROR_RCPT, stl->thm(10), stl->lng(5),
			stl->thm(11), stl->lng(6), pid);
	else if (txt_i == 6)
		ft_printf(ERROR_SIGNAL, stl->thm(10), stl->lng(5),
			stl->thm(11), stl->lng(7));
	else if (txt_i == 7)
		ft_printf(COMMAND_DSPL, stl->thm(7), stl->lng(8), stl->thm(8), str);
}
