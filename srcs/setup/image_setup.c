/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/02/05 16:36:14 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	set_image_const(t_img *img, char *av)
{
	img->zoom = 1;
	img->iter = ITER;
	img->x_range = (t_range){-2, 2};
	img->y_range = (t_range){-1.5, 1.5};
	img->is_help = 0;
	img->mouse = (t_complex){0, 0};
	img->mouse_pos = (t_complex){0, 0};
	img->move_julia = 1;
	img->rotation = ROTATION;
	if (!img->fractal->name)
		img->fractal->name = ft_strdup(av);
	if (!img->fractal->name)
		return (NAME_ERR);
	img->bits |= NAME_INIT;
	img->n_frac = 0;
	img->colour_fun->index = 0;
	choose_colour(img);
	select_fractal(img);
	return (0);
}

static int	user_input(t_img *img)
{
	mlx_hook(img->win->win, ON_KEYDOWN, 1L << 0, key_handler, img);
	mlx_hook(img->win->win, ON_MOUSEDOWN, 1L << 0, mouse_handler, img);
	mlx_hook(img->win->win, ON_DESTROY, 1L << 0, ft_close_win, img);
	if (img->move_julia == 1)
		mlx_hook(img->win->win, ON_MOUSEMOVE, 1L << 0, mouse_position, img);
	return (0);
}

static int	parse_julia(t_img *img, char *av)
{
	size_t			i;

	if (!ft_strncmp(av, "Julia ", 6))
	{
		i = 5;
		while (ft_isspace(av[i]))
			i++;
		img->mouse.re = ft_atof(&av[i]);
		while (ft_isdigit(av[i]) || av[i] == '.' || av[i] == '-')
			i++;
		while (ft_isspace(av[i]))
			i++;
		img->mouse.im = ft_atof(&av[i]);
	}
	return (0);
}

int	set_image(t_img *img, char *av)
{
	int	check;

	img->img = mlx_new_image(img->win->mlx, WIDTH, HEIGHT);
	if (!img->img)
		return (IMG_ERR);
	img->bits |= IMG_INIT;
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (ADDR_ERR);
	img->bits |= ADDR_INIT;
	check = set_image_const(img, av);
	parse_julia(img, av);
	if (check)
		return (check);
	user_input(img);
	check = draw_fractal(img);
	if (check)
		return (check);
	return (0);
}
