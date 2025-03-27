/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:03:52 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/27 00:35:35 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

typedef struct s_style
{
	char	*(*lng)(int);
	char	*(*thm)(int);
}	t_style;

t_style		*init_style(void);
int			display_msg(t_style **style, char *str, int pid);
void		style_print(t_style *stl, int txt_i, int pid, char *str);
char		*(*get_language(char *command))(int);
char		*(*get_theme(char *command))(int);

#endif
