/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:12:18 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/25 18:18:57 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft/libft.h"
#include "ft_ls_header.h"

void	illegal_opt(char bad_opt)
{
	char tab[2];

	tab[0] = bad_opt;
	tab[1] = '\0';
	ft_putstr_fd("ft_ls: illegal option -- ", STDERR_FILENO);
	ft_putstr_fd(tab, STDERR_FILENO);
	ft_putstr_fd("\nusage: ft_ls [-", STDERR_FILENO);
	ft_putstr_fd(AVAILABLE_OPT, STDERR_FILENO);
	ft_putstr_fd("] [file ...]\n", STDERR_FILENO);
	exit(LS_ERROR);
}

void	my_exit(int exit_value, const char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(exit_value);
}
