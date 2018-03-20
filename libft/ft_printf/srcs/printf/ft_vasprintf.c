/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:49:10 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/13 15:51:37 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_2.h>

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_arg	arg;
	void	*check_malloc;

	arg.cmpt = 0;
	if ((check_malloc = malloc(1)) == NULL)
		return (ERROR);
	free(check_malloc);
	if (ret == NULL)
		return (ERROR);
	if (ft_parse(ret, format, ap, &arg) == ERROR)
		return (ERROR);
	if (ft_color(ret, &arg) == ERROR)
		return (ERROR);
	return (arg.cmpt);
}
