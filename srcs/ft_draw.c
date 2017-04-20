/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:14:06 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/20 19:19:22 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_color(t_env *e)
{
	int		color;

	if (e->pl->side)
	{
		if (e->stepY < 0)
			color = 0xFF45456;
		else
			color = 0xFFFFF5F;
	}
	else
	{
		if (e->stepX < 0)
			color = 0xFF4D656;
		else
			color = 0xFFD455F;
	}
	return (color);
}

void		pixel(int x, t_env *e)
{
	int		pos;
	int		y;
	void	*texture;
	int		lon;
	int		lar;

	y = -1;
	lon = e->drawStart;
	lar = e->drawEnd;
	e->roof = 0xFF0184F;
	e->floor = 0xFFF8494;
	texture =  mlx_xpm_file_to_image(MLX, "bluestone.xpm", &lar, &lon);
	while (++y < HEIGHT)
	{
		pos = (x * (e->bpp / 8)) + (y * e->size);
		// e->wall = ft_color(e);
		if (y < e->drawEnd  &&  y > e->drawStart )
		{
			// DATA[pos] = e->wall;
			// DATA[pos + 1] = e->wall >> 12;
			// DATA[pos + 2] = e->wall >> 6;
			DATA[pos] = (int)texture;
			DATA[pos + 1] = (int)texture;
			DATA[pos + 2] = (int)texture;
		}
		else if (y > e->drawEnd)
		{
			DATA[pos] = e->floor;
			DATA[pos + 1] = e->floor >> 12;
			DATA[pos + 2] = e->floor >> 6;
		}
		else
		{
			DATA[pos] = e->roof;
			DATA[pos + 1] = e->roof >> 12;
			DATA[pos + 2] = e->roof >> 6;
		}
	}
}




// mlx_xpm_file_to_image(mlx_ptr_t *xvar,char *file,int *width,int *height)

// mlx_xpm_file_to_image(IMG, "bright-squares.png",WIDTH, HEIGHT);
