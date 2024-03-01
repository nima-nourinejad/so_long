/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_data_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:57:39 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/01 12:10:38 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

t_point_data	ft_point_data_start(char *map, t_elements_count elements_count)
{
	t_point_data	point_data;

	point_data.fd_map = open(map, O_RDONLY);
	point_data.x_position = 0;
	point_data.y_position = 0;
	point_data.character = '\0';
	point_data.character_width
		= START_WINDOW_WIDTH / elements_count.width_count;
	point_data.character_height
		= START_WINDOW_HEIGHT / elements_count.hight_count;
	return (point_data);
}
