# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 15:08:31 by alde-abr          #+#    #+#              #
#    Updated: 2025/03/26 23:42:13 by alde-abr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SRV = server
NAME_CLT = client

NAME_SRV_BONUS = server_bonus
NAME_CLT_BONUS = client_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = libft/libft.a

SRC_CLT = \
	client.c sig_utils.c
SRC_SRV = \
	server.c sig_utils.c

SRC_CLT_BONUS = \
	client_bonus.c sig_utils.c
SRC_SRV_BONUS = \
	server_bonus.c sig_utils.c language.c theme.c style.c command.c

INCLUDES = -Iincludes/
INCLUDES_BONUS = -Ibonus/

SRC_DIR = src/
OBJ_DIR = obj/
BONUS_DIR = bonus/

all: $(NAME_SRV) $(NAME_CLT)

#Construction de la lib
$(LIB):
	make -C libft/

#Création des fichiers .o
OBJ_CLT = $(addprefix $(OBJ_DIR), $(SRC_CLT:.c=.o))
OBJ_SRV = $(addprefix $(OBJ_DIR), $(SRC_SRV:.c=.o))

OBJ_CLT_BONUS = $(addprefix $(OBJ_DIR), $(SRC_CLT_BONUS:.c=.o))
OBJ_SRV_BONUS = $(addprefix $(OBJ_DIR), $(SRC_SRV_BONUS:.c=.o))

#Création du dossier OBJ_DIR
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(INCLUDES_BONUS) $(CFLAGS) -c $< -o $@

#Création du programme
$(NAME_SRV): $(LIB) $(OBJ_DIR) $(OBJ_SRV)
	$(CC) $(CFLAGS) $(OBJ_SRV) -Llibft -lft -o $(NAME_SRV)

$(NAME_CLT): $(LIB) $(OBJ_DIR) $(OBJ_CLT)
	$(CC) $(CFLAGS) $(OBJ_CLT) -Llibft -lft -o $(NAME_CLT)

$(NAME_SRV_BONUS): $(LIB) $(OBJ_DIR) $(OBJ_SRV_BONUS)
	$(CC) $(CFLAGS) $(OBJ_SRV_BONUS) -Llibft -lft -o $(NAME_SRV_BONUS)

$(NAME_CLT_BONUS): $(LIB) $(OBJ_DIR) $(OBJ_CLT_BONUS)
	$(CC) $(CFLAGS) $(OBJ_CLT_BONUS) -Llibft -lft -o $(NAME_CLT_BONUS)

bonus: $(NAME_SRV_BONUS) $(NAME_CLT_BONUS)

clean:
	rm -f $(OBJ_CLT)
	rm -f $(OBJ_SRV)
	rm -f $(OBJ_SRV_BONUS)
	rm -f $(OBJ_CLT_BONUS)
	make clean -C libft/

fclean: clean
	rm -f $(NAME_SRV)
	rm -f $(NAME_CLT)
	rm -f $(NAME_SRV_BONUS)
	rm -f $(NAME_CLT_BONUS)
	make fclean -C libft/

re: fclean all

.PHONY = all clean fclean re bonus
