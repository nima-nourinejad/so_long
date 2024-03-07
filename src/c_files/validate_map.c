/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:10:45 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/07 12:44:22 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_surrounded_wall(char	*map)
{
	ft_check_first_line_wall(map);
	ft_check_last_line_wall(map);
	ft_check_left_side_wall(map);
	ft_check_right_side_wall(map);
}

void	ft_validate_map(char *map)
{
	ft_check_all_char(map);
	ft_check_one_exit(map);
	ft_check_one_starting_position(map);
	ft_check_one_collectible(map);
	ft_check_rectangular(map);
	ft_check_surrounded_wall(map);
	ft_check_valid_path(map);
}
