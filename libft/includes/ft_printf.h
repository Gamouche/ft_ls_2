/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:03:46 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 17:03:48 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <wchar.h>

# define EOC	"\x1B[0m"

# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENTA  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"

# define F_RED  "\x1B[41m"
# define F_GREEN  "\x1B[42m"
# define F_YELLOW	"\x1B[43m"
# define F_BLUE  "\x1B[44m"
# define F_MAGENTA  "\x1B[45m"
# define F_CYAN  "\x1B[46m"
# define F_WHITE  "\x1B[47m"

# define CLEAR "\033[H\033[2J"

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list ap);
int			ft_dprintf(int fd, const char *format, ...);
int			ft_vdprintf(int fd, const char *format, va_list ap);
int			ft_asprintf(char **str, const char *format, ...);
int			ft_vasprintf(char **ret, const char *format, va_list ap);

#endif
