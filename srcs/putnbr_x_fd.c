/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_x_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/19 15:51:44 by taehkim           #+#    #+#             */
/*   Updated: 2020/04/27 11:48:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_x_fd(unsigned int num, int fd, t_data *data)
{
	if (num == 0 && data->precision == 0 && data->has.dot)
	{
		data->arglen = 0;
		if (data->width && !data->has.l_align)
			ft_putchar_fd(' ', 1, data);
		return ;
	}
	if (num > 15)
		ft_putnbr_x_fd(num / 16, fd, data);
	write(fd, &"0123456789abcdef"[num % 16], 1);
}

void	ft_putnbr_large_x_fd(unsigned int num, int fd, t_data *data)
{
	if (num == 0 && data->precision == 0 && data->has.dot)
	{
		data->arglen = 0;
		if (data->width && !data->has.l_align)
			ft_putchar_fd(' ', 1, data);
		return ;
	}
	if (num > 15)
		ft_putnbr_large_x_fd(num / 16, fd, data);
	write(fd, &"0123456789ABCDEF"[num % 16], 1);
}
