/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:51:39 by jgagnon           #+#    #+#             */
/*   Updated: 2022/05/17 14:45:23 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int	win_close(t_screen_data *fract)
{
	mlx_destroy_image(fract->mlx, fract->img.image);
	mlx_destroy_window(fract->mlx, fract->win);
	exit(0);
}

int	move_event(int key, t_screen_data *fract)
{
	if (key == 2 || key == 124)
		fract->img.min_val -= fract->img.zoom;
	if (key == 0 || key == 123)
		fract->img.min_val += fract->img.zoom;
	if (key == 1 || key == 125)
		fract->img.max_val += fract->img.zoom;
	if (key == 13 || key == 126)
		fract->img.max_val -= fract->img.zoom;
	if (key == 49)
	{
		fract->img.max_val = 2.5;
		fract->img.min_val = -2.5;
	}
	if (key == 53)
		win_close(fract);
	if (key || key == 0)
	{
		update_fract(fract);
		draw_fractal(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->img.image,
			0 + fract->img.offset_x, 0 + fract->img.offset_y);
	}
	return (0);
}

int	zoom_event(int mouse, int x, int y, t_screen_data *fract)
{
	long double	zoom;

	zoom = 20;
	(void)x;
	(void)y;
	if (mouse == 4)
	{
		fract->img.size *= 1.1;
		update_fract(fract);
		draw_fractal(fract);
	}
	if (mouse == 5)
	{
		fract->img.size *= 0.9;
		update_fract(fract);
		draw_fractal(fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img.image,
		0 + fract->img.offset_x, 0 + fract->img.offset_y);
	return (0);
}

void	get_move_val(t_screen_data *fract)
{
	int	z;

	z = fract->img.size / 5000;
	if (z > 0 && z < 10)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 250);
	else if (z >= 10 && z < 100)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 1000);
	else if (z >= 100 && z < 1000)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 50000);
	else if (z >= 1000 && z < 10000)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 500000);
	else if (z >= 10000 && z < 100000)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 5000000);
	else if (z >= 100000)
		while (z-- > 0)
			fract->img.zoom = ((long double)1 / 50000000);
}

void	update_fract(t_screen_data *fract)
{
	get_move_val(fract);
	mlx_destroy_image(fract->mlx, fract->img.image);
	fract->img.image = mlx_new_image(fract->mlx, fract->img.max_x,
			fract->img.max_y);
	fract->img.addr = mlx_get_data_addr(fract->img.image, &fract->img.bpp,
			&fract->img.l_l, &fract->img.end);
}
