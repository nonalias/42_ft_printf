/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:42:40 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/25 17:18:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*s1mover;
	char	*s2mover;
	size_t	i;

	s1mover = (char *)s1;
	s2mover = (char *)s2;
	i = 0;
	while (i < n && (*s1mover || *s2mover))
	{
		if (*s1mover != *s2mover)
			return ((unsigned char)*s1mover - (unsigned char)*s2mover);
		s1mover++;
		s2mover++;
		i++;
	}
	return (0);
}
