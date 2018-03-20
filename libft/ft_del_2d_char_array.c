/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_2d_char_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:21:59 by cyfermie          #+#    #+#             */
/*   Updated: 2017/11/11 18:22:03 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_del_2d_char_array(char ***array, size_t n)
{
	size_t	i;

	if (array == NULL || *array == NULL)
		return ;
	i = 0;
	while (i < n && (*array)[i] != NULL)
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		++i;
	}
	free(*array);
	*array = NULL;
}
