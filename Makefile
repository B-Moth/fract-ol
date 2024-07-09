# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lberne <lberne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 12:24:09 by lberne            #+#    #+#              #
#    Updated: 2024/07/05 16:52:36 by lberne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=\033[0m

# Regular Colors
Black=\033[0;30m         # Black
Red=\033[0;31m          # Red
Green=\033[0;32m        # Green
Yellow=\033[0;33m       # Yellow
Blue=\033[0;34m         # Blue
Purple=\033[0;35m       # Purple
Cyan=\033[0;36m         # Cyan
White=\033[0;37m        # White

# Bold
BBlack=\033[1;30m       # Black
BRed=\033[1;31m         # Red
BGreen=\033[1;32m       # Green
BYellow=\033[1;33m      # Yellow
BBlue=\033[1;34m        # Blue
BPurple=\033[1;35m     # Purple
BCyan=\033[1;36m        # Cyan
BWhite=\033[1;37m       # White

# Underline
UBlack=\033[4;30m       # Black
URed=\033[4;31m         # Red
UGreen=\033[4;32m       # Green
UYellow=\033[4;33m      # Yellow
UBlue=\033[4;34m        # Blue
UPurple=\033[4;35m      # Purple
UCyan=\033[4;36m        # Cyan
UWhite=\033[4;37m       # White

# Background
On_Black=\033[40m       # Black
On_Red=\033[41m         # Red
On_Green=\033[42m         # Green
On_Yellow=\033[43m      # Yellow
On_Blue=\033[44m        # Blue
On_Purple=\033[45m      # Purple
On_Cyan=\033[46m        # Cyan
On_White=\033[47m       # White

# High Intensity
IBlack=\033[0;90m       # Black
IRed=\033[0;91m         # Red
IGreen=\033[0;92m       # Green
IYellow=\033[0;93m      # Yellow
IBlue=\033[0;94m        # Blue
IPurple=\033[0;95m      # Purple
ICyan=\033[0;96m        # Cyan
IWhite=\033[0;97m       # White

# Bold High Intensity
BIBlack=\033[1;90m      # Black
BIRed=\033[1;91m        # Red
BIGreen=\033[1;92m      # Green
BIYellow=\033[1;93m     # Yellow
BIBlue=\033[1;94m       # Blue
BIPurple=\033[1;95m     # Purple
BICyan=\033[1;96m       # Cyan
BIWhite=\033[1;97m      # White

# High Intensity backgrounds
On_IBlack=\033[0;100m   # Black
On_IRed=\033[0;101m     # Red
On_IGreen=\033[0;102m     # Green
On_IYellow=\033[0;103m    # Yellow
On_IBlue=\033[0;104m    # Blue
On_IPurple=\033[0;105m  # Purple
On_ICyan=\033[0;106m    # Cyan
On_IWhite=\033[0;107m   # White

.SUFFIXES:
.SUFFIXES: .c .o
#Program name
NAME	= fractol

# Compiler
CC		= cc
CFLAGS	= -Werror -Wextra -Wall

# Minilibx
MLX_PATH	= libs/minilibx-linux/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libs/libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC			=	-I ./includes/\
				-I ./libs/libft/\
				-I ./libs/minilibx-linux/

# Sources
SRC_PATH	=	srcs/
SRC			=	fractol.c \
				init.c \
				render.c \
				utils.c \
				events.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/
	@mkdir $(OBJ_PATH)color_schemes/

$(MLX):
	@make -sC $(MLX_PATH)
	@echo "\n$(BGreen)miniLibX ready !$(END)$(BWhite)\n\n...\n$(END)"
	

$(LIBFT):
	@make -sC $(LIBFT_PATH)
	@echo "$(BGreen)libft ready !$(END)\n"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(INC) -lXext -lX11 -lm
	@echo "\n$(UWhite)Use following command :$(END)                                                          \n"
	@echo "              $(BICyan)./fractol mandelbrot\n$(END)                                               "
	@echo "$(BWhite)OR\n                                                                                     "
	@echo "              $(BIPurple)./fractol julia [x] [y]$(END)\n\n                                        "
	@echo "\n$(UWhite)Some interesting examples :$(END)\n                                                    "
	@echo "$(BIYellow)\n[0.3][0,5]      [0.285][0.01]                                                        "
	@echo "[-1.476][0]     [-0.12][-0.77]\n\n$(END)                                                          "
	
bonus: all

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@echo "$(Green)\nC'est propre...\n$(END)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@echo "$(BGreen)tres tres propre !\n$(END)"

re: fclean all

.PHONY: all re clean fclean%     