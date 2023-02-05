/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djagusch <djagusch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 14:57:13 by djagusch          #+#    #+#             */
/*   Updated: 2023/01/27 16:15:28 by djagusch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include "macos_keys.h"
# include "libft.h"
# include "errors.h"

//DEFAULTS
# define WIDTH 600
# define HEIGHT 600
# define ITER 40
# define CUT_OFF 4
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define GREY 0x00808080
# define ROTATION 0
# define NUM_FRACTALS 4
# define COLOUR_CHOICES 10
# define ZOOM_DEPTH 0.2
# define ROTATION_INCR 0.05
# define _2_PI (2 * M_PI)

typedef struct s_range 
{
	double		min;
	double		max;
}			t_range;

typedef struct s_window
{
	void	*mlx;
	void	*win;
}			t_window;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

struct s_img;
typedef struct s_img t_img;

typedef struct s_fractal
{
	char			*name;
	int				(*fractal)(t_img*, t_complex);
}					t_fractal;

typedef struct s_col_choice
{
	int	index;
	int	(*color_algo)(t_img*, int);
}				t_col_coices;

typedef struct s_colour
{
	uint8_t	t;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
}				t_colour;

typedef struct s_img
{
	t_window		*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	t_fractal		*fractal;
	int				n_frac;
	t_range			x_range;
	t_range			y_range;
	int				move_julia;
	int				is_help;
	t_col_coices	*colour_fun;
	t_complex		mouse;
	t_complex		mouse_pos;
	double			zoom;
	unsigned int	iter;
	double			rotation;
	u_int8_t		bits;
	int				active;
	int				win_id;
	int				win_num;
}					t_img;

//FRACTOL
int			set_image(t_img *img, char *av);
void		fractol(t_img **images, int ac, char** av);
t_img		**malloc_images_array(int ac);
void		free_img(t_img *img);
void		free_images_array(t_img **images, int index, int error);
void		ft_options(void);
int			ft_error(int error);
void		set_active(t_img *img, u_int8_t *active);
int			set_rot_point(t_img *img, int x, int y);

//VIEW HANDLERS
int			ft_shift(t_img *img, int key);
int			ft_zoom(int mouse_action, int x, int y, t_img *img);
t_complex	ft_scale(t_img *img, t_complex p);
t_complex	ft_rotate(t_img *img, t_complex p);
double		ft_clamp(double value, t_range range_old, t_range range_new);
int			ft_toggle_julia(t_img *img);
int			ft_toggle_help(t_img *img);
int			ft_change_frac(t_img *img, int frac);
int			ft_change_col(t_img *img, int key);
int			ft_change_rot(t_img *img, int dir);
int			ft_change_iter(t_img *img, int key);

//INPUT HANDLERS
int			mouse_position(int x, int y, t_img *img);
int			mouse_handler(int mouse_action, int x, int y, t_img *img);
int			ft_close_win(t_img *img);
void		ft_close(int error);
int			key_handler(int key, t_img *img);

//FRACTAL FUNCTIONS
int			(*select_fractal(t_img *img))(t_img *img, t_complex coord);
int			draw_fractal(t_img *img);
int			ft_mandelbrot(t_img *img, t_complex coord);
int			ft_julia(t_img *img, t_complex coord);
int			ft_burning_ship(t_img *img, t_complex coord);
int			ft_newton(t_img *img, t_complex coord);

//COMPLEX MATHS
t_complex	ft_cadd(t_complex c1, t_complex c2);
t_complex	ft_csub(t_complex c1, t_complex c2);
t_complex	ft_cmult(t_complex c1, t_complex c2);
t_complex	ft_fmultc(double f, t_complex c2);
t_complex	ft_cdiv(t_complex c1, t_complex c2);
t_complex	ft_cpowi(t_complex c, unsigned int n);
double		ft_cmag(t_complex c);
double		ft_cmag2(t_complex c);
double		ft_ccum_sumf(t_complex *array, int length, double (*f)(t_complex));


//COLOUR FUNCTIONS
int			get_t(int trgb);
int			create_trgb(t_colour colour);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);
int			calc_colour(t_img *img, int iter);
int			calc_colour2(t_img *img, int iter);
int			calc_colour3(t_img *img, int iter);
int			calc_colour4(t_img *img, int iter);
int			calc_colour5(t_img *img, int iter);
int			calc_colour6(t_img *img, int iter);
int			calc_colour7(t_img *img, int iter);
int			calc_colour8(t_img *img, int iter);
int			calc_bw_band(t_img *img, int iter);
int			calc_bw(t_img *img, int iter);
int			(*choose_colour(t_img *img))(t_img *, int);

// Miscelaneous
double		ft_neg_exp(t_complex z);
double		ft_fmodf(double a, double b);
t_range		ft_lerp(double p, t_range val, double param);

#endif
