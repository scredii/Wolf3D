/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 20:14:15 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/25 15:12:00 by abourgeu         ###   ########.fr       */
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
# define TEXTW 64
# define TEXTH 64
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
	char			**text_data;
	double			*buff;
	int				tex_width;
	int				tex_height;
	int				texX;
	double 			wallX;
	int				textNum;
	void			*texture[3];
	int				xorcolor;
	int				ycolor;
	int				xycolor;
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
	int				mapX;
	int				mapY;
	int				side;
	double			distMurX;
	double			distMurY;
	double			dist2MurX;
	double			dist2MurY;
	double			longueurMur;
}					t_player;

typedef struct		s_env
{
	int				which;
	double			shiftx;
	double			shifty;
	double			mousex;
	double			mousey;
	double			zoom;
	int				lineheight;
	int				drawStart;
	int				drawEnd;
	int				Xmax;
	int				Ymax;
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
	int				sizeline;
	void			*mlx;
	int				wall;
	int				floor;
	int				roof;
	void			*img;
	void			*win;
	int				bpp;
	int				endian;
	int				size;
	int				redraw;
	char			*data;
	char			**tab;
	t_player		*pl;
}					t_env;

int					pixel_text(t_env *e);
void				ft_init_text(t_env *e);
int					ft_mouse_hook(t_env *e);
void				ft_wallX_value(t_env *e);
void 				ft_init_cam(t_env *e, int x);
int					texture(t_env *e);
void				ft_draw(t_env *e);
void				ft_wall_length(t_env *e);
void				ft_map(t_env *e);
void				ft_get_dist(t_env *e);
void				ft_init_map(t_env *e);
void				pixel(int x, t_env *e);
int					event(int key, t_env *e);

#endif
