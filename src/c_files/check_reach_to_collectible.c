/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reach_to_collectible.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:04:14 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/29 13:06:53 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_check_with_collectible_instance(mlx_image_t *player,
	mlx_image_t *collectible, int index)
{
	int			px;
	int			py;
	int			cx;
	int			cy;

	px = player->instances[0].x;
	py = player->instances[0].y;
	cx = collectible->instances[index].x;
	cy = collectible->instances[index].y;
	if (cx == px && cy == py)
		collectible->instances[index].enabled = 0;
}

void	ft_check_reach_to_collectible(t_window_elements *window_elements)
{
	mlx_image_t	*player;
	mlx_image_t	*collectible;
	int			count;
	int			index;

	player = (window_elements->elements)->player;
	collectible = (window_elements->elements)->collectible;
	count = ((*window_elements).elements_count).collectible_count;
	index = 0;
	while (index < count)
	{
		ft_check_with_collectible_instance(player, collectible, index);
		index++;
	}
}
