/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:04:03 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/29 16:00:58 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

mlx_image_t	*ft_create_image(mlx_t *window, char c)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	if (c == '1')
		texture = mlx_load_png("./src/images/wall.png");
	else if (c == 'C')
		texture = mlx_load_png("./src/images/collectible.png");
	else if (c == 'E')
		texture = mlx_load_png("./src/images/exit.png");
	else
		texture = mlx_load_png("./src/images/player.png");
	if (!texture)
		ft_exit_failure(window, 0, "Texture creation problem");
	image = mlx_texture_to_image (window, texture);
	mlx_delete_texture(texture);
	if (!image)
		ft_exit_failure(window, 0, "Image creation problem");
	if (!mlx_resize_image(image, 90, 90))
		ft_exit_failure(window, 0, "Resize problem");
	return (image);
}

t_elements	*ft_create_elements(mlx_t *window, t_elements_count elements_count)
{
	t_elements	*elements;

	elements = malloc(sizeof(t_elements));
	if (!elements)
		ft_exit_failure(window, 0, "Elements creting problem");
	elements->empty_space = ft_create_background(window, elements_count);
	elements->wall = ft_create_image(window, '1');
	elements->collectible = ft_create_image(window, 'C');
	elements->exit = ft_create_image(window, 'E');
	elements->player = ft_create_image(window, 'P');
	return (elements);
}
