#ifndef SO_LONG_H
# define SO_LONG_H

# pragma region // ERRORS

typedef enum _error{
    INVALID_EXTENSION = 0
}       t_error;

#pragma endregion

# pragma region // INCLUDES

#include "get_next_line.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <string.h>

# pragma endregion

# pragma region // KEYWORDS

typedef enum s_bool{
    true = 1,
    false = 0
}       bool;

# define foreach(item, array, size) \
    size_t i; \
\
    i = 0; \
    while (i < size) \
    { \
        item = array[i]; \
        

# define endforeach \
        i++; \
    }
# pragma endregion

# pragma region // STRUCTS

typedef struct s_data{
    int collectibles;
}               t_data

# pragma endregion

# pragma region // FUNCTIONS

// - - - ERRORS - - -

void    error(t_error error);

#pragma endregion

#endif