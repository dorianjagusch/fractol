/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/02/05 16:38:49 by djagusch         ###   ########.fr       */
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

void	select_fractal(t_img *img)
{
	int						i;
	int						(*fractal)(t_img *, t_complex);
	static const t_fractal	fractals[NUM_FRACTALS] = {
	{"Mandelbrot", &ft_mandelbrot},
	{"Julia", &ft_julia},
	{"Burning Ship", &ft_burning_ship},
	{"Newton", &ft_newton}
	};
	static const int		lengths[] = {10, 5, 12, 6};

	i = 0;
	fractal = NULL;
	while (i < (sizeof(fractals) / sizeof(t_fractal)))
	{
		if (!ft_strncmp(img->fractal->name, fractals[i].name, lengths[i]))
		{
			fractal = fractals[(i + img->n_frac) % NUM_FRACTALS].fractal;
			break;
		}
		i++;
	}
	img->fractal->fractal = fractal;
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
