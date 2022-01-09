/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mrab <yel-mrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 12:43:41 by yel-mrab          #+#    #+#             */
/*   Updated: 2022/01/02 17:39:00 by yel-mrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(char *num)
{
	int	number;
	int	index;

	index = 0;
	number = 0;
	while (num[index])
	{
		number = number * 10 + (num[index] - 48);
		index++;
	}
	return (number);
}

double	ft_map(int in, double min, double max)
{
	double	maped;

	maped = in * ((max - min) / 600) + min;
	return (maped);
}

void	ft_instruction(void)
{
	write(1, "############# Instruction ##############\n", 41);
	write(1, "# arrows        - Up Down Right Left   #\n", 41);
	write(1, "# mouse wheel   - Zoom                 #\n", 41);
	write(1, "# mouse buttons - Use them whith julia #\n", 41);
	write(1, "#                                      #\n", 41);
	write(1, "# r - Reset                            #\n", 41);
	write(1, "# p - Change color                     #\n", 41);
	write(1, "# z - Increase the max iteration       #\n", 41);
	write(1, "# n - Decrease the max iteration       #\n", 41);
	write(1, "# esc | q - Quit                       #\n", 41);
	write(1, "########################################\n", 41);
}
