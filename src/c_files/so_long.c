/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:23:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/01 16:41:22 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	main(int argc, char **argv)
{
	t_window_elements		window_elements;

	if (argc != 2)
		ft_exit_failure(0, 0, "the wrong number of arguments");
	window_elements = ft_create_window_elements(argv[1]);
	mlx_key_hook(window_elements.window, &ft_press_key, &window_elements);
	mlx_loop(window_elements.window);
	ft_exit_success (window_elements.window, window_elements.elements);
}
