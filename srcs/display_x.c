/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:32:25 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:41:54 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_x(t_data *data)
{
	int		argument;

	argument = va_arg(data->ap, int);
	data->arglen = ft_hexlen(argument);
	if ((data->width > data->arglen || data->precision > data->arglen)
	&& data->has.l_align == 1)
	{
		zero_print(data);
		ft_putnbr_x_fd(argument, 1, data);
		white_print(data);
	}
	else
	{
		white_print(data);
		zero_print(data);
		ft_putnbr_x_fd(argument, 1, data);
	}
	data->len += data->arglen;
}
