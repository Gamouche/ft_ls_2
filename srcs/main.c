/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:52:51 by cyfermie          #+#    #+#             */
/*   Updated: 2018/01/25 18:19:52 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "ft_ls_header.h"

static void	test_malloc(void)
{
	void	*test;

	test = malloc(128);
	if (test == NULL)
		my_exit(FATAL_ERROR, "Call to malloc() failed\n");
	free(test);
}

int			main(int argc, char **argv)
{
	int			etagere;
	t_ls_opt	opt;
	char		**paths;

	test_malloc();
	paths = NULL;
	get_arg_opt(argc, argv + 1, &opt, &paths);
	etagere = ft_ls(&opt, paths);
	free(paths);
	return (etagere);
}
