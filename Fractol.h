/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:46:20 by jgagnon           #+#    #+#             */
/*   Updated: 2022/05/18 13:36:26 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "Libft/libft.h"

enum e_f_type	{mandelbrot, julia};

typedef struct image_var
{
	void			*image;
	char			*addr;
	int				bpp;
	int				l_l;
	int				end;
	int				iter;
	long double		max_x;
	long double		max_y;
	long double		pos_x;
	long double		pos_y;
	long double		x;
	long double		y;
	long double		size;
	long double		max_val;
	long double		min_val;
	long double		offset_x;
	long double		offset_y;
	long double		zoom;
	double			c1;
	double			c2;
}	t_img_data;

typedef struct screen_var
{
	t_img_data		img;
	t_img_data		bgd;
	void			*mlx;
	void			*win;
	int				zoom;
	enum e_f_type	frac_type;

}	t_screen_data;

int					win_close(t_screen_data *fract);
void				draw_mandel(t_img_data img);
void				my_mlx_p_p(t_img_data img, int x, int y, int color);
int					ft_color_julia(int it);
int					ft_color_mandel(int it);
int					create_trgb(int t, int r, int g, int b);
int					move_event(int key, t_screen_data *fract);
t_screen_data		init_mandel(void);
int					zoom_event(int mouse, int x, int y, t_screen_data *fract);
unsigned int		get_color(t_img_data *img, int x, int y);
void				get_move_val(t_screen_data *fract);
t_screen_data		init_fractal(void);
void				draw_julia(t_screen_data *fract);
void				update_fract(t_screen_data *fract);
void				draw_fractal(t_screen_data *fract);

#endif
