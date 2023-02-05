/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/02/02 14:07:52 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_position(int x, int y, t_img *img)
{
	if (x > 1 && x < WIDTH
		&& y > 1 && y < HEIGHT && img->move_julia == 1)
	{
		img->mouse.re = ft_clamp(x, (t_range){0, WIDTH - 1}, img->x_range);
		img->mouse.im = ft_clamp(y, (t_range){0, HEIGHT - 1}, img->y_range);
		draw_fractal(img);
	}
	return (0);
}

void	ft_close(int error)
{
	exit(error);
}

int	ft_close_win(t_img *img)
{
	static int		start;
	static u_int8_t	active;

	if (!start)
	{
		active = pow(2, img->win_num) - 1;
		start++;
	}
	img->active = 0;
	set_active(img, &active);
	free_img(img);
	if (!active)
		ft_close(0);
	return (0);
}

int	key_handler(int key, t_img *img)
{
	if (key == MAIN_PAD_ESC)
		ft_close_win(img);
	else if (key == MAIN_PAD_SPACE)
		ft_toggle_julia(img);
	else if (key == MAIN_PAD_R)
		set_image(img, img->fractal->name);
	else if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		ft_change_rot(img, key);
	else if (key == MAIN_PAD_PLUS || key == MAIN_PAD_MINUS)
		ft_change_iter(img, key);
	else if (key == MAIN_PAD_H)
		ft_toggle_help(img);
	else if (key == MAIN_PAD_UP || key == MAIN_PAD_DOWN || key == MAIN_PAD_LEFT
		|| key == MAIN_PAD_RIGHT)
		ft_shift(img, key);
	else if (key == MAIN_PAD_C || key == MAIN_PAD_X)
		ft_change_col(img, key);
	else if ((MAIN_PAD_1 <= key && key <= MAIN_PAD_3) || key == MAIN_PAD_0)
		ft_change_frac(img, key);
	return (0);
}

int	mouse_handler(int mouse_action, int x, int y, t_img *img)
{
	if (mouse_action == MOUSE_SCROLL_DOWN || mouse_action == MOUSE_SCROLL_UP)
		ft_zoom(mouse_action, x, y, img);
	if (mouse_action == MOUSE_LEFT)
		set_rot_point(img, x, y);
	return (0);
}
