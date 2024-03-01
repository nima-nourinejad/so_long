/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_character_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:22:07 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/01 17:03:50 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_calculate_character_size(t_elements_count *elements_count)
{
	int			monitor_width;
	int			monitor_height;
	float		ratio_width;
	float		final_ratio;
	mlx_t		*temp_window;

	temp_window = mlx_init(100, 100, "temp_window", true);
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	mlx_terminate(temp_window);
	(*elements_count).start_image_size = START_IMAGE_SIZE;
	ratio_width = monitor_width / START_IMAGE_SIZE;
	ratio_width = ratio_width / (*elements_count).width_count;
	final_ratio = monitor_height
		/ (START_IMAGE_SIZE * (*elements_count).hight_count);
	if (ratio_width < final_ratio)
		final_ratio = ratio_width;
	if (final_ratio > 1)
		final_ratio = 1;
	(*elements_count).image_width = floor(final_ratio * START_IMAGE_SIZE);
	(*elements_count).image_height = floor(final_ratio * START_IMAGE_SIZE);
	(*elements_count).window_width = ceil((*elements_count).image_width
			* (*elements_count).width_count);
	(*elements_count).window_height = ceil((*elements_count).image_height
			* (*elements_count).hight_count);
}
