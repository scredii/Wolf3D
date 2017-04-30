/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_code.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:42:55 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/30 17:12:22 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		event(int key, t_env *e)
{
	if (key == 69)
		if (e->pl->moveSpeed < 0.70)
			e->pl->moveSpeed += 0.2;
	if (key == 78)
		if (e->pl->moveSpeed > 0.10)
			e->pl->moveSpeed -= 0.2;
	if (key == 53)
		exit(write(1, "Program close.\n", 15));
	if (key == 123 || key == 0)
		event_left(e);
	if (key == 124 || key == 2)
		event_right(e);
	if (key == 125 || key == 1)
		event_down(e);
	if (key == 126 || key == 13)
		event_up(e);
	e->redraw = 1;
	return (0);
}

void	event_left(t_env *e)
{
	OLDDX = e->view_x;
	e->view_x = e->view_x * cos(ROTSPEED) - e->view_y * sin(ROTSPEED);
	e->view_y = OLDDX * sin(ROTSPEED) + e->view_y * cos(ROTSPEED);
	e->pl->oldPlaneX = e->planeX;
	e->planeX = e->planeX * cos(ROTSPEED) - e->planeY * sin(ROTSPEED);
	e->planeY = e->pl->oldPlaneX * sin(ROTSPEED) + e->planeY * cos(ROTSPEED);
}

void	event_right(t_env *e)
{
	OLDDX = e->view_x;
	e->view_x = e->view_x * cos(-ROTSPEED) - e->view_y * sin(-ROTSPEED);
	e->view_y = OLDDX * sin(-ROTSPEED) + e->view_y * cos(-ROTSPEED);
	e->pl->oldPlaneX = e->planeX;
	e->planeX = e->planeX * cos(-ROTSPEED) - e->planeY * sin(-ROTSPEED);
	e->planeY = e->pl->oldPlaneX * sin(-ROTSPEED) + e->planeY * cos(-ROTSPEED);
}

void	event_up(t_env *e)
{
	if ((e->tab[(int)(INITX + e->view_x * MSPEED)][(int)(INITY)]) != '1')
		INITX += e->view_x * MSPEED;
	if ((e->tab[(int)(INITX)][(int)(INITY + e->view_y * MSPEED)]) != '1')
		INITY += e->view_y * MSPEED;
}

void	event_down(t_env *e)
{
	if ((e->tab[(int)(INITX - e->view_x * MSPEED)][(int)(INITY)]) != '1')
		INITX -= e->view_x * MSPEED;
	if ((e->tab[(int)(INITX)][(int)(INITY - e->view_y * MSPEED)]) != '1')
		INITY -= e->view_y * MSPEED;
}
