/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/02/29 13:59:17 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

typedef struct s_elements
{
	mlx_image_t	*empty_space;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}				t_elements;

typedef struct s_elements_count
{
	int		wall_count;
	int		collectible_count;
	int		exit_count;
	int		player_count;
	int		total_count;
}			t_elements_count;

typedef struct s_window_elements
{
	mlx_t				*window;
	t_elements			*elements;
	t_elements_count	elements_count;
	int					*movement_count;
}				t_window_elements;

typedef struct s_point_data
{
	int		x_position;
	int		y_position;
	char	character;
}				t_point_data;

int					ft_exit_failure(mlx_t *mlx,
						t_elements *elements, char *error_message);
int					ft_exit_success(mlx_t *mlx, t_elements *elements);
void				ft_check_with_collectible_instance(mlx_image_t *player,
						mlx_image_t *collectible, int index);
void				ft_check_reach_to_collectible(
						t_window_elements *window_elements);
int					ft_check_with_wall_instance_up(mlx_image_t *player,
						mlx_image_t *wall, int index);
int					ft_check_with_wall_instance_down(mlx_image_t *player,
						mlx_image_t *wall, int index);
int					ft_check_with_wall_instance_left(mlx_image_t *player,
						mlx_image_t *wall, int index);
int					ft_check_with_wall_instance_right(mlx_image_t *player,
						mlx_image_t *wall, int index);
int					ft_check_with_wall_instance(mlx_image_t *player,
						mlx_image_t *wall, int index, char move);
int					ft_check_near_wall(t_window_elements *window_elements,
						char move);
int					ft_check_all_collectible_done(
						t_window_elements *window_elements);
void				ft_check_reach_to_exit(t_window_elements *window_elements,
						mlx_image_t *player,	mlx_image_t *exit);
void				ft_check_exit(t_window_elements *window_elements);
void				ft_move_up(void *param);
void				ft_move_down(void *param);
void				ft_move_right(void *param);
void				ft_move_left(void *param);
void				ft_move(mlx_key_data_t keydata, void *param);
mlx_image_t			*ft_create_image(mlx_t *window, char c);
t_elements			*ft_create_elements(mlx_t *window);
void				ft_create_instance(mlx_t *window,
						t_elements *elements, t_point_data point_data);
void				ft_map_to_instance_except_player(mlx_t *window,
						t_elements *elements, char *map);
void				ft_map_to_instance_player(mlx_t *window,
						t_elements *elements, char *map);
void				ft_map_to_instance(mlx_t *window,
						t_elements *elements, char *map);
int					ft_character_counter(char character,
						mlx_t *window, t_elements *elements);
t_elements_count	ft_elements_count(mlx_t *window, t_elements *elements);
t_window_elements	ft_create_window_elements(char *map);

#endif // SO_LONG_H