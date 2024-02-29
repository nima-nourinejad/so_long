/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:48 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/29 13:06:01 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_exit_failure(mlx_t *mlx, t_elements *elements, char *error_message)
{
	if (mlx)
		mlx_terminate(mlx);
	if (elements)
		free (elements);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_message, 2);
	ft_putstr_fd("\n", 2);
	exit (EXIT_FAILURE);
}

int	ft_exit_success(mlx_t *mlx, t_elements *elements)
{
	if (mlx)
		mlx_terminate(mlx);
	if (elements)
		free (elements);
	exit(EXIT_SUCCESS);
}
