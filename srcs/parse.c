/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 14:19:27 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 18:46:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	number_parse(t_data *data)
{
	if (data->has.dot)
	{
		while (ft_isdigit(data->copy[data->index]))
		{
			data->precision *= 10;
			data->precision += data->copy[data->index++] - '0';
		}
	}
	else
	{
		while (ft_isdigit(data->copy[data->index]))
		{
			data->width *= 10;
			data->width += data->copy[data->index++] - '0';
		}
	}
}

void	asterik_parse(t_data *data)
{
	if (data->has.dot)
		data->precision = va_arg(data->ap, int);
	else
		data->width = va_arg(data->ap, int);
	data->index++;
}

void	flag_parse(t_data *data)
{
	check_l_align_and_zero(data);
}

void	input_parse(t_data *data)
{
	if (ft_isdigit(data->copy[data->index]))
		number_parse(data);
	else if (data->copy[data->index] == '*')
		asterik_parse(data);
	if (data->copy[data->index] == '.')
	{
		data->has.dot = 1;
		data->index++;
	}
	if (ft_isdigit(data->copy[data->index]))
		number_parse(data);
	else if (data->copy[data->index] == '*')
		asterik_parse(data);
	asterik_minus_process(data);
	data->conversion = ft_substr(data->copy, data->index++, 1);
	if (data->has.zero && !data->has.dot && !data->has.l_align)
		int_swap(&data->precision, &data->width);
}
