# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nkuipers <nkuipers@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/18 09:44:57 by nkuipers       #+#    #+#                 #
#    Updated: 2019/11/27 14:27:03 by nkuipers      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a
OBJECTS = 	

BONUS = 	
FLAGS = 	-Wall -Werror -Wextra
INCLUDES = 	ft_printf.h

# COLOURS
GREEN	= \x1b[32;01m
WHITE	= \x1b[29;01m

all: $(NAME)

%.o: %.c
	@echo "$(WHITE)Compiling: $<"
	@gcc -o $@ -c $< $(FLAGS) -I$(INCLUDES)

$(NAME): $(OBJECTS)
	@echo "$(GREEN)Creating"
	@ar rc $(NAME) $(OBJECTS)
	@echo "$(GREEN)Done"

clean: clean_b
	@echo "$(WHITE) Cleaning..."

fclean: clean_b
	@echo "$(WHITE) Cleaning all..."
	@rm -f $(NAME)

clean_b:
	@rm -f $(BONUS)
	@rm -f $(OBJECTS)

re: fclean all

bonus: $(OBJECTS) $(BONUS) $(NAME)
	@echo "$(GREEN)Adding the bonuses..."
	@ar rc $(NAME) $(OBJECTS) $(BONUS)
	@echo "$(GREEN)Done"

.PHONY: all clean fclean re bonus
