/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:24:47 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:43:04 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_u(t_data *data)
{
	unsigned int argument;

	argument = va_arg(data->ap, unsigned int);
	data->arglen = ft_intlen(argument);
	if ((data->width > data->arglen || data->precision > data->arglen)
	&& data->has.l_align == 1)
	{
		zero_print(data);
		ft_putnbr_fd(argument, 1, data);
		white_print(data);
	}
	else
	{
		white_print(data);
		zero_print(data);
		ft_putnbr_fd(argument, 1, data);
	}
	data->len += data->arglen;
}
