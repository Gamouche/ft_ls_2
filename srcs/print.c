/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 17:19:35 by cyfermie          #+#    #+#             */
/*   Updated: 2018/03/14 17:19:40 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "ft_ls_header.h"
#include "../libft/libft.h"

static void	long_format_option(struct stat *sstat_array, char *final_str,
									const char *pathlol, t_ls_opt *opt)
{
	print_file_type(sstat_array->st_mode, final_str);
	print_rights(sstat_array->st_mode, final_str);
	print_acl(pathlol, final_str);
	print_nb_links(sstat_array->st_nlink, final_str);
	print_username(final_str, sstat_array->st_uid, opt);
	if (opt->o == false)
		print_groupname(final_str, sstat_array->st_gid, opt);
	print_size_file_or_major_minor(final_str, sstat_array->st_mode,
						sstat_array->st_rdev, sstat_array->st_size);
	print_date(sstat_array->st_mtime, final_str);
}

void		print(const char *s, struct stat *sstat_array, t_ls_opt *opt,
												const char *pathlol)
{
	char	final_str[100000];
	bool	ret_add_color;

	final_str[0] = '\0';
	if (((opt->big_a == true && (ft_strcmp(s, ".") == 0
	|| ft_strcmp(s, "..") == 0))
	&& opt->d == false) || ((opt->a == false && s[0] == '.')
	&& opt->big_a == false && opt->d == false))
		return ;
	if (opt->i == true)
		print_inode(sstat_array->st_ino, final_str);
	if (opt->l == true)
		long_format_option(sstat_array, final_str, pathlol, opt);
	if (opt->big_g == true)
		ret_add_color = add_color(final_str, sstat_array);
	ft_strcat(final_str, s);
	if (opt->big_g == true && ret_add_color == true)
		ft_strcat(final_str, EOC);
	if (opt->p == true && S_ISDIR(sstat_array->st_mode))
		ft_strcat(final_str, "/");
	else if (opt->l == true && S_ISLNK(sstat_array->st_mode))
		print_symbolic_link(final_str, pathlol);
	ft_strcat(final_str, "\n");
	if (write(STDOUT_FILENO, final_str, ft_strlen(final_str)) == -1)
		my_exit(FATAL_ERROR, "call to write() failed\n");
}

bool		add_color(char *final_str, struct stat *sstat_array)
{
	mode_t	mode;

	mode = sstat_array->st_mode;
	if (S_ISDIR(mode))
		if ((mode & S_IWOTH) && (mode & S_ISVTX))
			ft_strcat(final_str, BLACK) && ft_strcat(final_str, F_GREEN);
		else if ((mode & S_IWOTH) && !(mode & S_ISVTX))
			ft_strcat(final_str, BLUE) && ft_strcat(final_str, F_YELLOW);
		else
			ft_strcat(final_str, BOLD) && ft_strcat(final_str, CYAN);
	else if (S_ISLNK(mode))
		ft_strcat(final_str, MAGENTA);
	else if (S_ISCHR(mode))
		ft_strcat(final_str, BLUE) && ft_strcat(final_str, F_YELLOW);
	else if (S_ISBLK(mode))
		ft_strcat(final_str, BLUE) && ft_strcat(final_str, F_CYAN);
	else if (S_ISFIFO(mode))
		ft_strcat(final_str, YELLOW);
	else if (S_ISSOCK(mode))
		ft_strcat(final_str, GREEN);
	else if (mode & S_IXUSR)
		ft_strcat(final_str, RED);
	else
		return (false);
	return (true);
}
