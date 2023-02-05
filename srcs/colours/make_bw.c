/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 16:15:05 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_bw(t_img *img, int iter)
{
	double		s;
	double		t;
	t_colour	colour;

	s = (double)iter / img->iter;
	t = powf(s, 2);
	colour.t = 0;
	colour.r = round((1 - t) * 0 + t * 255);
	colour.g = round((1 - t) * 0 + t * 255);
	colour.b = round((1 - t) * 0 + t * 255);
	return (create_trgb(colour));
}

int	calc_bw_band(t_img *img, int iter)
{
	if (iter % 3 == 1)
		return (GREY);
	if (iter % 3 == 2)
		return (WHITE);
	return (BLACK);
}
