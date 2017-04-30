/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:18:44 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/30 16:30:19 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_ray(t_env *e)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		ft_init_cam(e, x);
		ft_get_dist(e);
		ft_wall_length(e);
		ft_maj_pos(e);
		pixel(x, e);
	}
}

void		ft_init_cam(t_env *e, int x)
{
	e->pl->cameraX = 2 * x / (double)WIDTH - 1;
	e->pl->rayPosX = e->pos_init_X;
	e->pl->rayPosY = e->pos_init_Y;
	DIRX = e->view_x + e->planeX * e->pl->cameraX;
	DIRY = e->view_y + e->planeY * e->pl->cameraX;
	e->pl->mapX = (int)e->pl->rayPosX;
	e->pl->mapY = (int)e->pl->rayPosY;
	e->pl->Dist2WallX = sqrt(1 + (DIRY * DIRY) / (DIRX * DIRX));
	e->pl->Dist2WallY = sqrt(1 + (DIRX * DIRX) / (DIRY * DIRY));
}

void		ft_maj_pos(t_env *e)
{
	e->lineheight = fabs(HEIGHT / PPWDIST);
	e->drawStart = -e->lineheight / 2 + HEIGHT / 2;
	if (e->drawStart < 0)
		e->drawStart = 0;
	e->drawEnd = e->lineheight / 2 + HEIGHT / 2;
	if (e->drawEnd >= HEIGHT)
		e->drawEnd = HEIGHT - 1;
}

void		ft_get_dist(t_env *e)
{
	int		touch;

	touch = 0;
	get_dirx(e);
	get_diry(e);
	while (touch == 0)
	{
		if (DISTWX < DISTWY)
		{
			DISTWX += e->pl->Dist2WallX;
			e->pl->mapX += e->stepX;
			SIDE = 0;
		}
		else
		{
			DISTWY += e->pl->Dist2WallY;
			e->pl->mapY += e->stepY;
			SIDE = 1;
		}
		if (e->tab[e->pl->mapX][e->pl->mapY] > '0' &&
				e->tab[e->pl->mapX][e->pl->mapY] != 's')
			touch = 1;
	}
}

void		ft_wall_length(t_env *e)
{
	if (SIDE == 0)
		PPWDIST = (e->pl->mapX - e->pl->rayPosX + (1 - e->stepX) / 2) / DIRX;
	else
		PPWDIST = (e->pl->mapY - e->pl->rayPosY + (1 - e->stepY) / 2) / DIRY;
}
