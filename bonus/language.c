/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   language.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:38:08 by alde-abr          #+#    #+#             */
/*   Updated: 2025/03/27 01:05:31 by alde-abr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#define LNG_CHANGED "\n\n[system : language turned to %s]"
#define LNG_RESET "\n\n[system : language not found, reset to %s]"

char	*l_english(int i)
{
	if (i == 1)
		return ("SERVER INFO");
	else if (i == 2)
		return ("Message received from");
	else if (i == 3)
		return ("MESSAGE");
	else if (i == 4)
		return ("reception sent successfully.");
	else if (i == 5)
		return ("error");
	else if (i == 6)
		return ("cannot send reception to");
	else if (i == 7)
		return ("signal cannot be sent to client.");
	else if (i == 8)
		return ("COMMAND");
	return ("?");
}

char	*l_french(int i)
{
	if (i == 1)
		return ("INFO SERVEUR");
	else if (i == 2)
		return ("Message reçu de la part de");
	else if (i == 3)
		return ("MESSAGE");
	else if (i == 4)
		return ("la réception a été envoyée avec succès.");
	else if (i == 5)
		return ("erreur");
	else if (i == 6)
		return ("impossible d'envoyer la réception à");
	else if (i == 7)
		return ("impossible d'envoyer le signal au client.");
	else if (i == 8)
		return ("COMMANDE");
	return ("?");
}

char	*l_chinese(int i)
{
	if (i == 1)
		return ("服务器信息");
	else if (i == 2)
		return ("收到的消息来自");
	else if (i == 3)
		return ("消息");
	else if (i == 4)
		return ("接收已成功发送。");
	else if (i == 5)
		return ("错误");
	else if (i == 6)
		return ("无法发送接收至");
	else if (i == 7)
		return ("无法向客户端发送信号。");
	else if (i == 8)
		return ("命令");
	return ("?");
}

char	*l_russian(int i)
{
	if (i == 1)
		return ("ИНФОРМАЦИЯ О СЕРВЕРЕ");
	else if (i == 2)
		return ("Сообщение получено от");
	else if (i == 3)
		return ("СООБЩЕНИЕ");
	else if (i == 4)
		return ("Прием успешно отправлен.");
	else if (i == 5)
		return ("Ошибка");
	else if (i == 6)
		return ("Невозможно отправить прием к");
	else if (i == 7)
		return ("Невозможно отправить сигнал клиенту.");
	else if (i == 8)
		return ("КОМАНДА");
	return ("?");
}

char	*(*get_language(char *command))(int)
{
	if (!ft_strncmp(command, "language:english", 16))
		return (ft_printf(LNG_CHANGED, "english"), l_english);
	else if (!ft_strncmp(command, "language:french", 15))
		return (ft_printf(LNG_CHANGED, "french"), l_french);
	else if (!ft_strncmp(command, "language:chinese", 16))
		return (ft_printf(LNG_CHANGED, "chinese"), l_chinese);
	else if (!ft_strncmp(command, "language:russian", 16))
		return (ft_printf(LNG_CHANGED, "russian"), l_russian);
	else if (!ft_strncmp(command, "language:init", 14))
		return (l_english);
	return (ft_printf(LNG_RESET, "english"), l_english);
}
