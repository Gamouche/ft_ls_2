/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:45:30 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:45:31 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static int	ft_checklimit(char const *format, int i, char **expression)
{
	int		index;
	int		nbchar;

	index = i;
	nbchar = 1;
	while (ft_strchr("+- 0#123456789.*lhzjtq", format[i]) != NULL
			&& format[i] != '\0')
	{
		++i;
		++nbchar;
	}
	if (format[i] == '\0')
		return (-i);
	if ((*expression = ft_strsub(format, index, nbchar)) == NULL)
		return ((int)(ft_strlen(format) + 10));
	return (nbchar);
}

static int	ft_norminette(char **ret, t_arg *arg, int x)
{
	if (ft_strcmp(*ret, "") == 0)
		return (ERROR);
	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		write(STDOUT_FILENO, *ret, arg->cmpt - x);
	return (ERROR);
}

static int	ft_fill_l(int *i, const char *format, char **ret, t_arg *arg)
{
	char *tmp;

	if ((tmp = ft_strsub(format, *i, 1)) == NULL)
		return (ERROR);
	if ((*ret = ft_strfreejoin(*ret, tmp, 1, arg)) == NULL)
		return (ERROR);
	arg->cmpt += 1;
	++(*i);
	free(tmp);
	return (SUCCESS);
}

int			ft_parse(char **str, const char *format, va_list ap, t_arg *arg)
{
	static int	i = 0;
	int			nbchar;
	char		*expression;
	static int	x = 0;

	nbchar = ((i *= 0) && (x *= 0)) ? 1 : 1;
	if ((*str = ft_strnew(0)) == NULL)
		return (ERROR);
	while (format[i] && i < (int)ft_strlen(format))
		if (format[i] == '%' && ++i)
		{
			if ((nbchar = ft_checklimit(format, i, &expression))
					== (int)(ft_strlen(format) + 10))
				return (ERROR);
			if (nbchar <= 0 && ((i += -nbchar) ? 1 : 1))
				continue;
			if (ft_check(str, expression, ap, arg) == ERROR)
				return (ft_norminette(str, arg, x));
			x = ((i += nbchar) && (nbchar -= nbchar - 1)) ? 0 : 0;
		}
		else if (i < (int)ft_strlen(format))
			if (++x && ft_fill_l(&i, format, str, arg) == ERROR)
				return (ERROR);
	return (SUCCESS);
}
