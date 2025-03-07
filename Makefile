# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alde-abr <alde-abr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 15:08:31 by alde-abr          #+#    #+#              #
#    Updated: 2025/03/07 19:00:31 by alde-abr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME_2 = client
CC = gcc
CFLAGS =
LIB = libft/libft.a

SRC_CLIENT = client.c

SRC_SERVER = server.c

INCLUDES = -Iincludes/

SRC_DIR = src/
OBJ_DIR = obj/

all: $(NAME) $(NAME_2)

#Construction de la lib
$(LIB):
	make -C libft/

#Création des fichiers .o
OBJ_CLIENT = $(addprefix $(OBJ_DIR), $(SRC_CLIENT:.c=.o))
OBJ_SERVER = $(addprefix $(OBJ_DIR), $(SRC_SERVER:.c=.o))

#Création du dossier OBJ_DIR
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#Compilation des fichiers .c en .o
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

#Création du programme
$(NAME): $(LIB) $(OBJ_DIR) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -Llibft -lft -o $(NAME)

$(NAME_2): $(LIB) $(OBJ_DIR) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -Llibft -lft -o $(NAME_2)

clean:
	rm -f $(OBJ_CLIENT)
	rm -f $(OBJ_SERVER)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_2)
	make fclean -C libft/

re: fclean all

.PHONY = all clean fclean re bonus
