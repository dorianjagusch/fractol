/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_changers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/02/05 16:36:04 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_change_frac(t_img *img, int frac)
{
	int	check;

	check = 0;
	if (frac == MAIN_PAD_0)
		img->n_frac = 0;
	if (MAIN_PAD_1 <= frac && frac <= MAIN_PAD_4)
		img->n_frac = frac - 17;
	select_fractal(img);
	if (!img->fractal->fractal)
		check = FRAC_ERR;
	if (!check)
		check = draw_fractal(img);
	return (check);
}

int	ft_change_iter(t_img *img, int key)
{
	int	check;

	if (key == MAIN_PAD_PLUS && img->iter < img->iter * (1 + ZOOM_DEPTH))
		img->iter = floor(img->iter * (1 + ZOOM_DEPTH));
	else
		img->iter = ft_max((long)floor(img->iter * (1 - ZOOM_DEPTH)),
				1 / ZOOM_DEPTH);
	check = draw_fractal(img);
	return (check);
}

int	ft_change_col(t_img *img, int key)
{
	int	check;

	check = 0;
	if (key == MAIN_PAD_C)
	img->colour_fun->index++;
	else
		img->colour_fun->index--;
	choose_colour(img);
	if (!check)
		check = draw_fractal(img);
	return (check);
}

int	ft_change_rot(t_img *img, int dir)
{
	int	check;

	if (dir == NUM_PAD_PLUS)
		img->rotation += ROTATION_INCR;
	if (dir == NUM_PAD_MINUS)
		img->rotation -= ROTATION_INCR;
	if (img->rotation < 0)
		img->rotation += 2 * M_PI;
	img->rotation = ft_fmodf(img->rotation, 2 * M_PI);
	check = draw_fractal(img);
	return (check);
}
