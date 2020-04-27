/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:01:14 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/27 11:39:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void		ft_putnbr_fd(long long temp, int fd, t_data *data)
{
	if (temp == 0 && data->precision == 0 && data->has.dot)
	{
		data->arglen = 0;
		if (data->width && !data->has.l_align)
			ft_putchar_fd(' ', 1, data);
		return ;
	}
	if (temp < 0)
	{
		write(fd, &"-"[0], 1);
		temp = -temp;
	}
	if (temp > 9)
		ft_putnbr_fd(temp / 10, fd, data);
	write(fd, &"0123456789"[temp % 10], 1);
}
