#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "../libft/ft_printf.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdbool.h>

typedef struct s_data{
	int collectibles;
    int exits_found;
    int players_found;
    char* file_name;
	int fd;
	size_t width;
	size_t height;
    char **map;
}               t_data;

typedef enum s_error {
	INVALID_INPUT = 0,
	FILE_NOT_FOUND = 1,
    INVALID_MAP_SIZE_X = 2,
	UNKNOWN_CHARACTER = 3,
    MAP_NOT_CLOSED_BY_WALLS = 4
}				t_error;

// - - - Functions - - - 
bool    is_valid_input(char *str);
void	get_error(t_error error);
bool	validate_map(t_data *data, char *str);
void 	get_height(t_data *data);
void    get_x(t_data *data);
void    verify_file_data(t_data *data);
void    verify_walls(t_data *data);
char    *get_trimed_line(t_data *data, size_t index);
//void    floodfill(t_data *data);
void    store_map(t_data *data);
void    declare_data_vars(t_data *data);

#endif