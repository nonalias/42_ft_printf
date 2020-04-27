/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 23:03:55 by marvin            #+#    #+#             */
/*   Updated: 2020/04/27 17:43:48 by taehkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_l_align_and_zero(t_data *data)
{
	while (data->copy[data->index] == '-' || data->copy[data->index] == '0')
	{
		if (data->copy[data->index] == '-')
			data->has.l_align = 1;
		else
			data->has.zero = 1;
		data->index++;
	}
}
