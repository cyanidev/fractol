# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afelicia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 17:08:26 by afelicia          #+#    #+#              #
#    Updated: 2023/03/04 17:56:49 by afelicia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Program name
NAME = fractol

#Path to the MLX42 library
LIBMLX = ./lib/MLX42

#Path to the header files that will be used
HEADERS = -I ./include -I $(LIBMLX)/include

#libraries linked to the program
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

#Sources (command 'find' to locate all source files in 'src' directory with the extension '.c')
SRCS = ${shell find ./src -iname "*.c"}

#Objects
OBJS = ${SRCS:.c=.o}

#Compiler flags
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast -Lmlx -framework Cocoa -framework OpenGL -framework IOKit

#Compile
CC = gcc

#Force remove
RM = rm -f

#########################COLORS####################################

BLACK =	\033[0;30m
RED	=	\033[0;31m
GREEN =	\033[0;32m
YELLOW =	\033[0;33m
BLUE  =	\033[0;34m
MAGENTA =	\033[0;35m
CYAN =	\033[0;36m
LGRAY = \033[0;37m
DGRAY = \033[1;30m
LBLUE = \033[1;34m
LGREEN = \033[1;32m
LCYAN = \033[1;36m
LRED = \033[1;31m
LMAGENTA =\033[1;35m
LYELLOW = \033[1;33m
WHITE = \033[1;37m
RESET = \033[0m

###################################################################

#Compiles the MLX42 library by running 'cmake' and 'make'
libmlx:	
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

#Compiles the program by linking the object files with the libraries and outputting an ex file
${NAME}: ${OBJS} $(LIBS)
		@printf "${LCYAN}Making $@${RESET}"
		${CC} ${CFLAGS} ${HEADERS} -o ${NAME} ${OBJS} ${LIBS}
		@printf "${GREEN}Complete${RESET}"

#Defines a rule for generating object files 
${OBJS}%.o: ${SRCS}%.c
	${CC} ${CFLAGS} -Imlx -c $< -o $@ ${HEADERS}

#Removes all objects files
clean:
	@${RM} ${OBJS}
	@${RM} ${LIBMLX}/build
	@printf "${LGREEN}Objects cleaned from ${WHITE}${CURDIR}${RESET}"

#compiles both the MLX42 lib and the program
all: libmlx ${NAME}

#calls the 'clear' rule also removes executable file
fclean: clean
	${RM} ${NAME}
	@printf "${LRED}Binary ${LYELLOW}${NAME} ${LRED}has been deleted${RESET}"

#removes all and compiles MLX and program
re: fclean all

#Defines a list of targets that do not correspond to files(make will always 
#execute the recipes for these targets, even if there are files or directories
#with the same names)
.PHONY: all clean fclean re libmlx

