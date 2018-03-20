/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 19:28:40 by cyfermie          #+#    #+#             */
/*   Updated: 2018/03/13 19:28:44 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include "../libft/libft.h"
#include "ft_ls_header.h"

static int	check_opendir_failure(int errno_value, char *path)
{
	char *tmp;

	tmp = &(path[ft_strlen(path) - 1]);
	if (errno_value != EACCES && errno_value != ENOTDIR)
		my_exit(FATAL_ERROR, "call to opendir() failed\n");
	ft_putstr_fd("ft_ls: ", STDERR_FILENO);
	if (errno_value == EACCES)
	{
		while (tmp != path)
		{
			if (*tmp == '/' && ++tmp)
				break ;
			--tmp;
		}
		ft_putstr_fd(((*tmp == '/') ? (tmp + 1) : (tmp)), STDERR_FILENO);
		ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
	}
	else if (errno_value == ENOTDIR)
	{
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": Bad file descriptor\n", STDERR_FILENO);
	}
	return (LS_ERROR);
}

static void	count_and_init_entities(size_t *nb_entity, char ***d_name_array,
										struct stat **sstat_array, DIR *dir)
{
	struct dirent	*sdir;

	*nb_entity = 0;
	while ((sdir = readdir(dir)) != NULL)
		++(*nb_entity);
	*d_name_array = ft_malloc(sizeof(char *) * ((*nb_entity) + 1), FATAL_ERROR);
	(*d_name_array)[*nb_entity] = NULL;
	*sstat_array = ft_malloc(sizeof(struct stat) * (*nb_entity), FATAL_ERROR);
}

static void	fill_d_name_array(DIR *dir, char **d_name_array, char *path)
{
	size_t			i;
	struct dirent	*sdir;

	closedir(dir);
	if ((dir = opendir(path)) == NULL)
		my_exit(FATAL_ERROR, "opendir() call failed\n");
	i = 0;
	while ((sdir = readdir(dir)) != NULL)
	{
		d_name_array[i] = ft_strdup(sdir->d_name);
		if (d_name_array[i] == NULL)
			my_exit(FATAL_ERROR, "ft_strdup() call failed (malloc() used)\n");
		++i;
	}
	closedir(dir);
}

static void	fill_sstat_array(size_t *nb_entity, char *path,
			char **d_name_array, struct stat *sstat_array)
{
	char	tmp_array[1024];
	size_t	i;

	tmp_array[0] = '\0';
	i = 0;
	while (i < *nb_entity)
	{
		ft_strcpy(tmp_array, path);
		ft_strcat(tmp_array, "/");
		ft_strcat(tmp_array, d_name_array[i]);
		errno = 0;
		if (lstat(tmp_array, sstat_array + i) == -1)
		{
			if (errno == EBADF)
			{
				ft_putstr_fd(tmp_array, STDERR_FILENO);
				ft_putstr_fd(": Bad file descriptor\n", STDERR_FILENO);
			}
			else if (errno != EACCES && errno != ENOENT && errno != ENOTDIR)
				my_exit(FATAL_ERROR, "Call to lstat() failed\n");
			--i;
			--(*nb_entity);
		}
		++i;
	}
}

int			algo_ls(char *path, t_ls_opt *opt)
{
	DIR				*dir;
	size_t			nb_entity;
	char			**d_name_array;
	struct stat		*sstat_array;
	int				ret_value;

	ret_value = LS_SUCCESS;
	errno = 0;
	if ((dir = opendir(path)) == NULL)
		return (check_opendir_failure(errno, path));
	count_and_init_entities(&nb_entity, &d_name_array, &sstat_array, dir);
	fill_d_name_array(dir, d_name_array, path);
	fill_sstat_array(&nb_entity, path, d_name_array, sstat_array);
	calculate_and_print_the_total(opt, nb_entity, d_name_array, sstat_array);
	if (nb_entity > 0)
		sort_files(d_name_array, nb_entity, opt, sstat_array);
	opt->nb_entity_norme_lol = nb_entity;
	print_ls_output(path, d_name_array, sstat_array, opt);
	if (opt->big_r == true && (opt->path_norme_lol = path))
	{
		opt->nb_entity_norme_lol = nb_entity;
		recur(opt, d_name_array, sstat_array, &ret_value);
	}
	free_algo_ls(d_name_array, sstat_array);
	return ((opt->big_r == true) ? (ret_value) : (LS_SUCCESS));
}
