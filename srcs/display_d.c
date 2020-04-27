/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 20:27:10 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:42:42 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	minus_print(t_data *data, int is_minus)
{
	if (is_minus)
		ft_putchar_fd('-', 1, data);
}

void	argument_minus_process(t_data *data, long *argument, int *is_minus)
{
	*is_minus = 0;
	if (*argument < 0)
	{
		if (data->has.zero && !data->has.dot)
			data->precision--;
		data->width--;
		(*argument) *= -1;
		*is_minus = 1;
	}
}

void	display_d(t_data *data)
{
	long	argument;
	int		is_minus;

	argument = va_arg(data->ap, int);
	data->arglen = ft_intlen(argument);
	argument_minus_process(data, &argument, &is_minus);
	if ((data->width > data->arglen || data->precision > data->arglen)
	&& data->has.l_align == 1)
	{
		minus_print(data, is_minus);
		zero_print(data);
		ft_putnbr_fd(argument, 1, data);
		white_print(data);
	}
	else
	{
		white_print(data);
		minus_print(data, is_minus);
		zero_print(data);
		ft_putnbr_fd(argument, 1, data);
	}
	data->len += data->arglen;
}
