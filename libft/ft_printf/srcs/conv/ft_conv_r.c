/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:09:44 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 16:09:49 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static void	ft_init_conv_r(int *i, int *taille, int *len, va_list ap)
{
	*i = 0;
	*taille = 0;
	*len = va_arg(ap, int);
}

static int	ft_joinstr(char **tmp, char *str, int i, int *taille)
{
	if (!(*tmp = ft_int_to_base(str[i], "0123456789ABCDEF")))
		return (ERROR);
	if (!(*tmp = ft_strjoin("<0x", *tmp)))
		return (ERROR);
	if (!(*tmp = ft_strjoin(*tmp, ">")))
		return (ERROR);
	*taille = (str[i] < 16) ? 5 : 6;
	return (SUCCESS);
}

static int	ft_conv_r_done(char **ret, t_arg *arg, va_list ap, char *str)
{
	char	*tmp;
	int		i;
	int		taille;
	int		len;

	ft_init_conv_r(&i, &taille, &len, ap);
	while (len > 0 && len--)
		if (str[i] < 127 && str[i] >= 32)
		{
			if (!(*ret = ft_strfreejoin(*ret, ft_strsub(str, i, 1), 1, arg)))
				return (ERROR);
			arg->cmpt += (i++) ? 1 : 1;
		}
		else if (str[i] == 127 || (str[i] < 32 && str[i] >= 0))
		{
			if (ft_joinstr(&tmp, str, i, &taille) == ERROR)
				return (ERROR);
			if (!(*ret = ft_strfreejoin(*ret, tmp, taille, arg)))
				return (ERROR);
			free(tmp);
			arg->cmpt += (i++) ? taille : taille;
		}
		else
			return (ERROR);
	return (SUCCESS);
}

int			ft_conv_r(char **ret, t_arg *arg, va_list ap)
{
	char	*str;

	str = (char *)arg->arg.s;
	if (str == NULL)
	{
		if (!(*ret = ft_strfreejoin(*ret, "(null)", 6, arg)))
			return (ERROR);
		arg->cmpt += 6;
		return (SUCCESS);
	}
	return (ft_conv_r_done(ret, arg, ap, str));
}
