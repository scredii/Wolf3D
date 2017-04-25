/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:42:55 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/25 15:12:22 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		event(int key, t_env *e)
{
	if (key == 17)
		e->which = (e->which ? 0 : 1);
	if (key == 53)
		exit(write(1, "Program close.\n", 15));
	if (key == 123 || key == 0)
	{
		OLDDX = e->dirX;
		e->dirX = e->dirX * cos(ROTSPEED) - e->dirY * sin(ROTSPEED);
		e->dirY = OLDDX * sin(ROTSPEED) + e->dirY * cos(ROTSPEED);
		e->pl->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(ROTSPEED) - e->planeY * sin(ROTSPEED);
		e->planeY = e->pl->oldPlaneX * sin(ROTSPEED) + e->planeY * cos(ROTSPEED);
	}
	if (key == 124 || key == 2)
	{
		OLDDX = e->dirX;
		e->dirX = e->dirX * cos(-ROTSPEED) - e->dirY * sin(-ROTSPEED);
		e->dirY = OLDDX * sin(-ROTSPEED) + e->dirY * cos(-ROTSPEED);
		e->pl->oldPlaneX = e->planeX;
		e->planeX = e->planeX * cos(-ROTSPEED) - e->planeY * sin(-ROTSPEED);
		e->planeY = e->pl->oldPlaneX * sin(-ROTSPEED) + e->planeY * cos(-ROTSPEED);
	}
	if (key == 125 || key == 1)
	{
		if((e->tab[(int)(e->posX - e->dirX * e->pl->moveSpeed)][(int)(e->posY)]) != '1')
			e->posX -= e->dirX * e->pl->moveSpeed;
		if((e->tab[(int)(e->posX)][(int)(e->posY - e->dirY * e->pl->moveSpeed)]) != '1')
			e->posY -= e->dirY * e->pl->moveSpeed;
	}
	if (key == 126 || key == 13)
	{
		if((e->tab[(int)(e->posX + e->dirX * e->pl->moveSpeed)][(int)(e->posY)]) != '1')
			e->posX += e->dirX * e->pl->moveSpeed;
		if((e->tab[(int)(e->posX)][(int)(e->posY + e->dirY * e->pl->moveSpeed)]) != '1')
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
