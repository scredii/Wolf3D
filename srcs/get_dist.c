/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 16:18:36 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/30 16:28:02 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		get_dirx(t_env *e)
{
	if (DIRX < 0)
	{
		e->stepX = -1;
		DISTWX = (e->pl->rayPosX - e->pl->mapX) * e->pl->Dist2WallX;
	}
	else
	{
		e->stepX = 1;
		DISTWX = (e->pl->mapX + 1.0 - e->pl->rayPosX) * e->pl->Dist2WallX;
	}
}

void		get_diry(t_env *e)
{
	if (DIRY < 0)
	{
		e->stepY = -1;
		DISTWY = (e->pl->rayPosY - e->pl->mapY) * e->pl->Dist2WallY;
	}
	else
	{
		e->stepY = 1;
		DISTWY = (e->pl->mapY + 1 - e->pl->rayPosY) * e->pl->Dist2WallY;
	}
}
