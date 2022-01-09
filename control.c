/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:35:34 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/07 16:34:10 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_get_coler(t_data *data)
{
	data->color_code++;
	if (data->color_code == 8)
		data->color_code = 0;
	if (data->color_code == 0)
		data->color = 0xff0801;
	else if (data->color_code == 1)
		data->color = 0xfff600;
	else if (data->color_code == 2)
		data->color = 0x18ff00;
	else if (data->color_code == 3)
		data->color = 0xf4f4f5;
	else if (data->color_code == 4)
		data->color = 0xb0ffd9;
	else if (data->color_code == 5)
		data->color = 0xffffd9;
	else if (data->color_code == 6)
		data->color = 0xFFFCA7;
	else if (data->color_code == 7)
		data->color = 0xf1f1e1;
}

void	ft_key_hook2(t_data *data, int keycode)
{
	if (keycode == 6)
		data->max_it += 50;
	else if (keycode == 45 && data->max_it > 50)
		data->max_it -= 50;
	else if (keycode == 15)
	{
		data->zoom = 2.5;
		data->oy = 0;
		data->ox = 0;
		data->max_it = 100;
	}
	else if (keycode == 35)
		ft_get_coler(data);
}

int	ft_key_hook(int keycode, void *param)
{
	t_data	*data;

	data = param;
	if (keycode == 53 || keycode == 12)
		exit(0);
	else if (keycode == 126)
		data->oy -= data->zoom / 10;
	else if (keycode == 125)
		data->oy += data->zoom / 10;
	else if (keycode == 124)
		data->ox += data->zoom / 10;
	else if (keycode == 123)
		data->ox -= data->zoom / 10;
	ft_key_hook2(data, keycode);
	if (keycode == 35 || keycode == 15 || keycode == 45 || keycode == 6
		|| keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		ft_draw(*data);
	return (0);
}

void	ft_mouse_zoom(t_data *data, int button, int x, int y)
{
	double	new_ox;
	double	new_oy;

	new_ox = ft_map(x, data->ox - (data->zoom * 0.128),
			data->ox + (data->zoom * 0.128));
	new_oy = ft_map(y, data->oy - (data->zoom * 0.128),
			data->oy + (data->zoom * 0.128));
	data->ox = new_ox;
	data->oy = new_oy;
	if (button == 5)
		data->zoom -= data->zoom * 0.1;
	else if (button == 4)
		data->zoom += data->zoom * 0.1;
}

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_data	*data;

	data = param;
	if (button != 1 && button != 2)
	{
		ft_mouse_zoom(data, button, x, y);
		ft_draw(*data);
	}
	else if (button == 1 && data->julia)
		data->julia_move = !data->julia_move;
	return (0);
}
