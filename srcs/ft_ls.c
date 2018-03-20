/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:37:44 by cyfermie          #+#    #+#             */
/*   Updated: 2018/03/19 17:37:45 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "../libft/includes/libft.h"
#include "ft_ls_header.h"

static size_t	get_nb_elem(char **paths)
{
	size_t nb_elem;

	nb_elem = 0;
	while (paths[nb_elem] != NULL)
		++nb_elem;
	return (nb_elem);
}

static void		special_case_if_no_arg(char ***paths)
{
	*paths = ft_malloc(sizeof(char *) * 2, FATAL_ERROR);
	(*paths)[0] = ".";
	(*paths)[1] = NULL;
}

static int		print_no_such_file_or_dir(const char *path)
{
	int dummy;

	dummy = 42;
	ft_putstr_fd("ft_ls: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	return (dummy);
}

int				ft_ls(t_ls_opt *opt, char **paths)
{
	int		ret_value;
	int		ret_final;
	size_t	index;
	bool	need_free;
	size_t	nb_elem;

	ret_value = LS_SUCCESS;
	if ((!(need_free = false)) && paths != NULL && paths[1] != NULL)
		ret_value = sort_paths(opt, paths);
	ret_final = ret_value;
	if (paths == NULL && (need_free = true))
		special_case_if_no_arg(&paths);
	nb_elem = get_nb_elem(paths);
	index = 0;
	while (paths[index] != NULL)
	{
		if ((ret_value = treat_a_path(paths[index], opt, (nb_elem > 1)))
		== USER_ERROR && nb_elem == 1)
			print_no_such_file_or_dir(paths[index]) && (ret_final = LS_ERROR);
		if (ret_value == LS_ERROR)
			ret_final = LS_ERROR;
		++index;
	}
	free((need_free == true) ? paths : NULL);
	return (ret_final);
}
