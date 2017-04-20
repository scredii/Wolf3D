/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:18:44 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/19 17:30:57 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void ft_draw(t_env *e)
{
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &e->bpp, &e->size, &ENDIAN);
	ft_init_position(e);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_destroy_image(MLX, IMG);
}

void		ft_init_position(t_env *e)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		e->pl->cameraX = 2 * x / (double)WIDTH - 1;
		e->pl->rayPosX = e->posX;
		e->pl->rayPosY = e->posY;
		DIRX = e->dirX + e->planeX * e->pl->cameraX;
		DIRY = e->dirY + e->planeY * e->pl->cameraX;
		e->pl->mapX = (int)e->pl->rayPosX;
		e->pl->mapY = (int)e->pl->rayPosY;
		e->pl->dist2MurX = sqrt(1 + (DIRY * DIRY) / (DIRX * DIRX));
		e->pl->dist2MurY = sqrt(1 + (DIRX * DIRX) / (DIRY * DIRY));
		ft_calc_dist(e);
		ft_calc_height(e);
		e->lineheight = (int)(HEIGHT / e->pl->perpWallDist);
		e->drawStart = -e->lineheight / 2 + HEIGHT / 2;
		if(e->drawStart < 0)
			e->drawStart = 0;
		e->drawEnd = e->lineheight / 2 + HEIGHT / 2;
		if(e->drawEnd >= HEIGHT)
			e->drawEnd = HEIGHT - 1;
		pixel(x, e);
	}
}

void		ft_calc_dist(t_env *e)
{
	int		touch;

	touch = 0;
	if (DIRX < 0)
	{
		e->stepX = -1;
		e->pl->distMurX = (e->pl->rayPosX - e->pl->mapX) * e->pl->dist2MurX;
	}
	else
	{
		e->stepX = 1;
		e->pl->distMurX = (e->pl->mapX + 1 - e->pl->rayPosX) * e->pl->dist2MurX;
	}
	if (DIRY < 0)
	{
		e->stepY = -1;
		e->pl->distMurY = (e->pl->rayPosY - e->pl->mapY) * e->pl->dist2MurY;
	}
	else
	{
		e->stepY = 1;
		e->pl->distMurY = (e->pl->mapY + 1 - e->pl->rayPosY) * e->pl->dist2MurY;
	}
	while (touch == 0)
	{
		if (e->pl->distMurX < e->pl->distMurY)
		{
			e->pl->distMurX += e->pl->dist2MurX;
			e->pl->mapX += e->stepX;
			e->pl->side = 0;
		}
		else
		{
			e->pl->distMurY += e->pl->dist2MurY;
			e->pl->mapY += e->stepY;
			e->pl->side = 1;
		}
		if (e->tab[e->pl->mapX][e->pl->mapY] > '0')
			touch = 1;
	}
}

void ft_calc_height(t_env *e)
{
	if (e->pl->side == 0)
		e->pl->perpWallDist = (e->pl->mapX - e->pl->rayPosX + (1 - e->stepX) / 2) / DIRX;
	else
		e->pl->perpWallDist = (e->pl->mapY - e->pl->rayPosY + (1 - e->stepY) / 2) / DIRY;
}
