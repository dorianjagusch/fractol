/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/03 14:15:52 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

t_complex	ft_cdiv(t_complex c1, t_complex c2)
{
	t_complex	res;

	if (c2.re == 0 && c1.re == 0)
		exit(1);
	res.re = (c1.re * c2.re) + (c1.im * c2.im);
	res.re = res.re / (pow(c2.re, 2) + pow(c2.im, 2));
	res.im = (c1.im * c2.re) - (c1.re * c2.im);
	res.im = res.im / (pow(c2.re, 2) + pow(c2.im, 2));
	return (res);
}
