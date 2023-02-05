/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 16:43:44 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_fractal(char *av)
{
	if (!ft_strncmp(av, "Julia", 5)
		|| !ft_strcmp(av, "Mandelbrot")
		|| !ft_strcmp(av, "Burning Ship")
		|| !ft_strcmp(av, "Newton"))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	static t_img	**images;
	int				i;

	if (ac < 2 || ac > NUM_FRACTALS + 1 || !ft_strncmp(av[1], "H", 2))
		ft_options();
	i = 1;
	images = malloc_images_array(ac);
	if (!images)
		free_images_array(images, ac - 1, MALLOC_ERR);
	while (i < ac)
	{
		if (!is_fractal(av[i]))
			free_images_array(images, ac - 1, INPUT_ERR);
		i++;
	}
	fractol(images, ac, av);
	return (0);
}
