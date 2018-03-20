/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:47:18 by cyfermie          #+#    #+#             */
/*   Updated: 2018/03/15 15:47:19 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/acl.h>
#include <sys/xattr.h>
#include <time.h>
#include <sys/stat.h>
#include "ft_ls_header.h"
#include "../libft/includes/libft.h"

void	print_inode(ino_t ino, char *final_str)
{
	ssize_t i;
	ssize_t end_loop;
	char	str_number[50];

	ft_strcat(final_str, ft_itoa2(ino, str_number));
	i = 0;
	end_loop = SPACES_AFTER_INO - ft_strlen(str_number);
	while (i < end_loop)
	{
		ft_strcat(final_str, " ");
		++i;
	}
}

void	print_acl(const char *filename, char *final_str)
{
	ssize_t		listxattr_ret;
	acl_t		acl;

	acl = NULL;
	if (filename == NULL)
	{
		ft_strcat(final_str, "   ");
		return ;
	}
	listxattr_ret = listxattr(filename, NULL, 0, XATTR_NOFOLLOW);
	if (listxattr_ret == -1)
		listxattr_ret = 0;
	if (listxattr_ret > 0)
		ft_strcat(final_str, "@  ");
	else if ((acl = acl_get_file(filename, ACL_TYPE_EXTENDED)) != NULL)
		ft_strcat(final_str, "+  ");
	else
		ft_strcat(final_str, "   ");
	acl_free(acl);
}

void	print_date(time_t mtime, char *final_str)
{
	char		*ctime_ret;
	time_t		current_time;
	uint64_t	foo;

	if ((ctime_ret = ctime(&mtime)) == NULL)
		my_exit(FATAL_ERROR, "ctime() failed in function print_date()\n");
	if ((current_time = time(NULL)) == (time_t)-1)
		my_exit(FATAL_ERROR, "time() failed in function print_date()\n");
	foo = (current_time - mtime < 0) ?
	((uint64_t)((current_time - mtime) * (-1)))
	: ((uint64_t)(current_time - mtime));
	ctime_ret[24] = '\0';
	ctime_ret += 4;
	if (foo > SIX_MONTHS)
	{
		ctime_ret[6] = '\0';
		ft_strcat(final_str, ctime_ret);
		ft_strcat(final_str, ctime_ret + 15);
		ft_strcat(final_str, "   ");
		return ;
	}
	else
		ctime_ret[12] = '\0';
	ft_strcat(final_str, ctime_ret) && ft_strcat(final_str, "  ");
}

void	print_file_type(mode_t mode, char *final_str)
{
	if (S_ISREG(mode))
		ft_strcat(final_str, "-");
	else if (S_ISDIR(mode))
		ft_strcat(final_str, "d");
	else if (S_ISCHR(mode))
		ft_strcat(final_str, "c");
	else if (S_ISBLK(mode))
		ft_strcat(final_str, "b");
	else if (S_ISFIFO(mode))
		ft_strcat(final_str, "p");
	else if (S_ISLNK(mode))
		ft_strcat(final_str, "l");
	else if (S_ISSOCK(mode))
		ft_strcat(final_str, "s");
}

void	print_rights(mode_t mode, char *final_str)
{
	ft_strcat(final_str, (mode & S_IRUSR) ? "r" : "-");
	ft_strcat(final_str, (mode & S_IWUSR) ? "w" : "-");
	if (mode & S_ISUID)
		ft_strcat(final_str, (mode & S_IXUSR) ? "s" : "S");
	else
		ft_strcat(final_str, (mode & S_IXUSR) ? "x" : "-");
	ft_strcat(final_str, (mode & S_IRGRP) ? "r" : "-");
	ft_strcat(final_str, (mode & S_IWGRP) ? "w" : "-");
	if (mode & S_ISGID)
		ft_strcat(final_str, (mode & S_IXGRP) ? "s" : "S");
	else
		ft_strcat(final_str, (mode & S_IXGRP) ? "x" : "-");
	ft_strcat(final_str, (mode & S_IROTH) ? "r" : "-");
	ft_strcat(final_str, (mode & S_IWOTH) ? "w" : "-");
	if (mode & S_ISVTX)
		ft_strcat(final_str, (mode & S_IXOTH) ? "t" : "T");
	else
		ft_strcat(final_str, (mode & S_IXOTH) ? "x" : "-");
}
