/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:30:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/25 16:51:09 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_error(int error)
{
	static const	char	(*errors[]) = {
		"No error\n",
		"Input invalid. Consult the options menu.\n",
		"Malloc failed. Check memory of your machine or try fewer fractals.\n",
		"Connection to graphics card could not be established.\n",
		"Window could not be created.\n",
		"Memory for fractal name could not be allocated.\n",
		"Memory for the colour scheme could not be allocated.\n",
		"Something went wrong when retrieving the fractal\n",
		"Julia parameters invalid\n",
		"Could not allocate memory to calculate pixel colours\n",
	};

	if (error)
		ft_printf_fd(errors[error], 2);
	ft_close(error);
	return (0);
}
