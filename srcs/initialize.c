/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 14:17:55 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:39:33 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initialize(t_data *data, const char *format)
{
	data->source = format;
	data->copy = (char *)data->source;
	data->arglen = 0;
	data->index = 0;
	data->precision = 0;
	data->width = 0;
	data->has.dot = 0;
	data->len = 0;
	data->has.l_align = 0;
	data->has.zero = 0;
	data->conversion = NULL;
}

void	reinitialize(t_data *data)
{
	data->has.l_align = 0;
	data->has.zero = 0;
	data->arglen = 0;
	data->precision = 0;
	data->width = 0;
	data->has.dot = 0;
	data->conversion = NULL;
	data->index++;
}
