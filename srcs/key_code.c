/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:42:55 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/24 13:42:49 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		event(int key, t_env *e)
{
	t_player *pl;

	pl = (t_player*)malloc(sizeof(t_player));
	e->pl->moveSpeed = 5.0;
	ROTSPEED = 3.0;
	if (key == 53)
		exit(write(1, "Program close.\n", 15));
	if (key == 123)
	{
		e->pl->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(ROTSPEED) - e->dirY * sin(ROTSPEED);
		e->dirY = e->pl->oldDirX * sin(ROTSPEED) + e->dirY * cos(ROTSPEED);
		e->pl->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(ROTSPEED) - e->planeY * sin(ROTSPEED);
		e->planeY = e->pl->oldPlaneX * sin(ROTSPEED) + e->planeY * cos(ROTSPEED);
	}
	if (key == 124)
	{
		e->pl->oldDirX = e->dirX;
		e->dirX = e->dirX * cos(-ROTSPEED) - e->dirY * sin(-ROTSPEED);
		e->dirY = e->pl->oldDirX * sin(-ROTSPEED) + e->dirY * cos(-ROTSPEED);
		e->pl->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(-ROTSPEED) - e->planeY * sin(-ROTSPEED);
		e->planeY = e->pl->oldPlaneX * sin(-ROTSPEED) + e->planeY * cos(-ROTSPEED);
	}
	if (key == 125)
	{
		if(!(e->worldMap[(int)(e->posX - e->dirX * e->pl->moveSpeed)][(int)(e->posY)]))
			e->posX -= e->dirX * e->pl->moveSpeed;
		if(!(e->worldMap[(int)(e->posX)][(int)(e->posY - e->dirY * e->pl->moveSpeed)]))
			e->posY -= e->dirY * e->pl->moveSpeed;
	}
	if (key == 126)
	{
		if(!(e->worldMap[(int)(e->posX + e->dirX * e->pl->moveSpeed)][(int)(e->posY)]))
			e->posX += e->dirX * e->pl->moveSpeed;
		if(!(e->worldMap[(int)(e->posX)][(int)(e->posY + e->dirY * e->pl->moveSpeed)]))
			e->posY += e->dirY * e->pl->moveSpeed;
	}
	e->redraw = 1;
	return (0);
}

// if (key == 8)
// {
// 	e->r = (rand() % 256) + 1;
// 	e->b = (rand() % 256) + 1;
// 	e->g = (rand() % 256) + 1;
// }
