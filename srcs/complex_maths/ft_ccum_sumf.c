/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ccum_sumf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/20 13:15:08 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

double	ft_ccum_sumf(t_complex *array, int length, double (*f)(t_complex))
{
	double	res;
	int		i;

	res = 0;
	i = 0;
	while (i < length && i < 40)
		res += (f)(array[i++]);
	free(array);
	return (res);
}
