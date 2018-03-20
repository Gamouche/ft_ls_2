/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:28:14 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/31 20:28:18 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h>
#include <stddef.h>
#include "../libft/includes/libft.h"
#include "ft_ls_header.h"

static void	sort_ascii(char **paths, size_t nb_elem)
{
	size_t	i;
	size_t	j;
	char	*swap;

	i = 0;
	while (i < nb_elem - 1)
	{
		j = 0;
		while (j < nb_elem - 1)
		{
			if (ft_strcmp(paths[j], paths[j + 1]) > 0)
			{
				swap = paths[j];
				paths[j] = paths[j + 1];
				paths[j + 1] = swap;
			}
			++j;
		}
		++i;
	}
}

static void	sort_reverse(char **paths)
{
	size_t	start;
	size_t	end;
	char	*swap;

	start = 0;
	end = 0;
	while (paths[end] != NULL)
		++end;
	end -= 1;
	while (start < end)
	{
		swap = paths[start];
		paths[start] = paths[end];
		paths[end] = swap;
		++start;
		--end;
	}
}

static void	for_the_norme_lol(int *ret, const char *one_path)
{
	*ret = LS_ERROR;
	ft_putstr_fd("ft_ls: ", STDERR_FILENO);
	ft_putstr_fd(one_path, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
}

static int	print_no_such_file_or_directory(char **paths)
{
	size_t		i;
	struct stat sstat;
	int			ret;

	ret = LS_SUCCESS;
	i = 0;
	while (paths[i] != NULL)
	{
		errno = 0;
		if (lstat(paths[i], &sstat) == -1)
		{
			if (errno == EBADF)
			{
				ft_putstr_fd(paths[i], STDERR_FILENO);
				ft_putstr_fd(": Bad file descriptor\n", STDERR_FILENO);
			}
			else if (errno != EACCES && errno != ENOENT && errno != ENOTDIR)
				my_exit(FATAL_ERROR, "lstat() call failed\n");
			else if (errno == ENOENT)
				for_the_norme_lol(&ret, paths[i]);
		}
		++i;
	}
	return (ret);
}

int			sort_paths(t_ls_opt *opt, char **paths)
{
	int		ret;
	size_t	nb_elem;

	nb_elem = 0;
	while (paths[nb_elem] != NULL)
		++nb_elem;
	if (opt->f == false)
		sort_ascii(paths, nb_elem);
	ret = print_no_such_file_or_directory(paths);
	if (opt->big_s == true)
		sort_paths_by_size(paths, nb_elem);
	else if (opt->t == true)
		sort_paths_by_time_last_modif(paths, nb_elem);
	if (opt->r == true)
		sort_reverse(paths);
	if (opt->d == false)
		sort_files_before_directories(paths, nb_elem);
	return (ret);
}
