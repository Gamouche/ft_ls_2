# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 20:58:27 by cyfermie          #+#    #+#              #
#    Updated: 2018/03/19 20:58:28 by cyfermie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Environment
OS :=						$(shell uname)

#	Output
NAME :=						ft_ls

#	Compiler
CC :=						gcc
VERSION :=					-std=c11

#	Flags:
ifneq ($(OS), Linux)
	FLAGS +=				-Wall -Wextra -Werror 
endif

HEADERS :=					-I ./includes/
O_FLAG :=					-O0 -g

#	Directories
LIBFTDIR =					./libft/
OBJDIR :=					./build/

SRCS_DIR :=					./srcs/

#	Sources
SRC +=						main.c algo_ls.c algo_ls_2.c errors.c ft_ls.c get_arg_opt.c print.c
SRC +=						print_2.c print_3.c sort_files.c sort_files_before_directories.c
SRC +=						sort_paths.c sort_time_size.c treat_a_path.c

OBJECTS =					$(patsubst %.c,$(OBJDIR)%.o,$(SRCS))

SRCS +=						$(SRC)

vpath %.c $(SRCS_DIR)

#################
##    RULES    ##
#################

all: libft $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(VERSION) $(FLAGS) $(O_FLAG) $(patsubst %.c,$(OBJDIR)%.o,$(notdir $(SRCS))) -L $(LIBFTDIR) -lft -o $@
	@printf  "\033[92m\033[1:32mCompiling -------------> \033[91m$(NAME)\033[0m:\033[0m%-14s\033[32m[✔]\033[0m\n"

$(OBJECTS): | $(OBJDIR)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o: %.c
	@printf  "\033[1:92mCompiling $(NAME)\033[0m %-29s\033[32m[$<]\033[0m\n" ""
	@$(CC) $(VERSION) $(DEBUG)$(FLAGS)$(O_FLAG) $(HEADERS) -c $< -o $@
	@printf "\033[A\033[2K"

clean:
	@/bin/rm -rf $(OBJDIR)
	@printf  "\033[1:32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-14s\033[32m[✔]\033[0m\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf  "\033[1:32mCleaning binary -------> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-14s\033[32m[✔]\033[0m\n"

libft:
	@printf "\033[92m\033[1:32mCompiling -------------> \033[91mlibft\033[0m:\033[0m%-14s\033[32m[✔]\033[0m\n"
	@$(MAKE) -C $(LIBFTDIR)

purge: fclean
	@$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean libft purge re







