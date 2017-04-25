/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:12:35 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/25 15:13:30 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_loop(t_env *e)
{
	if (e->redraw)
	{
		ft_draw(e);
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
	WIN = mlx_new_window(MLX, WIDTH, HEIGHT, "=> Wolf3D <=");
	mlx_hook(WIN, KeyPress, KeyPressMask, event, e);
	// mlx_mouse_hook(WIN, ft_mouse_hook, e);
	// mlx_hook(WIN, 1, ButtonPress, event, e);
	mlx_loop_hook(MLX, ft_loop, e);
	mlx_expose_hook(WIN, ft_expose, e);
	mlx_loop(MLX);
}

void		ft_init_map(t_env *e)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_read_map("map1");
	e->tab = ft_strsplit(tmp, '\n');
	e->Xmax = ft_strlen(e->tab[0]);
	while(e->tab[++i])
		if ((size_t)e->Xmax != ft_strlen(e->tab[i]))
			exit(write(1, "Error\n", 6));
	e->Ymax = i;
	// e->pl->textNum = e->tab[e->pl->mapX][e->pl->mapY] - 1;
	free(tmp);
}

void		ft_init_env(t_env *e)
{
	// e->pl->buff = (double*)malloc(WIDTH * sizeof(double));
	e->posX = 12.50;
	e->posY = 15.50;
	e->pl->moveSpeed = 0.10;
	e->pl->rotSpeed = 0.10;
	e->dirX = -1.0;
	e->dirY = 0.0;
	e->planeX = 0.0;
	e->planeY = 0.65;
	e->redraw = 1;
	e->which = 0;
	e->pl->distMurX = 0.0;
	e->pl->distMurY = 0.0;
	e->pl->dist2MurX = 0.0;
	e->pl->dist2MurY = 0.0;
	e->pl->longueurMur = 0.0;
	e->pl->oldPlaneX = 0.0;
	e->pl->oldDirX = 0.0;
	e->pl->perpWallDist = 0.0;
	e->pl->cameraX = 0.0;
	e->pl->rayPosX = 0.0;
	e->pl->rayPosY = 0.0;
	e->pl->rayDirX = 0.0;
	e->pl->rayDirY = 0.0;
	ft_init_map(e);
}

int			main(void)
{
	t_env	*e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		exit(write(1, "Malloc failed\n", 15));
	if (!(e->pl  = (t_player*)malloc(sizeof(t_player))))
		exit(write(1, "Malloc failed\n", 15));
	ft_init_env(e);
	ft_coffee(e);
	return (0);
}
