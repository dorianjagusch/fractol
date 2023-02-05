/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burning_ship.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 10:41:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 14:54:05 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

int	ft_burning_ship(t_img *img, t_complex coord)
{
	t_complex	z;
	int			i;
	double		temp_z_re;

	z = (t_complex){0, 0};
	temp_z_re = 0;
	i = 1;
	while (i < img->iter)
	{
		temp_z_re = pow(z.re, 2) - pow(z.im, 2) + coord.re;
		z.im = fabs(2 * z.re * z.im) + coord.im;
		z.re = temp_z_re;
		if (ft_cmag2(z) > CUT_OFF)
			return (img->colour_fun->color_algo(img, i));
		i++;
	}
	return (BLACK);
}
