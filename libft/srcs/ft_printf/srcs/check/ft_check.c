/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:44:18 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:44:29 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static void	ft_checkflag(t_arg *arg, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '+')
			arg->flag.plus = 1;
		else if (str[i] == '#')
			arg->flag.hashtag = 1;
		else if (str[i] == '-')
			arg->flag.minus = 1;
		else if (str[i] == ' ')
			arg->flag.space = 1;
		else if ((str[i] == '0' && i == 0) ||
				(str[i] == '0' && (str[i - 1] < '0' || str[i - 1] > '9') &&
				str[i - 1] != '.' && str[i - 1] != '*'))
			arg->flag.zero = 1;
	}
}

static int	ft_checkwidth2(t_arg *arg, char *str, int *i)
{
	if ((*i == 0) || (!ft_isdigit(str[*i - 1]) && ((str[*i - 1] != '*' &&
						str[*i - 1] != '.') || (*i == 1 && str[*i - 1] != '.')
					|| (*i >= 2 && str[*i - 1] == '*' && str[*i - 2] != '.'))))
	{
		arg->wi = ft_atoi(str + *i);
		return (SUCCESS);
	}
	else if (ft_isdigit(str[*i - 1]))
	{
		while (*i >= 1 && ft_isdigit(str[*i - 1]))
			--(*i);
		if (*i == 0 || str[*i - 1] != '.')
		{
			arg->wi = ft_atoi(str + *i);
			return (SUCCESS);
		}
	}
	return (END);
}

static void	ft_checkwidth(t_arg *arg, char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (--i >= 0)
	{
		if (str[i] >= '1' && str[i] <= '9')
		{
			if (ft_checkwidth2(arg, str, &i) == SUCCESS)
				break ;
		}
		else if (i >= 1 && str[i] == '0' && str[i - 1] == '*')
		{
			if (!(i >= 2 && str[i - 2] == '.'))
			{
				arg->wi = 0;
				break ;
			}
		}
	}
}

static void	ft_checkprecision(t_arg *arg, char *str)
{
	int		i;

	i = ft_strlen(str);
	while (--i >= 0)
	{
		if (str[i] == '.')
		{
			if (str[i + 1] == '*')
				++i;
			if (str[++i] >= '0' && str[i] <= '9')
				arg->preci = ft_atoi(str + i);
			else if (str[i] == '*')
				arg->preci = -1;
			else
				arg->preci = 0;
			break ;
		}
	}
}

int			ft_check(char **ret, char *str, va_list ap, t_arg *arg)
{
	ft_initarg(arg);
	if (str != NULL)
		free(arg->str);
	arg->str = str;
	if (ft_cleanstars(&str, ap) == ERROR && ft_fruit(1, str))
		return (ERROR);
	ft_checkflag(arg, str);
	ft_checkwidth(arg, str);
	ft_checkprecision(arg, str);
	if (!(arg->str = ft_strdup(str)) && ft_fruit(2, str, arg->str))
		return (ERROR);
	if (ft_checkconv(ret, arg, ap) == ERROR && ft_fruit(2, str, arg->str))
		return (ERROR);
	ft_fruit(2, str, arg->str);
	return (SUCCESS);
}
