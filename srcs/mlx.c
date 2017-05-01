/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:50:19 by abourgeu          #+#    #+#             */
/*   Updated: 2017/05/01 14:52:52 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_loop(t_env *e)
{
	if (e->redraw)
	{
		ft_draw(e);
		mlx_string_put(MLX, WIN, 60, 40, 0x00ff38, "Help:");
		mlx_string_put(MLX, WIN, 60, 60, 0x00ff38, "Arrows or WSAD for motion");
		mlx_string_put(MLX, WIN, 60, 80, 0x00ff38, "+ or - for MoveSpeed");
		mlx_string_put(MLX, WIN, 60, 100, 0x00ff38, "Esc for exit");
		e->redraw = 0;
	}
	return (0);
}

int			ft_expose(t_env *e)
{
	e->redraw = 1;
	if (!WIN)
		exit(0);
	return (0);
}

void		ft_coffee(t_env *e)
{
	MLX = mlx_init();
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "Wolf3D");
	mlx_hook(WIN, KeyPress, KeyPressMask, event, e);
	mlx_hook(WIN, KeyPress, KeyPressMask, event, e);
	mlx_hook(WIN, 17, (1L << 17), close_prog, e);
	mlx_loop_hook(MLX, ft_loop, e);
	mlx_expose_hook(WIN, ft_expose, e);
	mlx_loop(MLX);
}

void		ft_draw(t_env *e)
{
	IMG = mlx_new_image(MLX, WIDTH, HEIGHT);
	DATA = mlx_get_data_addr(IMG, &e->bpp, &e->size, &ENDIAN);
	ft_ray(e);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	mlx_destroy_image(MLX, IMG);
}

void		ft_error(t_env *e)
{
	if (!e->s_bool)
		exit(write(1, "Need 1 pos with 's'. \n", 22));
	if (e->Ymax > 100 || e->Xmax > 100)
		exit(write(1, "Map limit: 100*100\n", 19));
}
