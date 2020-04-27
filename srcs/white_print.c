/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 20:16:51 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:37:16 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	white_print(t_data *data)
{
	int		count;
	int		i;

	count = data->width - data->arglen;
	if (data->width - data->precision < count)
		count = data->width - data->precision;
	i = 0;
	while (i < count)
	{
		ft_putchar_fd(' ', 1, data);
		i++;
	}
}
