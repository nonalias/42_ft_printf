/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 22:03:36 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:44:07 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_c(t_data *data)
{
	char	argument;

	argument = va_arg(data->ap, int);
	data->arglen = 1;
	if (data->has.l_align == 0)
	{
		white_print(data);
		ft_putchar_fd(argument, 1, data);
	}
	else
	{
		ft_putchar_fd(argument, 1, data);
		white_print(data);
	}
}
