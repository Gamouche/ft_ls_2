/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_ls_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:45:48 by cyfermie          #+#    #+#             */
/*   Updated: 2018/03/19 17:45:49 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "../libft/includes/libft.h"
#include "ft_ls_header.h"

void		calculate_and_print_the_total(t_ls_opt *opt, size_t nb_entity,
							char **d_name_array, struct stat *sstat_array)
{
	size_t		total_long_format;
	size_t		i;
	const char	*s;

	if ((!(i = 0)) && (opt->l == true && nb_entity >= 2)
	&& !(opt->a == false && nb_entity == 2))
	{
		total_long_format = 0;
		while (i < nb_entity)
		{
			s = d_name_array[i];
			if ((opt->a == false && opt->big_a == true
			&& (ft_strcmp(s, ".") == 0 || ft_strcmp(s, "..") == 0))
			&& opt->d == false && ++i)
				continue ;
			if ((opt->a == false && s[0] == '.') && opt->big_a == false
			&& opt->d == false && ++i)
				continue ;
			total_long_format += sstat_array[i].st_blocks;
			++i;
		}
		write(STDOUT_FILENO, "total ", 6);
		ft_putnbr(total_long_format);
		ft_putchar('\n');
	}
}

static void	recall_algo_ls(char *path, char *one_d_name_array,
								int *ret_value, t_ls_opt *opt)
{
	int		tmp_ret_value;
	char	tmpbufwrite[10000];
	char	tmp[10000];

	tmp[0] = '\0';
	if (path[ft_strlen(path) - 1] == '/')
	{
		ft_strcat(tmp, path);
		ft_strcat(tmp, one_d_name_array);
	}
	else
	{
		ft_strcat(tmp, path);
		ft_strcat(tmp, "/");
		ft_strcat(tmp, one_d_name_array);
	}
	tmpbufwrite[0] = '\0';
	ft_strcat(tmpbufwrite, "\n");
	ft_strcat(tmpbufwrite, tmp);
	ft_strcat(tmpbufwrite, ":\n");
	if (write(STDOUT_FILENO, tmpbufwrite, ft_strlen(tmpbufwrite)) == -1)
		my_exit(FATAL_ERROR, "call to write() failed\n");
	tmp_ret_value = algo_ls(tmp, opt);
	if (tmp_ret_value == LS_ERROR)
		*ret_value = LS_ERROR;
}

void		recur(t_ls_opt *opt, char **d_name_array, struct stat *sstat_array,
																int *ret_value)
{
	size_t	i;
	size_t	nb_entity;
	char	*path;

	nb_entity = opt->nb_entity_norme_lol;
	path = opt->path_norme_lol;
	i = 0;
	while (i < nb_entity)
	{
		if (ft_strcmp(d_name_array[i], ".") != 0
		&& ft_strcmp(d_name_array[i], "..") != 0)
			if (!(opt->a == false && d_name_array[i][0] == '.'))
				if (S_ISDIR(sstat_array[i].st_mode))
					recall_algo_ls(path, d_name_array[i], ret_value, opt);
		++i;
	}
}

void		print_ls_output(char *path, char **d_name_array,
					struct stat *sstat_array, t_ls_opt *opt)
{
	size_t	i;
	char	pathlol[2048];
	size_t	nb_entity;

	nb_entity = opt->nb_entity_norme_lol;
	i = 0;
	while (i < nb_entity)
	{
		ft_strcpy(pathlol, path);
		ft_strcat(pathlol, "/");
		ft_strcat(pathlol, d_name_array[i]);
		print(d_name_array[i], sstat_array + i, opt, pathlol);
		++i;
	}
}

void		free_algo_ls(char **d_name_array, struct stat *sstat_array)
{
	size_t	i;

	i = 0;
	while (d_name_array[i] != NULL)
	{
		free(d_name_array[i]);
		++i;
	}
	free(d_name_array);
	free(sstat_array);
}
