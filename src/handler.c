#include "../includes/so_long.h"

void get_error(t_error error)
{
    ft_printf("Error\n");
    if (error == INVALID_INPUT)
        ft_printf("Invalid input. Try again using ./so_long <filename>.ber\n");
    if (error == FILE_NOT_FOUND)
        ft_printf("Failed to find the respective file.\n");
    if (error == INVALID_MAP_SIZE_X)
        ft_printf("Invalid map size. The rows don't have the same width");
}