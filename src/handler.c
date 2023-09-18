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
    if (error == UNKNOWN_CHARACTER)
        ft_printf("Unknown character! The map must be composed of only 5 possible characters: 0 for an empty space, 1 for a wall, C for a collectible, E for map exit and P for the player’s starting position.");
    if (error == MAP_NOT_CLOSED_BY_WALLS)
        ft_printf("Invalid map wall. The map should be close by walls all around it.");
    exit(EXIT_FAILURE);
}