/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files_before_directories.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 20:17:25 by cyfermie          #+#    #+#             */
/*   Updated: 2018/03/17 20:17:27 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stddef.h>
#include <errno.h>
#include "../libft/libft.h"
#include "ft_ls_header.h"

static void	init_arrays_to_null(char **other_array, char **dir_array,
													size_t nb_elem)
{
	size_t	i;

	i = 0;
	while (i < nb_elem + 1)
	{
		dir_array[i] = NULL;
		other_array[i] = NULL;
		++i;
	}
}

static void	check_error_lstat_failed(int errno_value, const char *path)
{
	if (errno_value == EBADF)
	{
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": Bad file descriptor\n", STDERR_FILENO);
	}
	else if (errno_value != EACCES && errno_value != ENOENT
	&& errno_value != ENOTDIR)
		my_exit(FATAL_ERROR, "lstat() call failed\n");
}

static void	fill_other_and_dir_arrays(char **paths, char **dir_array,
												char **other_array)
{
	size_t		dir_index;
	size_t		other_index;
	size_t		i;
	struct stat	sstat;

	i = 0;
	dir_index = 0;
	other_index = 0;
	while (paths[i] != NULL)
	{
		errno = 0;
		if (lstat(paths[i], &sstat) == -1)
			check_error_lstat_failed(errno, paths[i]);
		if (errno == 0 && S_ISDIR(sstat.st_mode))
		{
			dir_array[dir_index] = paths[i];
			++dir_index;
		}
		else
		{
			other_array[other_index] = paths[i];
			++other_index;
		}
		++i;
	}
}

void		sort_files_before_directories(char **paths, size_t nb_elem)
{
	char		**dir_array;
	char		**other_array;
	size_t		i;
	size_t		j;

	dir_array = ft_malloc(sizeof(char *) * (nb_elem + 1), FATAL_ERROR);
	other_array = ft_malloc(sizeof(char *) * (nb_elem + 1), FATAL_ERROR);
	init_arrays_to_null(other_array, dir_array, nb_elem);
	fill_other_and_dir_arrays(paths, dir_array, other_array);
	i = 0;
	j = 0;
	while (other_array[i] != NULL)
	{
		paths[j] = other_array[i];
		++j;
		++i;
	}
	i = 0;
	while (dir_array[i] != NULL)
	{
		paths[j] = dir_array[i];
		++j;
		++i;
	}
	ft_fruit(2, dir_array, other_array);
}
