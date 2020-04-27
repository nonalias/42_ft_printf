/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 21:54:45 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:43:20 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	putnstr(char *s, int arglen)
{
	while (*s && arglen--)
	{
		write(1, &*s, 1);
		s++;
	}
}

void	s_init(t_data *data, char **argment)
{
	if (!*argment)
	{
		data->arglen = 6;
		*argment = "(null)";
	}
	else
		data->arglen = ft_strlen(*argment);
	if (data->has.dot && data->arglen >= data->precision)
		data->arglen -= (data->arglen - data->precision);
	if (!data->has.zero)
		data->precision = 0;
}

void	display_s(t_data *data)
{
	char	*argment;

	argment = va_arg(data->ap, char *);
	s_init(data, &argment);
	if (data->has.l_align == 0)
	{
		white_print(data);
		zero_print(data);
		putnstr(argment, data->arglen);
	}
	else
	{
		zero_print(data);
		putnstr(argment, data->arglen);
		white_print(data);
	}
	data->len += data->arglen;
}
