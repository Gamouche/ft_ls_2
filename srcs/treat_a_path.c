/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_a_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:49:13 by cyfermie          #+#    #+#             */
/*   Updated: 2018/03/15 15:49:14 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "ft_ls_header.h"
#include "../libft/includes/libft.h"

static int	error_file_1(int errno_value, const char *path)
{
	int dummy;

	dummy = 42;
	if (errno_value == EBADF)
	{
		ft_putstr_fd("ft_ls: ", STDERR_FILENO);
		ft_putstr_fd(path, STDERR_FILENO);
		ft_putstr_fd(": Bad file descriptor\n", STDERR_FILENO);
		return (LS_ERROR);
	}
	else if (errno_value == ENOENT)
		return (USER_ERROR);
	my_exit(FATAL_ERROR, "Call to lstat() failed\n");
	return (dummy);
}

static int	error_file_2(int errno_value)
{
	int dummy;

	dummy = 42;
	if (errno_value != EACCES && errno_value != ENOENT
	&& errno_value != ENOTDIR)
		my_exit(FATAL_ERROR, "Call to stat() failed\n");
	else if (errno == ENOENT)
		return (USER_ERROR);
	return (dummy);
}

int			treat_a_path(char *path, t_ls_opt *opt,
				bool print_name_dir_special_case)
{
	struct stat sstat;
	static bool	foo = false;
	char		buf_write[2048];

	buf_write[0] = '\0';
	if ((!(errno = 0)) && lstat(path, &sstat) == -1)
		return (error_file_1(errno, path));
	if (S_ISLNK(sstat.st_mode) && opt->l == false && (!(errno = 0)))
		if ((stat(path, &sstat) == -1) && (error_file_2(errno) == USER_ERROR))
			return (USER_ERROR);
	if (S_ISDIR(sstat.st_mode) && opt->d == false)
	{
		if (foo == true)
			ft_strcat(buf_write, "\n");
		if (print_name_dir_special_case == true && (foo = true))
			ft_strcat(buf_write, path) && ft_strcat(buf_write, ":\n");
		if (write(STDOUT_FILENO, buf_write, ft_strlen(buf_write)) == -1)
			my_exit(FATAL_ERROR, "Call to write() failed\n");
		if (algo_ls(path, opt) == LS_ERROR)
			return (LS_ERROR);
	}
	else if ((foo = true))
		print(path, &sstat, opt, path);
	return (!USER_ERROR);
}
