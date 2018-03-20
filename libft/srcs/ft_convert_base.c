/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:56:56 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 13:56:58 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char		*ft_convert_base(char *n, char *base_in, char *base_out)
{
	long long	int_nb;
	char		*ret;

	int_nb = ft_base_to_int(n, base_in);
	if (!(ret = ft_int_to_base(int_nb, base_out)))
		return (NULL);
	return (ret);
}
