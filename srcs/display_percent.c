/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:55:14 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:45:34 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_percent(t_data *data)
{
	data->arglen = 1;
	if (data->has.dot)
		data->precision = 0;
	if ((data->width > data->arglen || data->precision > data->arglen)
	&& data->has.l_align == 1)
	{
		zero_print(data);
		ft_putchar_fd('%', 1, data);
		white_print(data);
	}
	else
	{
		white_print(data);
		zero_print(data);
		ft_putchar_fd('%', 1, data);
	}
}
