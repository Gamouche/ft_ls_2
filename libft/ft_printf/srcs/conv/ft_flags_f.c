/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:23:10 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 16:23:31 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static char	*flag_zero_f(char *str, int width, int space, t_arg *arg)
{
	size_t	s_len;
	size_t	i;
	size_t	f_zero;

	f_zero = 0;
	s_len = ft_strlen(str);
	if (!(str = ft_realloc(str, s_len + 1, s_len + 1 + width - s_len)))
		return (NULL);
	ft_memmove(str + width - s_len - space, str, s_len + 1);
	i = 0;
	if (arg->flag.zero == 1 && arg->arg.f < 0)
	{
		str[i++] = '-';
		f_zero = 1;
	}
	while (i < width - s_len - space + f_zero && i < 4242)
	{
		str[i] = '0';
		++i;
	}
	return (str);
}

static char	*flag_space_f(char *str)
{
	if (!(str = ft_realloc(str, ft_strlen(str) + 1, ft_strlen(str) + 2)))
		return (NULL);
	ft_memmove(str + 1, str, ft_strlen(str) + 1);
	str[0] = ' ';
	return (str);
}

static char	*flag_plus_f(char *str, int flag_zero)
{
	if (flag_zero == 1)
	{
		str[0] = '+';
		return (str);
	}
	if (!(str = ft_realloc(str, ft_strlen(str) + 1, ft_strlen(str) + 2)))
		return (NULL);
	ft_memmove(str + 1, str, ft_strlen(str) + 1);
	str[0] = '+';
	return (str);
}

static char	*flag_hashtag_f(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (ft_strchr(str, '.') == NULL)
	{
		if (!(str = ft_realloc(str, len + 1, len + 2)))
			return (NULL);
		str[len] = '.';
		str[len + 1] = '\0';
	}
	return (str);
}

int			ft_flags_f(char **str, int sign, t_arg *arg)
{
	if (arg->flag.zero == 1 && arg->wi > 0
			&& (size_t)arg->wi > ft_strlen(*str))
		if (!(*str = flag_zero_f(*str, arg->wi, arg->flag.space, arg)))
			return (ERROR);
	if (arg->flag.space == 1 && sign == 0)
		if (!(*str = flag_space_f(*str)))
			return (ERROR);
	if (arg->flag.plus == 1 && arg->arg.f >= 0)
		if (!(*str = flag_plus_f(*str, arg->flag.zero)))
			return (ERROR);
	if (arg->flag.hashtag == 1)
		if (!(*str = flag_hashtag_f(*str)))
			return (ERROR);
	if ((size_t)arg->wi > ft_strlen(*str) && arg->flag.minus == 0)
		if (!(*str = right_justify_f(*str, arg->wi)))
			return (ERROR);
	if ((size_t)arg->wi > ft_strlen(*str) && arg->flag.minus == 1)
		if (!(*str = left_justify_f(*str, arg->wi)))
			return (ERROR);
	return (SUCCESS);
}
