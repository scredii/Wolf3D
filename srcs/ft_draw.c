/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:14:06 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/25 15:31:42 by abourgeu         ###   ########.fr       */
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
	e->roof = 0x009999D6;
	e->floor = 0xFF5B805B;
	while (++y < HEIGHT)
	{
		pos = (x * (e->bpp / 8)) + (y * e->size);
		if (e->which == 0)
			e->wall = ft_color(e);
		// else
		// 	e->wall = pixel_text(e);
		if (y < e->drawEnd  &&  y > e->drawStart )
		{
			DATA[pos] = e->wall;
			DATA[pos + 1] = e->wall >> 6;
			DATA[pos + 2] = e->wall >> 12;
		}
		else if (y > e->drawEnd)
		{
			DATA[pos] = e->floor;
			DATA[pos + 1] = e->floor;
			DATA[pos + 2] = e->floor;
		}
		else
		{
			DATA[pos] = e->roof;
			DATA[pos + 1] = e->roof >> 6;
			DATA[pos + 2] = e->roof >> 12;
		}
	}
}
