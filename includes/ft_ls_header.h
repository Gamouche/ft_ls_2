/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:52:59 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/25 17:22:10 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_HEADER_H

# define FT_LS_HEADER_H

# include <stddef.h>
# include <stdbool.h>
# include <sys/stat.h>

# define AVAILABLE_OPT "AGRSadfilnoprt"
# define LS_SUCCESS   (0)
# define LS_ERROR (1)
# define FATAL_ERROR   (2)
# define NO_DATA_BECAUSE_NO_ACCESS (-1)
# define USER_ERROR (5)

# define EOC	"\x1B[0m"
# define BLACK  "\x1B[30m"
# define RED  "\x1B[31m"
# define GREEN  "\x1B[32m"
# define YELLOW	"\x1B[33m"
# define BLUE  "\x1B[34m"
# define MAGENTA  "\x1B[35m"
# define CYAN  "\x1B[36m"
# define WHITE  "\x1B[37m"
# define F_RED  "\x1B[41m"
# define F_GREEN  "\x1B[42m"
# define F_YELLOW	"\x1B[43m"
# define F_BLUE  "\x1B[44m"
# define F_MAGENTA  "\x1B[45m"
# define F_CYAN  "\x1B[46m"
# define F_WHITE  "\x1B[47m"
# define BOLD "\e[1m"

# define SPACES_AFTER_INO (10)
# define SIX_MONTHS (15811200)
# define USERNAME_WIDTH (20)
# define GROUPNAME_WIDTH (20)
# define SIZE_WIDTH (12)
# define MAJOR_WIDTH (5)
# define MINOR_WIDTH (5)

struct			s_ls_opt
{
	bool	l;
	bool	r;
	bool	a;
	bool	big_r;
	bool	t;

	bool	big_a;
	bool	d;
	bool	f;
	bool	big_g;
	bool	i;
	bool	n;
	bool	o;
	bool	p;
	bool	big_s;

	size_t	nb_entity_norme_lol;
	char	*path_norme_lol;
};

typedef struct s_ls_opt	t_ls_opt;

void			get_arg_opt(int argc, char **argv, t_ls_opt *opt,
												char ***paths);

int				ft_ls(t_ls_opt *opt, char **paths);

int				sort_paths(t_ls_opt *opt, char **paths);
void			sort_paths_by_size(char **paths, size_t nb_elem);
void			sort_paths_by_time_last_modif(char **paths, size_t nb_elem);
void			sort_files_before_directories(char **paths, size_t nb_elem);

int				treat_a_path(char *path, t_ls_opt *opt,
				bool print_name_dir_special_case);
int				algo_ls(char *path, t_ls_opt *opt);
void			calculate_and_print_the_total(t_ls_opt *opt, size_t nb_entity,
							char **d_name_array, struct stat *sstat_array);
void			sort_files(char **array, size_t nb_elem, t_ls_opt *opt,
										struct stat *sstat_array);
void			print_ls_output(char *path, char **d_name_array,
					struct stat *sstat_array, t_ls_opt *opt);
void			recur(t_ls_opt *opt, char **d_name_array,
				struct stat *sstat_array, int *ret_value);
void			free_algo_ls(char **d_name_array, struct stat *sstat_array);

void			print(const char *s, struct stat *sstat_array, t_ls_opt *opt,
														const char *pathlol);
void			print_inode(ino_t ino, char *final_str);
void			print_file_type(mode_t mode, char *final_str);
void			print_rights(mode_t mode, char *final_str);
void			print_acl(const char *filename, char *final_str);
void			print_nb_links(nlink_t nlink, char *final_str);
void			print_username(char *final_str, uid_t uid, t_ls_opt *opt);
void			print_groupname(char *final_str, gid_t gid, t_ls_opt *opt);
void			print_size_file_or_major_minor(char *final_str, mode_t mode,
													dev_t rdev, off_t size);
void			print_date(time_t mtime, char *final_str);
void			print_symbolic_link(char *final_str, const char *pathlol);
bool			add_color(char *final_str, struct stat *sstat_array);

void			illegal_opt(char bad_opt);
void			my_exit(int exit_value, const char *msg);

#endif
