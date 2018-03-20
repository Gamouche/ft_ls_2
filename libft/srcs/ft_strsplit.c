/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:07:51 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/09 16:33:30 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_nb_str(const char *s, char c)
{
	size_t	nb_str;

	nb_str = 0;
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		if (*s != '\0')
			++nb_str;
		while (*s != c && *s != '\0')
			++s;
	}
	return (nb_str);
}

static int		alloc_the_str(char **strsplit, const char *s, char c)
{
	size_t	index;
	size_t	nb_ch;

	index = 0;
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		nb_ch = 0;
		while (*s != c && *s != '\0')
		{
			++s;
			++nb_ch;
		}
		if (nb_ch != 0)
		{
			strsplit[index] = (char *)malloc(sizeof(char) * (nb_ch + 1));
			if (strsplit[index] == NULL)
				return (0);
			++index;
		}
	}
	return (1);
}

static void		fill_strsplit(char **strsplit, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		j = 0;
		while (*s != c && *s != '\0')
		{
			strsplit[i][j] = *s;
			++j;
			++s;
		}
		if (j > 0)
			strsplit[i][j] = '\0';
		++i;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**strsplit;
	size_t	nb_str;

	if (s == NULL)
		return (NULL);
	nb_str = get_nb_str(s, c);
	strsplit = (char **)malloc(sizeof(char *) * (nb_str + 1));
	if (strsplit == NULL)
		return (NULL);
	strsplit[nb_str] = NULL;
	if (alloc_the_str(strsplit, s, c) == 0)
		return (NULL);
	fill_strsplit(strsplit, s, c);
	return (strsplit);
}
