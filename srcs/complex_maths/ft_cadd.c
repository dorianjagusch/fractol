/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/03 15:49:22 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

t_complex	ft_cadd(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.re = c1.re + c2.re;
	res.im = c1.im + c2.im;
	return (res);
}

t_complex	ft_caddf(t_complex c1, double f)
{
	t_complex	res;

	res.re = c1.re + f;
	res.im = c1.im + f;
	return (res);
}
