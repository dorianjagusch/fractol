/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_colour2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 10:30:36 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_colour2(t_img *img, int iter)
{
	double		s;
	double		t;
	t_colour	colour;

	s = (double)iter / img->iter;
	t = powf(s, 2);
	colour.t = 0;
	colour.r = round((1 - t) * 0x05 + t * 0xDF);
	colour.g = round((1 - t) * 0x41 + t * 0x35);
	colour.b = round((1 - t) * 0x2A + t * 0x35);
	return (create_trgb(colour));
}

int	calc_colour4(t_img *img, int iter)
{
	double		s;
	double		t;
	t_colour	colour;

	s = (double)iter / img->iter;
	t = powf(s, 2);
	colour.t = 0;
	colour.r = round((1 - t) * 0x00 + t * 0xFF);
	colour.g = round((1 - t) * (0x00) + t * (0));
	colour.b = round((1 - t) * (0x46) + t * (0xAA));
	return (create_trgb(colour));
}

int	calc_colour6(t_img *img, int iter)
{
	t_colour	colour;

	colour.t = 0;
	colour.r = (int)round(ft_clamp(iter, (t_range){1, img->iter},
				(t_range){0, 0xFF}));
	colour.g = (int)round(ft_clamp(iter % 34, (t_range){1, img->iter},
				(t_range){0, 0xFF}));
	colour.b = (int)round(ft_clamp(iter % 21, (t_range){1, img->iter},
				(t_range){0, 0xFF}));
	return (create_trgb(colour));
}

int	calc_colour8(t_img *img, int iter)
{
	double		s;
	double		t;
	t_colour	colour;

	s = (double)iter / img->iter;
	t = powf(s, 2);
	colour.t = 0;
	colour.r = round((1 - t) * 0x25 + t * 0xFF);
	colour.g = round((1 - t) * (0x05) + t * (0x98));
	colour.b = round((1 - t) * (0x29) + t * (0x0));
	return (create_trgb(colour));
}
