/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:18:44 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/24 15:03:52 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"


void ft_init_map(t_env *e)
{
	e->worldMap[4][1] = 0;
}

void		ft_init_position(t_env *e)
{
	int		x;

	e->width = 512;
	x = 0;
	while (x < e->width)
	{
		e->pl->cameraX = 2 * x / (double)e->width - 1;
		e->pl->rayPosX = e->posX;
		e->pl->rayPosY = e->posY;
		e->pl->rayDirX = e->dirX + e->planeX * e->pl->cameraX;
		e->pl->rayDirY = e->dirY + e->planeY * e->pl->cameraX;
		e->pl->mapX = (int)e->pl->rayPosX;
		e->pl->mapY = (int)e->pl->rayPosY;
		// e->pl->distMurX;
		// e->pl->distMurY;
		e->pl->dist2MurX = sqrt(1 + (e->pl->rayDirY * e->pl->rayDirY) / (e->pl->rayDirX * e->pl->rayDirX));
		e->pl->dist2MurY = sqrt(1 + (e->pl->rayDirX * e->pl->rayDirX) / (e->pl->rayDirY * e->pl->rayDirY));
		// e->pl->longueurMur;
		x++;
	}
}

void		ft_calc_dist(t_env *e)
{
	int		touch;

	touch = 0;
	if (e->pl->rayDirX < 0)
	{
		e->stepX = -1;
		e->pl->distMurX = (e->pl->rayPosX - e->pl->mapX) * e->pl->dist2MurX;
	}
	else
	{
		e->stepX = 1;
		e->pl->distMurX = (e->pl->mapX + 1.0 - e->pl->rayPosX) * e->pl->dist2MurX;
	}
	if (e->pl->rayDirY < 0)
	{
		e->stepY = -1;
		e->pl->distMurY = (e->pl->rayPosY - e->pl->mapY) * e->pl->dist2MurY;
	}
	else
	{
		e->stepY = 1;
		e->pl->distMurY = (e->pl->mapY + 1.0 - e->pl->rayPosY) * e->pl->dist2MurY;
	}
	// while (touch == 0)
	// {
	// 	if (e->distMurX < e->distMurY)
	// 	{
	// 		e->distMurX += e->dist2MurX;
	// 		e->mapX += stepX;
	// 		murVertiOuHori = 0;
	// 	}
	// 	else
	// 	{
	// 		e->distMurY += e->dist2MurY;
	// 		e->mapY += stepY;
	// 		murVertiOuHori = 1;
	// 	}
	// 	if (worldMap[e->mapX][e->mapY] > 0)
	// 		touche = 1;
	// }
}

void ft_calc_height(t_env *e)
{
	int		hauteurMur;
	int		drawStart;
	int		drawEnd;
	int		murVertiOuHori;

	murVertiOuHori = 0;
	if (murVertiOuHori == 0)
		e->pl->longueurMur = fabs((e->pl->mapX - e->pl->rayPosX + (1 - e->stepX) / 2) / e->pl->rayDirX);
	else
		e->pl->longueurMur = fabs((e->pl->mapY - e->pl->rayPosY + (1 - e->stepY) / 2) / e->pl->rayDirY);
	hauteurMur = abs((int)(e->height / e->pl->longueurMur));
	drawStart = -hauteurMur / 2 + e->height / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = hauteurMur / 2 + e->height / 2;
	if(drawEnd >= e->height)
		drawEnd = e->height - 1;
    //   Uint8 colorR;
    //   Uint8 colorG;
    //   Uint8 colorB;
    //   switch(worldMap[mapX][mapY])
    //   {
    //     case 1:  colorR = 0xFF; colorG = 0x00; colorB = 0x00;  break; ///rouge
    //     case 2:  colorR = 0x00; colorG = 0xFF; colorB = 0x00;  break; ///vert
    //     case 3:  colorR = 0x00; colorG = 0x00; colorB = 0xFF;   break; ///bleu
    //     case 4:  colorR = 0xFF; colorG = 0xFF; colorB = 0xFF;  break; ///blanc
    //     default: colorR = 0xFF; colorG = 0xFF; colorB = 0x00; break; ///jaune
    //   }
	// if (murVertiOuHori == 1)
	// {
	// 	colorR /= 2;
	// 	colorB /= 2;
	// 	colorG /= 2;
	// }
	// pixel(x, drawStart, drawEnd, colorR, colorG, colorB);
}
