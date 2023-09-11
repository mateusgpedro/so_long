#ifndef SO_LONG_H
# define SO_LONG_H

#include "get_next_line.h"
#include "../libft/ft_printf.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdbool.h>

typedef struct s_data{
	int collectibles;
    char* file_name;
	int fd;
	size_t x;
	size_t y;
}               t_data;

typedef enum s_error {
	INVALID_INPUT = 0,
	FILE_NOT_FOUND = 1,
    INVALID_MAP_SIZE_X = 2
}				t_error;

// - - - Functions - - - 
bool    is_valid_input(char *str);
void	get_error(t_error error);
bool	validate_map(t_data *data, char *str);
void 	get_y(t_data *data);
void    get_x(t_data *data);
void    verify_file_data(t_data *data);

#endif