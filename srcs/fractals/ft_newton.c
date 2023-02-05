/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 11:41:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 10:25:52 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

static t_complex	ft_newtonfnct(t_complex c)
{
	return (ft_cadd(ft_cpowi(c, 3), (t_complex){-1, 0}));
}

static t_complex	ft_newtonderiv(t_complex c)
{
	return (ft_fmultc(3., ft_cmult(c, c)));
}

static int	get_newton_colour(t_img *img, t_complex *z)
{
	static const t_complex	roots[3] = {(t_complex){1, 0},
		(t_complex){-.5, 1.73205080757 / 2},
		(t_complex){-.5, -1.73205080757 / 2}
	};
	t_complex				diff;
	int						i;

	*z = ft_csub(*z, ft_cdiv(ft_newtonfnct(*z), ft_newtonderiv(*z)));
	i = 0;
	while (i < 3)
	{
		diff = ft_csub(*z, roots[i]);
		if (fabs(diff.re) < 0.000001 && fabs(diff.im) < 0.000001)
			return (img->colour_fun->color_algo(img, i * 19));
		i++;
	}
	return (0);
}

int	ft_newton(t_img *img, t_complex coord)
{
	size_t		i;
	t_complex	z;
	int			res;

	i = 0;
	z = coord;
	while (i < img->iter)
	{
		res = get_newton_colour(img, &z);
		if (res)
			return (res);
		i++;
	}
	return (0);
}
