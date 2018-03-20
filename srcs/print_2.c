/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:45:24 by cyfermie          #+#    #+#             */
/*   Updated: 2018/03/15 15:45:26 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/stat.h>
#include <errno.h>
#include "ft_ls_header.h"
#include "../libft/libft.h"

void	print_symbolic_link(char *final_str, const char *pathlol)
{
	ssize_t len;
	char	buf_lnk[1024];

	if ((len = readlink(pathlol, buf_lnk, sizeof(buf_lnk) - 1)) == -1)
		my_exit(FATAL_ERROR, "readlink() call failed\n");
	buf_lnk[len] = '\0';
	ft_strcat(final_str, " -> ");
	ft_strcat(final_str, buf_lnk);
}

void	print_size_file_or_major_minor(char *final_str, mode_t mode, dev_t rdev,
																	off_t size)
{
	char	str_number[50];
	size_t	i;
	size_t	end_loop;

	if (S_ISBLK(mode) || S_ISCHR(mode))
	{
		ft_strcat(final_str, ft_itoa2(major(rdev), str_number));
		ft_strcat(final_str, ",");
		end_loop = MAJOR_WIDTH - ft_strlen(str_number);
		i = 0;
		while (i < end_loop)
			((i = i + 1)) && ft_strcat(final_str, " ");
		ft_strcat(final_str, ft_itoa2(minor(rdev), str_number));
		end_loop = MINOR_WIDTH - ft_strlen(str_number);
		i = 0;
		while (i < end_loop)
			((i = i + 1)) && ft_strcat(final_str, " ");
	}
	else
	{
		(!(i = 0)) && ft_strcat(final_str, ft_itoa2(size, str_number));
		end_loop = SIZE_WIDTH - ft_strlen(str_number);
		while (i < end_loop)
			((i = i + 1)) && ft_strcat(final_str, " ");
	}
}

void	print_groupname(char *final_str, gid_t gid, t_ls_opt *opt)
{
	struct group	*gr;
	char			str_number[50];
	size_t			i;
	size_t			end_loop;

	errno = 0;
	if (opt->n == true || ((gr = getgrgid(gid)) == NULL))
	{
		if (errno != 0)
			my_exit(FATAL_ERROR, "call to getgrgid() failed\n");
		ft_strcat(final_str, ft_itoa2(gid, str_number));
		i = 0;
		end_loop = GROUPNAME_WIDTH - ft_strlen(str_number);
		while (i < end_loop)
			((i = i + 1)) && ft_strcat(final_str, " ");
	}
	else
	{
		ft_strcat(final_str, gr->gr_name);
		i = 0;
		end_loop = GROUPNAME_WIDTH - ft_strlen(gr->gr_name);
		while (i < end_loop)
			((i = i + 1)) && ft_strcat(final_str, " ");
	}
}

void	print_username(char *final_str, uid_t uid, t_ls_opt *opt)
{
	struct passwd	*s_passwd;
	size_t			i;
	size_t			end_loop;
	char			str_number[50];

	errno = 0;
	if (opt->n == true || ((s_passwd = getpwuid(uid)) == NULL))
	{
		if (errno != 0)
			my_exit(FATAL_ERROR, "getpwuid() call failed\n");
		ft_strcat(final_str, ft_itoa2(uid, str_number));
		i = 0;
		end_loop = USERNAME_WIDTH - ft_strlen(str_number);
		while (i < end_loop)
			((i = i + 1)) && ft_strcat(final_str, " ");
	}
	else
	{
		ft_strcat(final_str, s_passwd->pw_name);
		i = 0;
		end_loop = USERNAME_WIDTH - ft_strlen(s_passwd->pw_name);
		while (i < end_loop)
			((i = i + 1)) && ft_strcat(final_str, " ");
	}
}

void	print_nb_links(nlink_t nlink, char *final_str)
{
	char	str_number[50];

	ft_strcat(final_str, ft_itoa2(nlink, str_number));
	if (nlink < 10)
		ft_strcat(final_str, "   ");
	else if (nlink > 9 && nlink < 100)
		ft_strcat(final_str, "  ");
	else if (nlink > 99 && nlink < 1000)
		ft_strcat(final_str, " ");
}
