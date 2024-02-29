/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_instance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:40 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/29 13:21:31 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_create_instance(mlx_t *window,
	t_elements *elements, t_point_data point_data)
{
	mlx_image_t	*image;

	if (point_data.character == '0')
		image = elements->empty_space;
	else if (point_data.character == '1')
		image = elements->wall;
	else if (point_data.character == 'C')
		image = elements->collectible;
	else if (point_data.character == 'E')
		image = elements->exit;
	else
		image = elements->player;
	if (point_data.character == 'C')
	{
		if (mlx_image_to_window(window, elements->empty_space,
				point_data.x_position, point_data.y_position) == -1)
			ft_exit_failure(window, elements, "Insance making problem");
	}
	if (mlx_image_to_window(window, image,
			point_data.x_position, point_data.y_position) == -1)
		ft_exit_failure(window, elements, "Insance making problem");
}

void	ft_map_to_instance_except_player(mlx_t *window, t_elements *elements)
{
	int				fd_map;
	t_point_data	point_data;

	fd_map = open("./map.ber", O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(window, elements, "Map opening problem");
	point_data.x_position = 0;
	point_data.y_position = 0;
	point_data.character = '\0';
	while (read(fd_map, &(point_data.character), 1))
	{
		if (point_data.character == '\n')
		{
			point_data.x_position = 0;
			point_data.y_position = point_data.y_position + 90;
		}
		else
		{
			if (point_data.character == 'P')
				point_data.character = '0';
			ft_create_instance(window, elements, point_data);
			point_data.x_position = point_data.x_position + 90;
		}
	}
	close(fd_map);
}

void	ft_map_to_instance_player(mlx_t *window, t_elements *elements)
{
	int				fd_map;
	t_point_data	point_data;

	fd_map = open("./map.ber", O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(window, elements, "Map opening problem");
	point_data.x_position = 0;
	point_data.y_position = 0;
	point_data.character = '\0';
	while (read(fd_map, &(point_data.character), 1))
	{
		if (point_data.character == '\n')
		{
			point_data.x_position = 0;
			point_data.y_position = point_data.y_position + 90;
		}
		else
		{
			if (point_data.character == 'P')
				ft_create_instance(window, elements, point_data);
			point_data.x_position = point_data.x_position + 90;
		}
	}
	close(fd_map);
}

void	ft_map_to_instance(mlx_t *window, t_elements *elements)
{
	ft_map_to_instance_except_player(window, elements);
	ft_map_to_instance_player(window, elements);
}
