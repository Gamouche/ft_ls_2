/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:47:53 by cyfermie          #+#    #+#             */
/*   Updated: 2018/02/04 17:47:55 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/stat.h>
#include "../libft/libft.h"
#include "ft_ls_header.h"

static void	sort_ascii(char **array, size_t nb_elem, struct stat *sstat_array)
{
	size_t		i;
	size_t		j;
	char		*swap;
	struct stat swap_stat;

	i = 0;
	while (i < nb_elem - 1)
	{
		j = 0;
		while (j < nb_elem - 1)
		{
			if (ft_strcmp(array[j], array[j + 1]) > 0)
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				swap_stat = sstat_array[j];
				sstat_array[j] = sstat_array[j + 1];
				sstat_array[j + 1] = swap_stat;
			}
			++j;
		}
		++i;
	}
}

static void	sort_files_by_size(char **array, size_t nb_elem,
									struct stat *sstat_array)
{
	size_t		i;
	size_t		j;
	char		*swap;
	struct stat swap_stat;

	i = 0;
	while (i < nb_elem - 1)
	{
		j = 0;
		while (j < nb_elem - 1)
		{
			if (sstat_array[j].st_size < sstat_array[j + 1].st_size)
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				swap_stat = sstat_array[j];
				sstat_array[j] = sstat_array[j + 1];
				sstat_array[j + 1] = swap_stat;
			}
			++j;
		}
		++i;
	}
}

static void	sort_files_by_time_last_modif(char **array, size_t nb_elem,
									struct stat *sstat_array)
{
	size_t		i;
	size_t		j;
	char		*swap;
	struct stat swap_stat;

	i = 0;
	while (i < nb_elem - 1)
	{
		j = 0;
		while (j < nb_elem - 1)
		{
			if (sstat_array[j].st_mtime < sstat_array[j + 1].st_mtime)
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
				swap_stat = sstat_array[j];
				sstat_array[j] = sstat_array[j + 1];
				sstat_array[j + 1] = swap_stat;
			}
			++j;
		}
		++i;
	}
}

static void	sort_reverse(char **array, size_t nb_elem, struct stat *sstat_array)
{
	size_t		start;
	size_t		end;
	char		*swap;
	struct stat swap_stat;

	start = 0;
	end = nb_elem - 1;
	while (start < end)
	{
		swap = array[start];
		array[start] = array[end];
		array[end] = swap;
		swap_stat = sstat_array[start];
		sstat_array[start] = sstat_array[end];
		sstat_array[end] = swap_stat;
		++start;
		--end;
	}
}

void		sort_files(char **array, size_t nb_elem, t_ls_opt *opt,
										struct stat *sstat_array)
{
	if (opt->f == false)
		sort_ascii(array, nb_elem, sstat_array);
	if (opt->big_s == true)
		sort_files_by_size(array, nb_elem, sstat_array);
	else if (opt->t == true)
		sort_files_by_time_last_modif(array, nb_elem, sstat_array);
	if (opt->r == true)
		sort_reverse(array, nb_elem, sstat_array);
}
