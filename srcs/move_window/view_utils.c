/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 16:06:57 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_fmodf(double a, double b)
{
	if (!b)
		return (a);
	return (a - b * floor(a / b));
}

double	ft_clamp(double value, t_range range_old, t_range range_new)
{
	double	scaled_val;

	scaled_val = (value - range_old.min);
	scaled_val /= (range_old.max - range_old.min);
	scaled_val *= (range_new.max - range_new.min);
	scaled_val += range_new.min;
	return (scaled_val);
}

t_range	ft_lerp(double p, t_range val, double param)
{
	t_range	res;

	res.min = p + (val.min - p) * param;
	res.max = p + (val.max - p) * param;
	return (res);
}

t_complex	ft_scale(t_img *img, t_complex p)
{
	t_complex	new_p;

	new_p.re = ft_clamp(p.re, (t_range){0, WIDTH - 1}, img->x_range);
	new_p.im = ft_clamp(p.im, (t_range){0, HEIGHT - 1}, img->y_range);
	return (new_p);
}
