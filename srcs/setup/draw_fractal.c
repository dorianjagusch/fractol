/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 15:46:26 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_mlx_pixel_put(t_img *img, t_complex pxl, int colour)
{
	char	*dst;

	dst = img->addr + ((int)pxl.im * img->line_length
			+ (int)pxl.re * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = colour;
}

int	(*select_fractal(t_img *img))(t_img *img, t_complex coord)
{
	int						i;
	int						(*fractal)(t_img *img, t_complex coord);
	static const t_fractal	fractals[NUM_FRACTALS] = {
	{"Mandelbrot", &ft_mandelbrot},
	{"Julia", &ft_julia},
	{"Burning Ship", &ft_burning_ship},
	{"Newton", &ft_newton}
	};
	static int				lengths[] = {10, 5, 12, 6};

	i = 0;
	fractal = NULL;
	while (i < (sizeof(fractals) / sizeof(t_fractal)))
	{
		if (!ft_strncmp(img->fractal->name, fractals[i].name, lengths[i]))
			return (fractals[(i + img->n_frac) % NUM_FRACTALS].fractal);
		i++;
	}
	return (0);
}

int	draw_fractal(t_img *img)
{
	t_complex	pxl;
	t_complex	coord;

	pxl.re = 0;
	while (pxl.re < WIDTH)
	{
		pxl.im = 0;
		while (pxl.im < HEIGHT)
		{
			coord = ft_scale(img, pxl);
			if (img->rotation)
				coord = ft_rotate(img, coord);
			my_mlx_pixel_put(img, pxl, img->fractal->fractal(img, coord));
			pxl.im++;
		}
		pxl.re++;
	}
	mlx_put_image_to_window(img->win->mlx, img->win->win, img->img, 0, 0);
	mlx_string_put(img->win->mlx, img->win->win, WIDTH - 80,
		20, WHITE, "[H] - Help");
	return (0);
}
