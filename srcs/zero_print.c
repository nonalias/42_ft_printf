/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 20:16:11 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:34:04 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	zero_print(t_data *data)
{
	int		count;
	int		i;

	count = data->precision - data->arglen;
	i = 0;
	while (i < count)
	{
		ft_putchar_fd('0', 1, data);
		i++;
	}
}
