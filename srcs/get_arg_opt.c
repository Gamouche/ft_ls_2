/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_opt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:52:54 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/25 20:21:55 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "ft_ls_header.h"
#include "../libft/includes/libft.h"

static void	init_opt(t_ls_opt *opt)
{
	opt->l = false;
	opt->r = false;
	opt->a = false;
	opt->big_r = false;
	opt->t = false;
	opt->big_a = false;
	opt->d = false;
	opt->f = false;
	opt->big_g = false;
	opt->i = false;
	opt->n = false;
	opt->o = false;
	opt->p = false;
	opt->big_s = false;
}

static void	stock_option(char c_opt, t_ls_opt *opt)
{
	opt->l = (c_opt == 'l') ? true : opt->l;
	opt->r = (c_opt == 'r') ? true : opt->r;
	opt->a = (c_opt == 'a') ? true : opt->a;
	opt->big_r = (c_opt == 'R') ? true : opt->big_r;
	opt->t = (c_opt == 't') ? true : opt->t;
	opt->big_a = (c_opt == 'A') ? true : opt->big_a;
	opt->d = (c_opt == 'd') ? true : opt->d;
	opt->f = (c_opt == 'f') ? true : opt->f;
	opt->big_g = (c_opt == 'G') ? true : opt->big_g;
	opt->i = (c_opt == 'i') ? true : opt->i;
	opt->n = (c_opt == 'n') ? true : opt->n;
	opt->o = (c_opt == 'o') ? true : opt->o;
	opt->p = (c_opt == 'p') ? true : opt->p;
	opt->big_s = (c_opt == 'S') ? true : opt->big_s;
}

static void	check_opt(const char *arg, t_ls_opt *opt)
{
	size_t		i;

	i = 1;
	while (arg[i] != '\0')
	{
		if (ft_strchr(AVAILABLE_OPT, arg[i]) == NULL)
			illegal_opt(arg[i]);
		stock_option(arg[i], opt);
		++i;
	}
}

static void	priority_opt(t_ls_opt *opt)
{
	if (opt->a == true)
		opt->big_a = false;
	if (opt->n == true)
		opt->l = true;
	if (opt->big_s == true)
		opt->t = false;
	if (opt->f == true)
	{
		opt->a = true;
		opt->t = false;
		opt->big_s = false;
		opt->r = false;
	}
	if (opt->o == true)
		opt->l = true;
	if (opt->d == true)
		opt->big_r = false;
	if (opt->big_a == true)
		opt->a = true;
}

void		get_arg_opt(int argc, char **argv, t_ls_opt *opt, char ***paths)
{
	size_t	i;
	size_t	paths_index;

	i = 0;
	paths_index = 0;
	init_opt(opt);
	while (argv[i] != NULL && argv[i][0] == '-' && argv[i][1] != '\0')
	{
		check_opt(argv[i], opt);
		++i;
	}
	priority_opt(opt);
	if (argc - i < 2)
		return ;
	*paths = ft_malloc(sizeof(char *) * (argc - i), FATAL_ERROR);
	(*paths)[argc - i - 1] = NULL;
	while (argv[i] != NULL)
	{
		(*paths)[paths_index] = argv[i];
		++paths_index;
		++i;
	}
}
