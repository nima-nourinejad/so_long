/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:55 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/29 15:01:15 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_character_counter(char character, mlx_t *window, t_elements *elements)
{
	int		fd_map;
	int		count;
	char	buffer_read;

	fd_map = open("./map.ber", O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(window, elements, "Map opening problem");
	count = 0;
	while (read(fd_map, &buffer_read, 1))
		if (buffer_read == character)
			count++;
	close(fd_map);
	return (count);
}

int	ft_width_counter(mlx_t *window, t_elements *elements)
{
	int		fd_map;
	int		width_count;
	char	buffer_read;

	fd_map = open("./map.ber", O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(window, elements, "Map opening problem");
	width_count = 0;
	while (read(fd_map, &buffer_read, 1))
	{
		width_count++;
		if (buffer_read == '\n')
			break ;
	}
	close(fd_map);
	return (width_count);
}

int	ft_hight_counter(mlx_t *window, t_elements *elements)
{
	int		fd_map;
	int		hight_count;
	char	buffer_read;

	fd_map = open("./map.ber", O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(window, elements, "Map opening problem");
	hight_count = 1;
	while (read(fd_map, &buffer_read, 1))
	{
		if (buffer_read == '\n')
			hight_count++;
	}
	close(fd_map);
	return (hight_count);
}

t_elements_count	ft_elements_count(mlx_t *window, t_elements *elements)
{
	t_elements_count	elements_count;

	elements_count.wall_count = ft_character_counter('1', window, elements);
	elements_count.collectible_count = ft_character_counter('C',
			window, elements);
	elements_count.exit_count = ft_character_counter('E', window, elements);
	elements_count.player_count = ft_character_counter('P', window, elements);
	elements_count.width_count = ft_width_counter(window, elements);
	elements_count.hight_count = ft_hight_counter(window, elements);
	return (elements_count);
}

t_window_elements	ft_create_window_elements(char *map)
{
	mlx_t					*window;
	t_elements				*elements;
	t_window_elements		window_elements;
	int						movement_count;

	window = mlx_init(1170, 450, "title", true);
	elements = ft_create_elements(window);
	ft_map_to_instance(window, elements, map);
	window_elements.window = window;
	window_elements.elements = elements;
	window_elements.elements_count = ft_elements_count(window, elements);
	movement_count = 0;
	window_elements.movement_count = &movement_count;
	return (window_elements);
}
