/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:41:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 10:36:00 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

int	ft_julia(t_img *img, t_complex coord)
{
	t_complex	z;
	int			i;

	z = coord;
	i = 1;
	while (i < img->iter)
	{
		z = ft_cadd(ft_cmult(z, z), img->mouse);
		if (ft_cmag2(z) > CUT_OFF)
			return (img->colour_fun->color_algo(img, i));
		i++;
	}
	return (BLACK);
}
