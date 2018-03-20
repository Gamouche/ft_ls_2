/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyfermie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:47:04 by cyfermie          #+#    #+#             */
/*   Updated: 2018/02/15 19:22:07 by cyfermie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	*ft_malloc(size_t len, int exit_value)
{
	void *ptr;

	if (!(ptr = malloc(len)))
	{
		write(STDERR_FILENO, "malloc() call failed\n", 21);
		exit(exit_value);
	}
	return (ptr);
}
