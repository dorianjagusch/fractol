/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/25 16:51:40 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_fractol(t_img *img, int ac, char *av)
{
	img->win->win = mlx_new_window(img->win->mlx,
			WIDTH, HEIGHT, av);
	if (!img->win->win)
		return (WIN_ERR);
	img->bits |= WIN_WIN_INIT;
	return (set_image(img, av));
}

static void	do_fractol(t_img **images, int ac, char *av, int index)
{
	int	check;

	check = 0;
	check = init_fractol(images[index], ac, av);
	if (check)
		free_images_array(images, index, check);
	check = draw_fractal(images[index]);
	if (check)
		free_images_array(images, index, check);
}

static void	get_mlx(t_img **images, int ac, void *mlx)
{
	int	i;

	i = 0;
	while (i < ac -1)
		images[i++]->win->mlx = mlx;
}

void	fractol(t_img **images, int ac, char **av)
{
	int		i;
	void	*mlx;

	mlx = mlx_init();
	if (!mlx)
		free_images_array(images, ac, MLX_ERR);
	i = 0;
	get_mlx(images, ac, mlx);
	while (i < (ac - 1))
	{
		if (images[i]->active == 0)
		{
			i++;
			continue ;
		}
		do_fractol(images, ac, av[i + 1], i);
		i++;
	}
	mlx_loop(mlx);
}
