/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:14:15 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/24 14:56:18 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# define WIDTH 1280
# define HEIGHT 800
# define MAPHEIGHT 4
# define MAPWIDTH 4
# define ROTSPEED e->pl->rotSpeed
# define IMG e->img
# define WIN e->win
# define MLX e->mlx
# define SIZE e->size
# define ENDIAN e->endian
# define DATA e->data

typedef struct		s_player
{
	double			oldPlaneX;
	double			oldDirX;
	double			moveSpeed;
	double			rotSpeed;
	double			cameraX;
	double			rayPosX;
	double			rayPosY;
 	double			rayDirX;
	double			rayDirY;
	int				mapX;
	int				mapY;
	double			distMurX;
	double			distMurY;
	double			dist2MurX;
	double			dist2MurY;
	double			longueurMur;
}					t_player;

typedef struct		s_env
{
	int				worldMap[MAPWIDTH][MAPHEIGHT];
	int				stepX;
	int				stepY;
	double			posX;
	double			posY;
	double			planeX;
	double			planeY;
	double			dirX;
	double			dirY;
	int				height;
	int				width;
	void			*mlx;
	void			*img;
	void			*win;
	int				bpp;
	int				endian;
	int				size;
	int				redraw;
	char			*data;
	t_player		*pl;
}					t_env;

void				ft_init_position(t_env *e);
void				ft_init_map(t_env *e);
int					event(int key, t_env *e);

#endif
