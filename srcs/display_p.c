/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:08:56 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:44:31 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_p(t_data *data)
{
	void	*argument;

	argument = va_arg(data->ap, char *);
	data->arglen = ft_ptrlen((long long)argument, data);
	if (data->has.dot && data->precision)
		data->precision += 2;
	if ((data->width > data->arglen || data->precision > data->arglen)
	&& data->has.l_align == 0)
	{
		white_print(data);
		write(1, "0x", 2);
		zero_print(data);
		if (!(!argument && data->has.dot))
			ft_put16base_fd((long long)argument, 1);
	}
	else
	{
		write(1, "0x", 2);
		zero_print(data);
		if (!(!argument && data->has.dot))
			ft_put16base_fd((long long)argument, 1);
		white_print(data);
	}
	data->len += (data->arglen);
}
