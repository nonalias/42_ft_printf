/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put16base_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 17:24:55 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/25 17:20:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put16base_fd(long long num, int fd)
{
	if (num > 15)
		ft_put16base_fd(num / 16, fd);
	write(fd, &"0123456789abcdef"[num % 16], 1);
}
