/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:45:49 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 20:35:28 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static int	ft_evalstr(t_color *color, char *str, size_t n)
{
	int		i;

	if (n > SIZE_COLOR_NAME)
		return (ERROR);
	i = -1;
	while (++i < NB_COLOR)
	{
		if (ft_strncmp(color[i].name, str, n) == 0)
			return (i);
	}
	return (ERROR);
}

static int	ft_put_color(t_color *color, char **str, long long pl_numc,
		t_arg *arg)
{
	int		size_del;
	int		size_add;
	char	*new_str;

	size_del = ft_strlen(color[ft_get2arg(pl_numc, 1)].name) + 2;
	size_add = ft_strlen(color[ft_get2arg(pl_numc, 1)].color);
	if (!(new_str = malloc(sizeof(char) * (ft_strlen(*str) + size_add - size_del
						+ 1))))
		return (ERROR);
	ft_strncpy(new_str, *str, ft_get2arg(pl_numc, 0));
	new_str[ft_get2arg(pl_numc, 0)] = '\0';
	ft_strncat(new_str, color[ft_get2arg(pl_numc, 1)].color, size_add);
	ft_strcat(new_str, (*str + ft_get2arg(pl_numc, 0) + size_del));
	free(*str);
	*str = new_str;
	arg->cmpt = arg->cmpt + size_add - size_del;
	return (SUCCESS);
}

static int	ft_isignore(char **str, int i)
{
	if (i == 0)
		return (0);
	if ((*str)[i - 1] == '%')
	{
		ft_memmove((*str + i - 1), (*str + i), ft_strlen(*str + i));
		if (!(*str = ft_realloc(*str, (ft_strlen(*str) + 2),
						ft_strlen(*str) + 1)))
			return (ERROR);
		return (END);
	}
	return (SUCCESS);
}

int			ft_color(char **str, t_arg *arg)
{
	t_color	color[NB_COLOR];
	int		i;
	int		j;
	int		num_c;
	int		ret;

	i = -1;
	ft_init_color(color);
	while (++i < arg->cmpt)
		if ((*str)[i] == '{' && !(j = 0) && ++i)
		{
			if ((ret = ft_isignore(str, i - 1)) == ERROR)
				return (ERROR);
			while (ret != 1 && (*str)[i + ++j] && j < 4242)
				if ((*str)[i + j] == '}')
				{
					if ((num_c = ft_evalstr(color, (*str + i), j)) != -1)
						if (ft_put_color(color, str, ft_2arg(i - 1, num_c),
									arg) == ERROR)
							return (ERROR);
					break ;
				}
		}
	return (SUCCESS);
}
