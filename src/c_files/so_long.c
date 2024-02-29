/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/29 13:13:06 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	main(void)
{
	t_window_elements		window_elements;

	window_elements = ft_create_window_elements();
	mlx_key_hook(window_elements.window, &ft_move, &window_elements);
	mlx_loop(window_elements.window);
	ft_exit_success (window_elements.window, window_elements.elements);
}
