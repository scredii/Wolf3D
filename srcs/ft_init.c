/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:18:44 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/25 15:31:30 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// int pixel_text(t_env *e)
// {
// 	int	color;
// 	int x;
//
// 	x = -1;
// 	while (++x < 4)
// 		color = e->pl->text_data[0][x] + e->pl->text_data[0][x + 1] * 256 + e->pl->text_data[0][x + 2] * 65536;
// 	return (color);
// }
//
// void		ft_init_text(t_env *e)
// {
// 	int x;
// 	int y;
//
// 	x = 64;
// 	y = 64;
//
// 	if (!(e->pl->text_data = (char**)malloc(sizeof(char*) * 10000)))
// 		exit(write(1, "Error\n", 6));
// 	e->pl->texture[0] = mlx_xpm_file_to_image(MLX, "42.xpm", &y, &x);
// 	e->pl->text_data[0] = mlx_get_data_addr(e->pl->texture[0], &e->bpp, &e->size, &ENDIAN);
//
// }

// void		ft_anim_text(t_env *e)
// {
// 	int i;
// 	int x;
// 	int y;
//
// 	e->pl->texture = malloc(sizeof(int*) * 64);
// 	e->pl->tex_width = 64;
// 	e->pl->tex_height = 64;
// 	i = -1;
// 	x = -1;
// 	y = -1;
// 	while (++i < 8)
// 		e->pl->texture[i] = malloc(sizeof(int) * e->pl->tex_width * e->pl->tex_height);
// 	while (++x < e->pl->tex_width)
// 	{
// 		while (++y < e->pl->tex_height)
// 			ft_init_text(e, x, y);
// 		y = -1;
// 	}
// }

void		ft_draw(t_env *e)
{

	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &e->bpp, &e->size, &ENDIAN);
	// ft_init_text(e);
	ft_map(e);
	// ft_anim_text(e);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_destroy_image(MLX, IMG);
}

void		ft_init_cam(t_env *e, int x)
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
}

void		ft_maj_pos(t_env *e)
{
	e->lineheight = (int)(HEIGHT / e->pl->perpWallDist);
	e->drawStart = -e->lineheight / 2 + HEIGHT / 2;
	if(e->drawStart < 0)
		e->drawStart = 0;
	e->drawEnd = e->lineheight / 2 + HEIGHT / 2;
	if(e->drawEnd >= HEIGHT)
		e->drawEnd = HEIGHT - 1;
}

void		ft_map(t_env *e)
{
	int		x;

	x = -1;
	while (++x < WIDTH)
	{
		ft_init_cam(e, x);
		ft_get_dist(e);
		ft_wall_length(e);
		ft_maj_pos(e);
		// if (e->which == 0)
			pixel(x, e);
		// else
			// pixel_text(x, e);
	}
}

void		ft_get_dist(t_env *e)
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
			SIDE = 0;
		}
		else
		{
			e->pl->distMurY += e->pl->dist2MurY;
			e->pl->mapY += e->stepY;
			SIDE = 1;
		}
		if (e->tab[e->pl->mapX][e->pl->mapY] > '0')
			touch = 1;
	}
}

void		ft_wall_length(t_env *e)
{
	if (SIDE == 0)
		e->pl->perpWallDist = (e->pl->mapX - e->pl->rayPosX + (1 - e->stepX) / 2) / DIRX;
	else
		e->pl->perpWallDist = (e->pl->mapY - e->pl->rayPosY + (1 - e->stepY) / 2) / DIRY;
	ft_wallX_value(e);

}

void		ft_wallX_value(t_env *e)
{
	if (SIDE == 0)
		e->pl->wallX = e->pl->rayPosY + e->pl->perpWallDist * DIRY;
	else
		e->pl->wallX = e->pl->rayPosX + e->pl->perpWallDist * DIRX;
	e->pl->wallX -= floor((e->pl->wallX));
	e->pl->texX = (int)e->pl->wallX * (double)64;
	if(SIDE == 0 && DIRX > 0)
		e->pl->texX = 64 - e->pl->texX - 1;
	if(SIDE == 1 && DIRY < 0)
		e->pl->texX = 64 - e->pl->texX - 1;
	e->pl->texX *= 4;
}
