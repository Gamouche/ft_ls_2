# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 19:38:21 by cyfermie          #+#    #+#              #
#    Updated: 2018/02/15 19:43:00 by cyfermie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_putendl.c \
		  ft_putnbr.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_strcmp.c \
		  ft_strncmp.c \
		  ft_strcpy.c \
		  ft_strncpy.c \
		  ft_strcat.c \
		  ft_strncat.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_atoi.c \
		  ft_itoa.c \
		  ft_strstr.c \
		  ft_strnstr.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_memalloc.c \
		  ft_memdel.c \
		  ft_strnew.c \
		  ft_strdel.c \
		  ft_strclr.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strequ.c \
		  ft_strnequ.c \
		  ft_strsub.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_strsplit.c \
		  ft_strdup.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlcat.c \
		  ft_lstnew.c \
		  ft_lstdelone.c \
		  ft_lstdel.c \
		  ft_lstadd.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_iseven.c \
		  ft_isodd.c \
		  ft_del_2d_char_array.c \
		  ft_str_remove_ch.c \
		  ft_power.c \
		  ft_fruit.c \
		  ft_realloc.c \
		  ft_ftoa.c \
		  ft_strndup.c \
		  ft_islower.c \
		  ft_isupper.c \
		  ft_malloc.c \
		  ft_itoa2.c \
		  autre/ft_int_to_base.c \
		  autre/ft_2arg.c \
		  autre/ft_base_to_int.c \
		  autre/ft_get2arg.c \
		  autre/ft_int_to_nbase.c \
		  autre/ft_abs.c \
		  ft_printf/srcs/printf/ft_printf.c \
		  ft_printf/srcs/printf/ft_vprintf.c \
		  ft_printf/srcs/printf/ft_dprintf.c \
		  ft_printf/srcs/printf/ft_vdprintf.c \
		  ft_printf/srcs/printf/ft_asprintf.c \
		  ft_printf/srcs/printf/ft_vasprintf.c \
		  ft_printf/srcs/color/ft_color.c \
		  ft_printf/srcs/color/ft_init_color.c \
		  ft_printf/srcs/check/ft_parse.c \
		  ft_printf/srcs/check/ft_check.c \
		  ft_printf/srcs/check/ft_initarg.c \
		  ft_printf/srcs/check/ft_forest.c \
		  ft_printf/srcs/check/ft_checkconv.c \
		  ft_printf/srcs/check/ft_cleanstars.c \
		  ft_printf/srcs/check/ft_cleanstars2.c \
		  ft_printf/srcs/conv/ft_wchart.c \
		  ft_printf/srcs/conv/ft_wchart_2.c \
		  ft_printf/srcs/conv/ft_getheight.c \
		  ft_printf/srcs/conv/ft_precision_e.c \
		  ft_printf/srcs/conv/ft_precision_e_2.c \
		  ft_printf/srcs/conv/ft_conv_bigs.c \
		  ft_printf/srcs/conv/ft_conv_bigs_2.c \
		  ft_printf/srcs/conv/ft_conv_s.c \
		  ft_printf/srcs/conv/ft_fill_str_ud.c \
		  ft_printf/srcs/conv/ft_conv_d.c \
		  ft_printf/srcs/conv/ft_conv_o.c \
		  ft_printf/srcs/conv/ft_conv_u.c \
		  ft_printf/srcs/conv/ft_conv_x.c \
		  ft_printf/srcs/conv/ft_conv_c.c \
		  ft_printf/srcs/conv/ft_conv_k.c \
		  ft_printf/srcs/conv/ft_conv_n.c \
		  ft_printf/srcs/conv/ft_conv_b.c \
		  ft_printf/srcs/conv/ft_conv_w.c \
		  ft_printf/srcs/conv/ft_conv_f.c \
		  ft_printf/srcs/conv/ft_flags_f.c \
		  ft_printf/srcs/conv/ft_arrondis_f.c \
		  ft_printf/srcs/conv/ft_conv_e.c \
		  ft_printf/srcs/conv/ft_conv_g.c \
		  ft_printf/srcs/conv/ft_conv_g_annexe.c \
		  ft_printf/srcs/conv/ft_conv_r.c \
		  ft_printf/srcs/conv/ft_conv_modulo.c \
		  ft_printf/srcs/conv/ft_conv_invalid.c \
		  ft_printf/srcs/conv/ft_regle_zero.c \
		  ft_printf/srcs/conv/ft_arrondis_f.c \
		  ft_printf/srcs/ft_strfreejoin.c 
		  


CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3

OBJ = $(notdir $(SRCS:.c=.o))

all: $(NAME)

$(NAME):
	@$(CC) -c $(SRCS) $(CFLAGS) -I ft_printf/includes -I . 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
