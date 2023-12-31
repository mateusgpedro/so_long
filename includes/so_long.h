#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "X11/X.h"
#include "../libft/ft_printf.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdbool.h>

#define SIZE 64
#define WALL "./sprites/Wall.xpm"
#define EMPTY "./sprites/Empty.xpm"
#define COLLECTIBLE "./sprites/Collectible.xpm"
#define EXIT_CLOSED "./sprites/Exit_Closed.xpm"
#define EXIT_OPEN "./sprites/Exit_Open.xpm"
#define PLAYER_DOWN "./sprites/Pacman_Down.xpm"
#define PLAYER_UP "./sprites/Pacman_Up.xpm"
#define PLAYER_LEFT "./sprites/Pacman_Left.xpm"
#define PLAYER_RIGHT "./sprites/Pacman_Right.xpm"

typedef struct s_vector {
    int x;
    int y;
}               t_vector;

typedef struct s_sprites {
    void*   collectibles_sprite;
    void*   exit_opened_sprite;
    void*   exit_closed_sprite;
    void*   wall_sprite;
    void*   empty_sprite;
    void*   player_sprite_left;
    void*   player_sprite_right;
    void*   player_sprite_up;
    void*   player_sprite_down;
}              t_sprites;

typedef struct s_data {
    void        *mlx;
    void        *window;
	int         collectibles;
    int         exits_found;
    int         players_found;
    char*       file_name;
	int         fd;
	int         width;
	int         height;
    char        **map;
    char        **map_dup;
    t_sprites   *sprites;
    t_vector    player_position;
}               t_data;

typedef enum s_error {
	INVALID_INPUT = 0,
	FILE_NOT_FOUND = 1,
    INVALID_MAP_SIZE_X = 2,
	UNKNOWN_CHARACTER = 3,
    MAP_NOT_CLOSED_BY_WALLS = 4,
    UNEXPECTED_NUMBER_OF_EXITS = 5,
    UNEXPECTED_NUMBER_OF_PLAYERS = 6,
    UNEXPECTED_NUMBER_OF_COLLECTIBLES = 7,
    UNREACHABLE_POSITION = 8
}				t_error;

// - - - Functions - - - 
bool    is_valid_input(char *str);
void	get_error(t_error error);
bool	validate_map(t_data *data, char *str);
void 	get_height(t_data *data);
void    get_width(t_data *data);
void    verify_file_data(t_data *data);
void    verify_walls(t_data *data);
char    *get_trimed_line(t_data *data, int index);
bool    floodfill(t_data *data, char **map, int x, int y);
void    store_map(t_data *data);
void    init_data(t_data *data, char *file_name);
void    check_characters(t_data *data);
void    duplicate_map(t_data *data);
void    init_map(t_data *data);
void    render_map(t_data *data);

#endif