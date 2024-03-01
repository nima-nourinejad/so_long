/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2024/03/01 17:08:30 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"

# define START_IMAGE_SIZE 100

typedef struct s_elements
{
	mlx_image_t	*empty_space;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	int			*start_image_size;
	int			*image_width;
	int			*image_height;
	int			*window_width;
	int			*window_height;
}				t_elements;

typedef struct s_elements_count
{
	int		wall_count;
	int		collectible_count;
	int		exit_count;
	int		player_count;
	int		width_count;
	int		hight_count;
	int		start_image_size;
	int		image_width;
	int		image_height;
	int		window_width;
	int		window_height;
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
	int		fd_map;
	int		character_width;
	int		character_height;
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
void				ft_escape_key(void *param);
void				ft_press_key(mlx_key_data_t keydata, void *param);
int					ft_make_color(int r, int g, int b, int a);
void				ft_color_backgroubd(mlx_image_t *background,
						int width, int hight);
mlx_image_t			*ft_create_background(mlx_t *window,
						int window_width, int window_height);
mlx_image_t			*ft_create_image(mlx_t *window, char c,
						int image_width, int image_height);
t_elements			*ft_create_elements(mlx_t *window,
						t_elements_count elements_count);
void				ft_map_to_instance_background(mlx_t *window,
						t_elements *elements);
void				ft_create_instance(mlx_t *window,
						t_elements *elements, t_point_data point_data);
t_point_data		ft_point_data_start(char *map,
						t_elements_count elements_count);
void				ft_map_to_instance_except_player(mlx_t *window,
						t_elements *elements,
						t_elements_count elements_count, char *map);
void				ft_map_to_instance_player(mlx_t *window,
						t_elements *elements,
						t_elements_count elements_count, char *map);
void				ft_map_to_instance(mlx_t *window,
						t_elements *elements,
						t_elements_count elements_count, char *map);
int					ft_character_counter(char character, char *map);
int					ft_width_counter(char *map);
int					ft_hight_counter(char *map);
t_elements_count	ft_elements_count(char *map);
void				ft_calculate_character_size(
						t_elements_count *elements_count);
t_window_elements	ft_create_window_elements(char *map);

#endif // SO_LONG_H