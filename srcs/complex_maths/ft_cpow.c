/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/03 15:45:16 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/fractol.h"

t_complex	ft_cpowi(t_complex c, unsigned int n)
{
	t_complex		res;
	unsigned int	i;

	if (n == 0)
		return ((t_complex){1, 0});
	if (n == 1)
		return (c);
	i = 1;
	res = c;
	while (i < n)
	{
		res = ft_cmult(res, c);
		i++;
	}
	return (res);
}
