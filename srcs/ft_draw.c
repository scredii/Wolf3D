/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:14:06 by abourgeu          #+#    #+#             */
/*   Updated: 2017/05/01 12:29:53 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_color(t_env *e)
{
	int		color;

	if (SIDE)
	{
		if (e->stepY < 0)
			color = 0xF00a1f0;
		else
			color = 0xFF00ffec;
	}
	else
	{
		if (e->stepX < 0)
			color = 0xF6f00ff;
		else
			color = 0x0ad29a;
	}
	return (color);
}

void		pixel(int x, t_env *e)
{
	int		pos;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		pos = (x * (e->bpp / 8)) + (y * e->size);
		if (y < e->drawEnd && y > e->drawStart)
		{
			e->wall = ft_color(e);
			DATA[pos] = e->wall;
			DATA[pos + 1] = e->wall >> 8;
			DATA[pos + 2] = e->wall >> 16;
		}
		else
			pixel_2(e, y, pos);
	}
}

void		pixel_2(t_env *e, int y, int pos)
{
	if (y >= e->drawEnd)
	{
		DATA[pos] = e->floor;
		DATA[pos + 1] = e->floor >> 8;
		DATA[pos + 2] = e->floor >> 16;
	}
	else
	{
		DATA[pos] = e->roof;
		DATA[pos + 1] = e->roof >> 8;
		DATA[pos + 2] = e->roof >> 16;
	}
}
