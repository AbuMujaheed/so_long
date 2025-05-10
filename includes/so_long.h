/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojetimi <sojetimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:01:13 by sojetimi          #+#    #+#             */
/*   Updated: 2025/05/10 16:28:09 by sojetimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_texture
{
	void	*img;
	int		width;
	int		height;
}	t_texture;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			tile_size;
	void		*background_img;
	t_texture	wall;
	t_texture	floor;
	t_texture	dolphin;
	t_texture	fish;
	t_texture	earth;
	int			player_x;
	int			player_y;
	int			moves;
	int			collected;
	int			total_collectibles;
	int			exit_count;
	int			player_count;
	int			move_count;

}	t_game;

typedef struct s_map_info
{
	char	**map;
	int		width;
	int		height;
}	t_map_info;

/* error.c */
void		ft_exit(const char *msg);
void		error_exit(const char *msg);
void		error_free_map(const char *msg, char **map);

/* exit.c */
void		free_map(char **map);
void		exit_game(t_game *g, char *msg);
int			x_close(t_game *game);

/* map.c */
char		**load_map(char *file, t_game *game);

/*map_utils.c*/
int			count_map_rows(const char *file);
void		check_file_extension(const char *filename);
void		check_map_validity(char **map);

/* init_game.c */
int			init_game(t_game *game, char *file);
// static int	count_map_rows_b(const char *file);

/* render.c */
void		render_map(t_game *game);

/* movement.c */
int			handle_input(int keycode, t_game *game);

// validate_map
int			validate_map(char **map, t_game *g);

// check_map_walls
int			check_walls(t_game *g);

//read_map_info
t_map_info	read_map_info(const char *file);

// free_map_info
void		free_map_info(t_map_info *info);

//check_map_walls_2
int			check_walls_b(t_map_info *g);

// check_map_path
void		check_path(t_game *g);

// copy_map
char		**copy_map(char **map);

// flood_fill
void		flood_fill(char **map, int y, int x);

// scrn_mvs_counter
void		render_move_counter(t_game *g);

#endif
