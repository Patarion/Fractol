/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:14:41 by jgagnon           #+#    #+#             */
/*   Updated: 2022/05/17 13:44:31 by jgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	ft_color_mandel(int it)
{
	if ((it % 24) == 0 || (it % 24) == 6 || (it % 24) == 12 || (it % 24) == 18)
		return (create_trgb(0, (63 + (64 * (it % 24 / 6))), 0, 0));
	if ((it % 24) == 1 || (it % 24) == 7 || (it % 24) == 13 || (it % 24) == 19)
		return (create_trgb(0, 0, (64 + (63 * (it % 24 / 6))), 0));
	if ((it % 24) == 2 || (it % 24) == 8 || (it % 24) == 14 || (it % 24) == 20)
		return (create_trgb(0, 0, 0, (63 + (64 * (it % 24 / 6)))));
	if ((it % 24) == 3 || (it % 24) == 9 || (it % 24) == 15 || (it % 24) == 21)
		return (create_trgb(0, (63 + (64 * (it % 24 / 6))), 0,
				(63 + (64 * (it % 24 / 6)))));
	if ((it % 24) == 4 || (it % 24) == 10 || (it % 24) == 16 || (it % 24) == 22)
		return (create_trgb(0, (63 + (64 * (it % 24 / 6))),
				(63 + (64 * (it % 24 / 6))), 0));
	if ((it % 24) == 5 || (it % 24) == 11 || (it % 24) == 17 || (it % 24) == 23)
		return (create_trgb(0, 0, (63 + (64 * (it % 24 / 6))),
				(63 + (64 * (it % 24 / 6)))));
	return (0);
}

int	ft_color_julia(int it)
{
	if ((it % 12) == 0 || (it % 12) == 6)
		return (create_trgb(0, (63 + (64 * (it % 12 / 6))), 0, 0));
	if ((it % 12) == 1 || (it % 12) == 7)
		return (create_trgb(0, 0, (64 + (63 * (it % 12 / 6))), 0));
	if ((it % 12) == 2 || (it % 12) == 8)
		return (create_trgb(0, 0, 0, (63 + (64 * (it % 12 / 6)))));
	if ((it % 12) == 3 || (it % 12) == 9)
		return (create_trgb(0, (63 + (64 * (it % 12 / 6))),
				0, (63 + (64 * (it % 12 / 6)))));
	if ((it % 12) == 4 || (it % 12) == 10)
		return (create_trgb(0, (63 + (64 * (it % 12 / 6))),
				(63 + (64 * (it % 12 / 6))), 0));
	if ((it % 12) == 5 || (it % 12) == 11)
		return (create_trgb(0, 0, (63 + (64 * (it % 12 / 6))),
				(63 + (64 * (it % 12 / 6)))));
	return (0);
}

unsigned int	get_color(t_img_data *img, int x, int y)
{
	char	*color;

	color = img->addr + (y * img->l_l + x * (img->bpp / 8));
	return (*(unsigned int *) color);
}
