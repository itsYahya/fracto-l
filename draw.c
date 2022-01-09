/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 12:40:41 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/02 17:29:34 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pre_cal(t_data *data, int x, int y)
{
	data->var.a = ft_map(x, data->ox - data->zoom, data->ox + data->zoom);
	data->var.b = ft_map(y, data->oy - data->zoom, data->oy + data->zoom);
	if (!data->julia)
	{
		data->var.a_r = data->var.a;
		data->var.b_r = data->var.b;
	}
	data->var.num_it = 0;
}

void	ft_calculater(t_data *data)
{
	while (data->var.num_it < data->max_it)
	{
		if (data->burning_ship)
			data->var.bb = fabs(2 * data->var.a * data->var.b);
		else
			data->var.bb = 2 * data->var.a * data->var.b;
		data->var.aa = data->var.a * data->var.a - data->var.b * data->var.b;
		data->var.a = data->var.aa + data->var.a_r;
		data->var.b = data->var.bb + data->var.b_r;
		data->var.num_it++;
		if (data->var.a * data->var.a + data->var.b * data->var.b > 4)
			break ;
	}
}

void	ft_mlx_pixel_put(t_data data, int x, int y, int color)
{
	char	*pixel;

	pixel = data.image.address + (y * data.image.line_length
			+ x * (data.image.bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	ft_draw(t_data data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 600)
		{
			ft_pre_cal(&data, x, y);
			ft_calculater(&data);
			color = data.var.num_it * data.color;
			if (data.var.num_it == data.max_it)
				color = 0;
			ft_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_clear_window(data.cnx, data.window);
	mlx_put_image_to_window(data.cnx, data.window, data.image.img, 0, 0);
}
