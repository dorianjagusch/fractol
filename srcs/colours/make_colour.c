/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_colour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 16:15:17 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//from https://www.sekinoworld.com/fractal/coloring.htm

int	(*choose_colour(t_img *img))(t_img *img, int iter)
{
	static const t_col_coices	colour_funs [COLOUR_CHOICES] = {
	{0, &calc_colour},
	{1, &calc_colour2},
	{2, &calc_colour3},
	{3, &calc_colour4},
	{4, &calc_colour5},
	{5, &calc_colour6},
	{6, &calc_colour7},
	{7, &calc_colour8},
	{8, &calc_bw},
	{9, &calc_bw_band}
	};

	if (img->colour_fun->index < 0)
		img->colour_fun->index = 14;
	return (colour_funs[img->colour_fun->index % COLOUR_CHOICES].color_algo);
}

int	calc_colour(t_img *img, int iter)
{
	double		s;
	double		t;
	t_colour	colour;

	s = (double)iter / ITER;
	t = powf(s, 2);
	colour.t = 0;
	colour.r = round((1 - t) * 0x05 + t * 0xDF);
	colour.g = round((1 - t) * 0x41 + t * 0x35);
	colour.b = round((1 - t) * 0x2A + t * 0x35);
	return (create_trgb(colour));
}

int	calc_colour3(t_img *img, int iter)
{
	double		s;
	double		t;
	t_colour	colour;

	s = (double)iter / ITER;
	t = powf(s, 2);
	colour.t = 0;
	colour.r = round((1 - t) * 0x00 + t * 0xFF);
	colour.g = round((1 - t) * (0x00) + t * (0));
	colour.b = round((1 - t) * (0x46) + t * (0xAA));
	return (create_trgb(colour));
}

int	calc_colour5(t_img *img, int iter)
{
	t_colour	colour;

	colour.t = 0;
	colour.r = (int)round(ft_clamp(iter, (t_range){1, ITER},
				(t_range){0, 0xFF}));
	colour.g = (int)round(ft_clamp(iter % 34, (t_range){1, ITER},
				(t_range){0, 0xFF}));
	colour.b = (int)round(ft_clamp(iter % 21, (t_range){1, ITER},
				(t_range){0, 0xFF}));
	return (create_trgb(colour));
}

int	calc_colour7(t_img *img, int iter)
{
	double		s;
	double		t;
	t_colour	colour;

	s = (double)iter / ITER;
	t = powf(s, 2);
	colour.t = 0;
	colour.r = round((1 - t) * 0x25 + t * 0xFF);
	colour.g = round((1 - t) * (0x05) + t * (0x98));
	colour.b = round((1 - t) * (0x29) + t * (0x0));
	return (create_trgb(colour));
}
