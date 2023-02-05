/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_shifters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 16:19:42 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_zoom(int mouse_action, int x, int y, t_img *img)
{
	t_complex	mouse;
	double		factor;
	int			check;

	check = 0;
	if (img->is_help)
		return (0);
	if (mouse_action == MOUSE_SCROLL_UP || mouse_action == MOUSE_SCROLL_DOWN)
	{
		mouse = ft_scale(img, (t_complex){x, y});
		if (mouse_action == MOUSE_SCROLL_UP)
			img->zoom = 1 - ZOOM_DEPTH;
		else
			img->zoom = 1 + ZOOM_DEPTH;
		factor = 1.0 / img->zoom;
		img->x_range = ft_lerp(mouse.re, img->x_range, factor);
		img->y_range = ft_lerp(mouse.im, img->y_range, factor);
		check = draw_fractal(img);
	}
	return (check);
}

int	ft_shift(t_img *img, int key)
{
	double	diff_x;
	double	diff_y;
	double	dir;

	dir = 1;
	if (key == MAIN_PAD_LEFT || key == MAIN_PAD_RIGHT)
	{
		if (key == MAIN_PAD_LEFT)
			dir = -1;
		diff_x = (img->x_range.max - img->x_range.min) * 0.05;
		img->x_range.min += diff_x * dir / img->zoom;
		img->x_range.max += diff_x * dir / img->zoom;
	}
	else
	{
		if (key == MAIN_PAD_UP)
			dir = -1;
		diff_y = (img->y_range.max - img->y_range.min) * 0.05;
		img->y_range.min += diff_y * dir / img->zoom;
		img->y_range.max += diff_y * dir / img->zoom;
	}
	if (draw_fractal(img))
		return (SHIFT_ERR);
	return (0);
}

int	set_rot_point(t_img *img, int x, int y)
{
	double	temp_re;
	double	temp_im;

	if (x > 0 && x < WIDTH
		&& y > 0 && y < HEIGHT)
	{
		temp_re = ft_clamp(x, (t_range){0, WIDTH - 1}, img->x_range);
		temp_im = ft_clamp(y, (t_range){0, HEIGHT - 1}, img->y_range);
		img->mouse_pos = (t_complex){temp_re, temp_im};
		draw_fractal(img);
	}
	return (0);
}

t_complex	ft_rotate(t_img *img, t_complex p)
{
	t_complex	res;
	double		sin_res;
	double		cos_res;

	sin_res = sin(img->rotation);
	cos_res = cos(img->rotation);
	res.re = img->mouse_pos.re + (p.re - img->mouse_pos.re) * cos_res;
	res.re -= (p.im - img->mouse_pos.im) * sin_res;
	res.im = img->mouse_pos.im + (p.re - img->mouse_pos.re) * sin_res;
	res.im += (p.im - img->mouse_pos.im) * cos_res;
	return (res);
}
