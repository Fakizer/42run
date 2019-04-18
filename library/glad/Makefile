# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvlasenk <vvlasenk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/17 14:13:40 by vvlasenk          #+#    #+#              #
#    Updated: 2019/04/18 18:42:02 by vvlasenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH 	= ./src/
OBJ_PATH 	= ./obj/
INC_PATH 	= ./include/glad/ ./include/KHR/

NAME 		= glad.a
CC 			= gcc
CFGLAGS 	= -Werror -Wextra -Wall

SRC_NAME  	= 	glad.c

OBJ_NAME 	= $(SRC_NAME:.c=.o)

SRC 		= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ 		= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC 		= $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

norme:
	norminette $(SRC) $(INC_PATH)libmath.h

clean:
	rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all