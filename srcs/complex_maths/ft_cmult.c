/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/03 12:44:56 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

t_complex	ft_cmult(t_complex c1, t_complex c2)
{
	t_complex	res;

	res.re = (c1.re * c2.re) - (c1.im * c2.im);
	res.im = (c1.re * c2.im) + (c1.im * c2.re);
	return (res);
}
