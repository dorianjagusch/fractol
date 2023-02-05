/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 16:40:41 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_img(t_img **images, int ac)
{
	size_t	i;

	i = 0;
	while (i < (ac - 1) && images)
	{
		images[i] = ft_calloc(1, sizeof(t_img));
		images[i]->win = ft_calloc(1, sizeof(t_window));
		if (!images[i]->win)
			free_images_array(images, i, MALLOC_ERR);
		images[i]->bits |= WIN_INIT;
		images[i]->fractal = ft_calloc(1, sizeof(t_fractal));
		if (!images[i]->fractal)
			free_images_array(images, i, MALLOC_ERR);
		images[i]->bits |= FRAC_INIT;
		images[i]->colour_fun = ft_calloc(1, sizeof(t_col_coices));
		if (!images[i]->colour_fun)
			free_images_array(images, i, MALLOC_ERR);
		images[i]->bits |= COLOUR_INIT;
		images[i]->active = 1;
		images[i]->win_id = i;
		images[i]->win_num = ac - 1;
		i++;
	}
}

t_img	**malloc_images_array(int ac)
{
	t_img	**images;

	images = ft_calloc(ac - 1, sizeof(t_img *));
	if (!images)
		ft_error(MALLOC_ERR);
	malloc_img(images, ac);
	return (images);
}

void	free_img(t_img *img)
{
	if (img->bits & IMG_INIT)
		mlx_destroy_image(img->win->mlx, img->img);
	if (img->bits & WIN_WIN_INIT)
		mlx_destroy_window(img->win->mlx, img->win->win);
	if (img->bits & WIN_INIT)
		free(img->win);
	if (img->bits & NAME_INIT)
		ft_free(img->fractal->name);
	if (img->bits & FRAC_INIT)
		ft_free(img->fractal);
	if (img->bits & COLOUR_INIT)
		ft_free(img->colour_fun);
}

void	free_images_array(t_img **images, int index, int error)
{	
	int	i;

	i = index - 1;
	while (i >= 0)
	{
		free_img(images[i]);
		ft_free(images[i--]);
	}
	ft_free(images);
	images = NULL;
	if (error && error != INPUT_ERR)
		ft_error(error);
	else if (error == INPUT_ERR)
		ft_options();
}
