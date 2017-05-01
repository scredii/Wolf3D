/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:14:15 by abourgeu          #+#    #+#             */
/*   Updated: 2017/05/01 14:54:08 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# define WIDTH 1600
# define HEIGHT 1200
# define PPWDIST e->pl->perpWallDist
# define DISTWX e->pl->DistWallX
# define DISTWY e->pl->DistWallY
# define MSPEED e->pl->moveSpeed
# define INITY e->pos_init_Y
# define INITX e->pos_init_X
# define SIDE e->pl->side
# define DIRY e->pl->rayDirY
# define DIRX e->pl->rayDirX
# define OLDDX e->pl->oldDirX
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
	double			perpWallDist;
	double			moveSpeed;
	double			rotSpeed;
	double			cameraX;
	double			rayPosX;
	double			rayPosY;
	double			rayDirX;
	double			rayDirY;
	double			DistWallX;
	double			DistWallY;
	double			Dist2WallX;
	double			Dist2WallY;
	int				mapX;
	int				mapY;
	int				side;
}					t_player;

typedef struct		s_env
{
	int				s_bool;
	double			pos_init_X;
	double			pos_init_Y;
	double			planeX;
	double			planeY;
	double			view_x;
	double			view_y;
	int				lineheight;
	int				drawStart;
	int				drawEnd;
	int				Xmax;
	int				Ymax;
	int				stepX;
	int				stepY;
	int				wall;
	int				floor;
	int				roof;
	int				bpp;
	int				endian;
	int				size;
	int				redraw;
	char			*data;
	char			**tab;
	void			*img;
	void			*win;
	void			*mlx;
	t_player		*pl;
}					t_env;

int					close_prog(t_env *e);
void				ft_error(t_env *e);
void				get_diry(t_env *e);
void				get_dirx(t_env *e);
void				pixel_2(t_env *e, int y, int pos);
void				event_left(t_env *e);
void				event_right(t_env *e);
void				event_down(t_env *e);
void				event_up(t_env *e);
void				ft_coffee(t_env *e);
void				ft_init_cam(t_env *e, int x);
void				ft_maj_pos(t_env *e);
void				ft_draw(t_env *e);
void				ft_wall_length(t_env *e);
void				ft_ray(t_env *e);
void				ft_get_dist(t_env *e);
void				ft_init_map(t_env *e);
void				pixel(int x, t_env *e);
int					event(int key, t_env *e);

#endif
