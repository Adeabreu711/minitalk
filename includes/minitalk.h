/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:16:23 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/22 01:19:03 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/ft_string_builder.h"
# include "../libft/includes/color.h"

//SERVER TEXT
# define SERVER_INFO "%s------------\n\e[0m\
%sSERVER INFO\n\e[0m%sPID : %i\n\e[0m\
%s------------\n\e[0m"
# define MSG_SRC "\n%s---------------------------------\n\e[0m\
%sMessage received from \e[0m%sPID[%i]\n\
%s---------------------------------\n\n\e[0m"
# define PRINT_MSG "%sMESSAGE\n\e[0m%s%s\n\n\e[0m"
# define ERROR_RCPTN "%serror :\e[0m %scannot send reception to PID[%i].\n\e[0m"
# define VALID_PID "%sreception sent with success.\n\e[0m"
# define ERROR_SIGNAL "%serror :\e[0m %ssignal cannot be sent to client.\n\e[0m"

//CLIENT TEXT
# define ERROR_PID "%serror :\e[0m %sthe given PID [%i] must be valid\n\e[0m"
# define ERROR_TIMEOUT "%serror :\e[0m %stimeout, client waited %ims\n\e[0m"
# define MSG_RECEIVED "%smessage received.\n\e[0m"

//UTILS
void	init_signals(int sig_c, int sigs[], void(*f)(int, siginfo_t *, void *));

#endif
