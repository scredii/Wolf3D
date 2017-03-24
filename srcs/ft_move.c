/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:55:51 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/24 13:37:24 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/wolf3d.h"

// {
// 	pl->moveSpeed = frameTime * 5.0;
// 	pl->rotSpeed = frameTime * 3.0;
// 	inkeys = SDL_GetKeyState(NULL);
//
// 	///Avancer s'il n'y a pas de mur en face
// 	///Reculer s'il n'y a aucun mur derriere soi
//
// 	///Effectuer une rotation vers la droite
// 	if ((inkeys[SDLK_RIGHT] != 0))
// 	{
// 	///la direction ainsi que le plan de la caméra doivent également effectuer une rotation
// 	double oldDirX = dirX;
// 	dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
// 	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
// 	double oldPlaneX = planeX;
// 	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
// 	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
// 	}
// 	///effectuer une rotaion vers la gauche
// 	if ((inkeys[SDLK_LEFT] != 0))
// 	{
// 	///la direction ainsi que le plan de la caméra doivent également effectuer une rotation
// 	pl->oldDirX = dirX;
// 	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
// 	dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
// 	double oldPlaneX = planeX;
// 	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
// 	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
// 	}
// }
