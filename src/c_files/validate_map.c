/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:10:45 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/06 17:40:22 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_check_each_char(char c)
{
	if (c == '0')
		return (1);
	if (c == '1')
		return (1);
	if (c == 'C')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'P')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

void	ft_check_all_char(char *map)
{
	int		fd_map;
	char	buffer;

	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	while (read(fd_map, &buffer, 1))
	{
		if (!ft_check_each_char(buffer))
		{
			close(fd_map);
			ft_exit_failure(0, 0, "Wrong characters");
		}
	}
	close(fd_map);
}

void	ft_check_one_exit(char *map)
{
	int		fd_map;
	char	buffer;
	int		counter;

	counter = 0;
	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	while (read(fd_map, &buffer, 1))
		if (buffer == 'E')
			counter++;
	close(fd_map);
	if (counter != 1)
		ft_exit_failure(0, 0, "Wrong number of exit");
}

void	ft_check_one_starting_position(char *map)
{
	int		fd_map;
	char	buffer;
	int		counter;

	counter = 0;
	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	while (read(fd_map, &buffer, 1))
		if (buffer == 'P')
			counter++;
	close(fd_map);
	if (counter != 1)
		ft_exit_failure(0, 0, "Wrong number of starting position");
}

void	ft_check_one_collectible(char *map)
{
	int		fd_map;
	char	buffer;
	int		counter;

	counter = 0;
	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	while (read(fd_map, &buffer, 1))
		if (buffer == 'C')
			counter++;
	close(fd_map);
	if (counter == 0)
		ft_exit_failure(0, 0, "No collectible");
}

t_read_data	ft_read_line(int fd_map)
{
	t_read_data	read_data;

	read_data.buffer = '\0';
	read_data.counter = 0;
	read_data.read = read(fd_map, &(read_data.buffer), 1);
	while (read_data.read)
	{
		if (read_data.buffer == '\n')
			return (read_data);
		else
			read_data.counter++;
		read_data.read = read(fd_map, &(read_data.buffer), 1);
	}
	return (read_data);
}

void	ft_check_rectangular(char *map)
{
	int				fd_map;
	t_read_data		line1;
	t_read_data		next_line;

	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	line1 = ft_read_line(fd_map);
	next_line = ft_read_line(fd_map);
	while (next_line.read)
	{
		if (next_line.counter != line1.counter)
		{
			close(fd_map);
			ft_exit_failure(0, 0, "Map is not rectangular");
		}
		next_line = ft_read_line(fd_map);
	}
	close(fd_map);
	if (next_line.counter != line1.counter)
		ft_exit_failure(0, 0, "Map is not rectangular");
}

void	ft_check_char_wall(char buffer, int fd_map)
{
	if (buffer != '1')
	{
		close(fd_map);
		ft_exit_failure(0, 0, "The map is not surrounded by walls");
	}
}

void ft_check_first_line_wall(char *map)
{
	int		fd_map;
	char	buffer;

	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	while (read(fd_map, &buffer, 1))
	{
		if (buffer == '\n')
			break ;
		ft_check_char_wall(buffer, fd_map);
	}
	close(fd_map);
}

void ft_check_last_line_wall(char *map)
{
	int		fd_map;
	int		height;
	int		line_num;
	char	buffer;

	height = ft_hight_counter(map);
	line_num = 1;
	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	while (read(fd_map, &buffer, 1))
	{
		if (line_num == height)
		{
			while (read(fd_map, &buffer, 1))
				ft_check_char_wall(buffer, fd_map);
			break ;
		}
		else if (buffer == '\n')
			line_num++;
	}
	close(fd_map);
}

void ft_check_left_side_wall(char *map)
{
	int		fd_map;
	int		triger;
	char	buffer;

	triger = 1;
	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	while (read(fd_map, &buffer, 1))
	{
		if (triger == 1)
		{
			ft_check_char_wall(buffer, fd_map);
			triger = 0;
		}
		if (buffer == '\n')
			triger = 1;
	}
	close(fd_map);
}

void ft_check_right_side_wall(char *map)
{
	int		fd_map;
	char	buffer;
	char	temp;

	fd_map = open(map, O_RDONLY);
	if (fd_map == -1)
		ft_exit_failure(0, 0, "Map opening problem");
	temp = '\0';
	while (read(fd_map, &buffer, 1))
	{
		if (buffer == '\n')
			ft_check_char_wall(temp, fd_map);
		temp = buffer;
	}
	ft_check_char_wall(temp, fd_map);
	close(fd_map);
}

void	ft_check_surrounded_wall(char	*map)
{
	ft_check_first_line_wall(map);
	ft_check_last_line_wall(map);
	ft_check_left_side_wall(map);
	ft_check_right_side_wall(map);
}

void	ft_check_valid_path(t_map_data	*start)
{
	t_map_data	*node;

	node = start;
	while (node)
	{
		if ((*node).ch == 'E' && !(*node).t)
		{
			ft_free_map_data(start);
			ft_exit_failure(0, 0, "No valid path");
		}
		if ((*node).ch == 'C' && !(*node).t)
		{
			ft_free_map_data(start);
			ft_exit_failure(0, 0, "No valid path");
		}
		node = node->next;
	}
}

void ft_flood_fill(char *map)
{
	t_map_data	*start;

	start = ft_create_map_data(map, -1, 0);
	ft_flood(start);
	ft_check_valid_path(start);
	ft_free_map_data(start);
}

void	ft_validate_map(char *map)
{
	ft_check_all_char(map);
	ft_check_one_exit(map);
	ft_check_one_starting_position(map);
	ft_check_one_collectible(map);
	ft_check_rectangular(map);
	ft_check_surrounded_wall(map);
	ft_flood_fill(map);
}
