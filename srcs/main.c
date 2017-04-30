/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:12:35 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/30 15:14:03 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_verif_wall(t_env *e)
{
	int 	i;

	i = -1;
	while(e->tab[0][++i])
		if (e->tab[0][i] != '1')
			exit(write(1, "Map error.\n", 11));
	i = -1;
	printf("y:%d\n", e->Ymax);
	printf("x:%d\n", e->Xmax);
	printf("%d\n", e->tab[i + 1][e->Ymax - 1]);
	// printf("1:%c\n", e->tab[i + 1][5]);
	while(e->tab[++i][e->Ymax])
	{
		printf("%c\n", e->tab[i][e->Ymax]);
		if (e->tab[i][e->Ymax] != '1')
			exit(write(1, "Map error.\n", 11));
	}
}

void		verif_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < e->Ymax)
	{
		j = 0;
		while (j < e->Xmax)
		{
			if (e->tab[i][j] != '1' && e->tab[i][j] != '0' &&
					e->tab[i][j] != 's')
				exit(write(1, "Map error.\n", 11));
			if (e->tab[i][j] == 's')
			{
				e->pos_init_X = i + 0.50;
				e->pos_init_Y = j + 0.50;
			}
			j++;
		}
		i++;
	}
	ft_verif_wall(e);
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
	verif_map(e);
	free(tmp);
}

void		ft_init_env(t_env *e)
{
	e->pos_init_X = 14.50;
	e->pos_init_Y = 15.50;
	e->pl->moveSpeed = 0.10;
	e->pl->rotSpeed = 0.10;
	e->view_x = -1.0;
	e->view_y = 0.0;
	e->planeX = 0.0;
	e->planeY = 0.65;
	e->redraw = 1;
	e->pl->DistWallX = 0.0;
	e->pl->DistWallY = 0.0;
	e->pl->Dist2WallX = 0.0;
	e->pl->Dist2WallY = 0.0;
	e->roof = 0x009999;
	e->floor = 0xCCCCFF;
	e->pl->oldDirX = 0.0;
	e->pl->perpWallDist = 0.0;
	e->pl->cameraX = 5.0;
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
