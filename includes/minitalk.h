/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:16:23 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/17 20:51:53 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/ft_string_builder.h"

void	init_signals(int sig_c, int sigs[], void(*f)(int, siginfo_t *, void *));

#endif
