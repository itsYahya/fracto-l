/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 11:45:33 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/02 17:29:47 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

typedef struct s_image
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_var
{
	double	a;
	double	b;
	double	aa;
	double	bb;
	double	a_r;
	double	b_r;
	int		num_it;
}	t_var;

typedef struct s_data
{
	void	*cnx;
	void	*window;
	t_image	image;
	t_var	var;
	double	zoom;
	double	ox;
	double	oy;
	int		max_it;
	int		color;
	int		color_code;
	int		julia;
	int		julia_move;
	int		burning_ship;
}	t_data;

double	ft_map(int in, double min, double max);
void	ft_pre_cal(t_data *data, int x, int y);
void	ft_calculater(t_data *data);
void	ft_mlx_pixel_put(t_data data, int x, int y, int color);
void	ft_draw(t_data data);
void	ft_get_coler(t_data *data);
int		ft_atoi(char *num);
void	ft_get_coler(t_data *data);
void	ft_key_hook2(t_data *data, int keycode);
int		ft_key_hook(int keycode, void *param);
void	ft_mouse_zoom(t_data *data, int button, int x, int y);
int		ft_mouse_hook(int button, int x, int y, void *param);
void	ft_instruction(void);

#endif