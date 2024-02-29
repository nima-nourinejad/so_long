/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_backgroub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:06:42 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/29 16:59:53 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_make_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_color_backgroubd(mlx_image_t *background, int width, int hight)
{
	int	x_index;
	int	y_index;

	x_index = 0;
	while (x_index < width)
	{
		y_index = 0;
		while (y_index < hight)
		{
			mlx_put_pixel(background, x_index, y_index,
				ft_make_color(100, 100, 100, 200));
			y_index++;
		}
		x_index++;
	}
}



mlx_image_t	*ft_create_background(mlx_t *window,
	t_elements_count elements_count)
{
	int				width;
	int				hight;
	mlx_image_t		*background;

	width = elements_count.width_count * 90;
	hight = elements_count.hight_count * 90;
	// width = 1170;
	// hight = 450;
	// ft_printf("width: %d and hight: %d\n", width, hight);
	background = mlx_new_image (window, width, hight);
	if (!background)
		ft_exit_failure(window, 0, "background creation problem");
	ft_color_backgroubd(background, width, hight);
	return (background);
}
