/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchart_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:56:51 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 16:57:01 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

static int	ft_tab_s(char **tab, int size, int *i)
{
	*i = 0;
	if (!(*tab = ft_strnew(size)))
		return (ERROR);
	ft_memset(*tab, ' ', size);
	return (SUCCESS);
}

int			ft_print_twob(char **ret, unsigned int wch, t_arg *arg)
{
	char			*tab;
	int				i;
	int				taille;

	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
	{
		if (ft_put_width(&tab, arg, &i, 2) == ERROR)
			return (ERROR);
	}
	else if (ft_tab_s(&tab, 2, &i) == ERROR)
		return (ERROR);
	tab[i] = ((wch >> 6) | 0xC0);
	tab[i + 1] = ((wch << 26) >> 26 | 0x80);
	taille = ft_strlen(tab);
	if (!(*ret = ft_strfreejoin(*ret, tab, taille, arg)))
		return (ERROR);
	arg->cmpt += taille;
	free(tab);
	return (SUCCESS);
}

int			ft_print_threeb(char **ret, unsigned int wch, t_arg *arg)
{
	char			*tab;
	int				i;
	int				taille;

	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		ft_put_width(&tab, arg, &i, 3);
	else
		ft_tab_s(&tab, 3, &i);
	tab[i] = ((wch >> 12) | 0xE0);
	tab[i + 1] = (((wch >> 6) << 26) >> 26 | 0x80);
	tab[i + 2] = ((wch << 26) >> 26 | 0x80);
	taille = ft_strlen(tab);
	if (!(*ret = ft_strfreejoin(*ret, tab, taille, arg)))
		return (ERROR);
	arg->cmpt += taille;
	free(tab);
	return (SUCCESS);
}

int			ft_print_fourb(char **ret, unsigned int wch, t_arg *arg)
{
	char			*tab;
	int				i;
	int				taille;

	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		ft_put_width(&tab, arg, &i, 4);
	else
		ft_tab_s(&tab, 4, &i);
	tab[i] = (wch >> 18 | 0xF0);
	tab[i + 1] = (((wch >> 12) << 26) >> 26 | 0x80);
	tab[i + 2] = (((wch >> 6) << 26) >> 26 | 0x80);
	tab[i + 3] = (((wch << 26) >> 26) | 0x80);
	taille = ft_strlen(tab);
	if (!(*ret = ft_strfreejoin(*ret, tab, taille, arg)))
		return (ERROR);
	arg->cmpt += taille;
	free(tab);
	return (SUCCESS);
}

int			ft_print_oneb(char **ret, unsigned int wch, t_arg *arg)
{
	char	*tmp;
	int		i;
	int		taille;

	i = 0;
	if (arg->conv == 'C' || (arg->conv == 'c' && ft_length_cs(arg) == ERROR))
		ft_put_width(&tmp, arg, &i, 1);
	else if (!(tmp = ft_strnew(1)))
		return (ERROR);
	tmp[i] = (char)wch;
	taille = ft_strlen(tmp);
	if (wch == 0)
		taille = 1;
	if (!(*ret = ft_strfreejoin(*ret, tmp, taille, arg)))
		return (ERROR);
	free(tmp);
	arg->cmpt += taille;
	return (SUCCESS);
}
