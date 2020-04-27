/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterik_minus_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 14:22:08 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 18:45:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	asterik_minus_process(t_data *data)
{
	if (data->precision < 0)
	{
		data->precision = 0;
		data->has.dot = 0;
	}
	if (data->width < 0)
	{
		data->has.l_align = 1;
		data->width *= -1;
	}
}
