/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:57:31 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 13:57:33 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static void	ft_reverse(char *tab)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = ft_strlen(tab) - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		++i;
		--j;
	}
}

char		*ft_ftoa(double f, int sign)
{
	char		tab[512];
	size_t		i;
	long long	ll;
	double		ff;
	char		*str_final;

	ft_memset(tab, ((i = 0) ? '\0' : '\0'), sizeof(tab));
	ll = (long long)f;
	if ((ll *= 10) == 0)
		tab[i++] = '0';
	while ((ll /= 10) > 0)
		tab[i++] = (int)(ll % 10) + '0';
	ft_reverse(tab);
	tab[i++] = '.';
	ff = (double)(((double)f) - ((long long)f));
	while (i < sizeof(tab))
		if (((long long)(ff * 10)) < 0 ||
				((tab[i++] = ((long long)(ff *= 10)) % 10 + '0') ? 0 : 0))
			break ;
	if ((str_final = malloc(i + sign + 1)) == NULL)
		return (NULL);
	str_final[i + sign] = '\0';
	ft_memcpy(str_final + sign, tab, i);
	str_final[0] = (sign == 1) ? ('-') : (str_final[0]);
	return (str_final);
}
