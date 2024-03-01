/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:14:56 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/01 17:20:08 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

mlx_resizefunc	ft_resize(int new_width, int new_height, void *param)
{
	mlx_t				*window;
	t_elements_count	elements_count;

	window = ((t_window_elements *) param)->window;
	elements_count = (((t_window_elements *) param))->elements_count;
}