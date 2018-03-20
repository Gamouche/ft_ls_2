/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 20:21:50 by cyfermie          #+#    #+#             */
/*   Updated: 2018/03/17 20:21:51 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "ft_ls_header.h"
#include "../libft/libft.h"

static void	fill_array(char **paths, int64_t *array, bool truetime_falsesize)
{
	size_t		i;
	struct stat sstat;

	i = 0;
	while (paths[i] != NULL)
	{
		errno = 0;
		if (lstat(paths[i], &sstat) == -1)
		{
			if (errno == EACCES || errno == ENOENT || errno == ENOTDIR
			|| errno == EBADF)
				array[i] = NO_DATA_BECAUSE_NO_ACCESS;
			else
				my_exit(FATAL_ERROR, "lstat() call failed 1\n");
		}
		else
		{
			if (truetime_falsesize == true)
				array[i] = (int64_t)(sstat.st_mtime);
			else if (truetime_falsesize == false)
				array[i] = (int64_t)(sstat.st_size);
		}
		++i;
	}
}

static void	swap_lol(char **paths, size_t j, int64_t *sizes)
{
	char	*swap;
	int64_t swap2;

	swap = paths[j];
	paths[j] = paths[j + 1];
	paths[j + 1] = swap;
	swap2 = sizes[j];
	sizes[j] = sizes[j + 1];
	sizes[j + 1] = swap2;
}

void		sort_paths_by_size(char **paths, size_t nb_elem)
{
	int64_t		*sizes;
	size_t		i;
	size_t		j;

	sizes = ft_malloc(sizeof(*sizes) * nb_elem, FATAL_ERROR);
	fill_array(paths, sizes, false);
	i = 0;
	while (i < nb_elem - 1)
	{
		j = 0;
		while (j < nb_elem - 1)
		{
			if ((sizes[j] != NO_DATA_BECAUSE_NO_ACCESS
			&& sizes[j + 1] == NO_DATA_BECAUSE_NO_ACCESS)
			|| (sizes[j] < sizes[j + 1]
			&& sizes[j] != NO_DATA_BECAUSE_NO_ACCESS))
				swap_lol(paths, j, sizes);
			++j;
		}
		++i;
	}
	free(sizes);
}

void		sort_paths_by_time_last_modif(char **paths, size_t nb_elem)
{
	int64_t		*times;
	size_t		i;
	size_t		j;

	times = ft_malloc(sizeof(*times) * nb_elem, FATAL_ERROR);
	fill_array(paths, times, true);
	i = 0;
	while (i < nb_elem - 1)
	{
		j = 0;
		while (j < nb_elem - 1)
		{
			if ((times[j] != NO_DATA_BECAUSE_NO_ACCESS
			&& times[j + 1] == NO_DATA_BECAUSE_NO_ACCESS)
			|| (times[j] < times[j + 1]
			&& times[j] != NO_DATA_BECAUSE_NO_ACCESS))
				swap_lol(paths, j, times);
			++j;
		}
		++i;
	}
	free(times);
}
