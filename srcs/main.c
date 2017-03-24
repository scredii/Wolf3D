/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:12:35 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/24 15:04:41 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_loop(t_env *e)
{
	if (e->redraw)
	{
		// ft_draw(e);
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
	WIN = mlx_new_window(MLX, 512, 384, "=> Wolf3D <=");
	mlx_key_hook(WIN, event, e);
	// mlx_mouse_hook(WIN, ft_mouse_hook, e);
	// mlx_hook(WIN, 6, (1L << 8), ft_mouse, e);
	mlx_loop_hook(MLX, ft_loop, e);
	mlx_expose_hook(WIN, ft_expose, e);
	mlx_loop(MLX);
}

void		ft_init_env(t_env *e)
{
	e->posX = 2;
	e->posY = 2;
	e->dirX = -1;
	e->dirY = 0;
	e->planeX = 0;
	e->planeY = 0.66;
	// ft_init_position(e);
}

int			main(void)
{
	t_env	*e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		exit(write(1, "Malloc failed\n", 15));
	ft_init_map(e);
	// ft_init_player();
	ft_coffee(e);
	return (0);
}
