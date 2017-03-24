/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 21:44:44 by abourgeu          #+#    #+#             */
/*   Updated: 2017/03/22 21:45:15 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// double		ft_calc_shift(double r, double t, t_env *e)
// {
// 	double	shift;
//
// 	shift = SHIFT * ((r / t) / e->zoom);
// 	return (shift);
// }
//
// void		ft_range(t_env *e)
// {
// 	double	cur;
//
// 	cur = (1.25 - -1.25) / (e->zoom * e->zoom);
// 	e->julia_min->re += ((e->julia_max->re - e->julia_min->re) - cur)
// 		* ((double)e->mousex / LENGTH);
// 	e->julia_max->re = e->julia_min->re + cur;
// 	cur = (0.5 - -0.5) / (e->zoom * e->zoom);
// 	e->julia_min->im += ((e->julia_max->im - e->julia_min->im) - cur)
// 		* ((double)e->mousey / HEIGHT);
// 	e->julia_max->im = e->julia_min->im + cur;
// }
//
// void		ft_move(t_env *e)
// {
// 	double	range;
// 	double	step;
//
// 	range = (e->julia_max->re - e->julia_min->re);
// 	step = range / LENGTH;
// 	e->julia->re = e->julia_min->re + (step * (double)e->mousey);
// 	range = (e->julia_max->im - e->julia_min->im);
// 	step = range / HEIGHT;
// 	e->julia->im = e->julia_min->im + (step * (double)e->mousex);
// }
//
// int			ft_mouse_hook(int button, int x, int y, t_env *e)
// {
// 	e->mousex = x;
// 	e->mousey = y;
// 	if (button == 1 || button == 4)
// 	{
// 		e->zoom *= e->zoom_step;
// 		e->shiftx += ft_calc_shift(MOUSE_REL_X, (LENGTH / 2), e);
// 		e->shifty += ft_calc_shift(MOUSE_REL_Y, (HEIGHT / 2), e);
// 	}
// 	if ((button == 2 || button == 5) && e->zoom)
// 	{
// 		e->zoom /= e->zoom_step;
// 		e->shiftx -= ft_calc_shift(MOUSE_REL_X, (LENGTH / 2), e);
// 		e->shifty -= ft_calc_shift(MOUSE_REL_Y, (HEIGHT / 2), e);
// 	}
// 	if (button == 1 || button == 2 || button == 4 || button == 5)
// 	{
// 		ft_range(e);
// 		e->redraw = 1;
// 	}
// 	return (0);
// }
//
// int			ft_mouse(int x, int y, t_env *e)
// {
// 	if (e->fractol == 1 && e->mouse == 1)
// 	{
// 		e->mousex = x;
// 		e->mousey = y;
// 		ft_move(e);
// 		e->redraw = 1;
// 	}
// 	return (0);
// }
