/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:49:18 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:49:19 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int			ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*str;
	int		ret;

	str = NULL;
	ret = ft_vasprintf(&str, format, ap);
	if (ret != ERROR && str != NULL)
		if (write(fd, str, ret) == -1)
			ret = ERROR;
	free(str);
	return (ret);
}
