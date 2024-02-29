/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:55 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/29 17:12:44 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_character_counter(char character, char *map)
{
	int		fd_map;
	int		count;
	char	buffer_read;

	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	count = 0;
	while (read(fd_map, &buffer_read, 1))
		if (buffer_read == character)
			count++;
	close(fd_map);
	return (count);
}

int	ft_width_counter(char *map)
{
	int		fd_map;
	int		width_count;
	char	buffer_read;

	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	width_count = 0;
	while (read(fd_map, &buffer_read, 1))
	{
		if (buffer_read == '\n')
			break ;
		else
			width_count++;
	}
	close(fd_map);
	return (width_count);
}

int	ft_hight_counter(char *map)
{
	int		fd_map;
	int		hight_count;
	char	buffer_read;

	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	hight_count = 1;
	while (read(fd_map, &buffer_read, 1))
	{
		if (buffer_read == '\n')
			hight_count++;
	}
	close(fd_map);
	return (hight_count);
}

t_elements_count	ft_elements_count(char *map)
{
	t_elements_count	elements_count;

	elements_count.wall_count = ft_character_counter('1', map);
	elements_count.collectible_count = ft_character_counter('C', map);
	elements_count.exit_count = ft_character_counter('E', map);
	elements_count.player_count = ft_character_counter('P', map);
	elements_count.width_count = ft_width_counter(map);
	elements_count.hight_count = ft_hight_counter(map);
	return (elements_count);
}

t_window_elements	ft_create_window_elements(char *map)
{
	mlx_t					*window;
	t_elements				*elements;
	t_window_elements		window_elements;
	int						movement_count;

	window_elements.elements_count = ft_elements_count(map);
	window = mlx_init((window_elements.elements_count.width_count * 90),
			(window_elements.elements_count.hight_count * 90), "title", true);
	elements = ft_create_elements(window, window_elements.elements_count);
	ft_map_to_instance(window, elements, map);
	window_elements.window = window;
	window_elements.elements = elements;
	movement_count = 0;
	window_elements.movement_count = &movement_count;
	return (window_elements);
}
