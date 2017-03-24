/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:14:06 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/24 15:14:36 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		pixel(int x, int y, int i, t_env *e)
{
	int		pos;

	pos = (x * (BPP / 8)) + (y * e->size);
	if (i == e->iter)
	{
		DATA[pos] = 0;
		DATA[pos + 1] = 0;
		DATA[pos + 2] = 0;
		DATA[pos + 3] = 0;
	}
	else
	{
		DATA[pos] = i * e->b;
		DATA[pos + 1] = i * e->g;
		DATA[pos + 2] = i * e->r;
		DATA[pos + 3] = 0;
	}
}
