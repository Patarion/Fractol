/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:44:41 by jgagnon           #+#    #+#             */
/*   Updated: 2022/05/23 10:46:22 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

t_screen_data	init_fractal(void)
{
	t_screen_data	fractal;

	fractal.img.pos_x = -1;
	fractal.img.pos_y = -1;
	fractal.img.size = 250;
	fractal.img.iter = 50;
	fractal.img.min_val = -2.5;
	fractal.img.max_val = 2.5;
	fractal.img.max_x = 1080;
	fractal.img.max_y = 720;
	fractal.img.offset_x = 0;
	fractal.img.offset_y = 0;
	fractal.img.zoom = 0.1;
	fractal.img.c1 = -0.4;
	fractal.img.c2 = 0.6;
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, 1080, 720, "Fractal");
	fractal.img.image = mlx_new_image(fractal.mlx, fractal.img.max_x,
			fractal.img.max_y);
	fractal.img.addr = mlx_get_data_addr(fractal.img.image, &fractal.img.bpp,
			&fractal.img.l_l, &fractal.img.end);
	return (fractal);
}

void	draw_fractal(t_screen_data *fract)
{
	if (fract->frac_type == mandelbrot)
		draw_mandel(fract->img);
	else if (fract->frac_type == julia)
		draw_julia(fract);
}

int	main(int argc, char **argv)
{
	t_screen_data	fract;

	fract = init_fractal();
	if (argc == 2 && (ft_strncmp(argv[1], "Mandelbrot", 11) == 0))
		fract.frac_type = mandelbrot;
	else if (argc == 2 && (ft_strncmp(argv[1], "Julia", 6) == 0))
		fract.frac_type = julia;
	else
	{
		printf("Veuillez sélectionné un fractal parmis les suivants :\n1- \
Mandelbrot\n2- Julia");
		win_close(&fract);
	}
	draw_fractal(&fract);
	mlx_put_image_to_window(fract.mlx, fract.win,
		fract.img.image, 0 + fract.img.offset_x, 0 + fract.img.offset_y);
	mlx_hook(fract.win, 17, 0, win_close, &fract);
	mlx_key_hook(fract.win, move_event, &fract);
	mlx_mouse_hook(fract.win, zoom_event, &fract);
	mlx_loop(fract.mlx);
}
