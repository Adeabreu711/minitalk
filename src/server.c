/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 18:24:42 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/07 20:10:44 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/ft_printf.h"
#include <signal.h>

int	main (int argc, char *argv[])
{
	ft_printf("PID : %i\n", getpid());
	return (0);
}
