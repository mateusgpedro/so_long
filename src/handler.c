#include "../includes/so_long.h"

void get_error(t_error error)
{
    ft_printf("Error\n");
    if (error == INVALID_INPUT)
        ft_printf("Invalid input. Try again using ./so_long <filename>.ber\n");
    if (error == FILE_NOT_FOUND)
        ft_printf("Failed to find the respective file.\n");
    if (error == INVALID_MAP_SIZE_X)
        ft_printf("Invalid map size. The rows don't have the same width\n");
    if (error == UNKNOWN_CHARACTER)
        ft_printf("Unknown character! The map must be composed of only 5 possible characters: 0 for an empty space, 1 for a wall, C for a collectible, E for map exit and P for the player’s starting position.\n");
    if (error == MAP_NOT_CLOSED_BY_WALLS)
        ft_printf("Invalid map wall. The map should be close by walls all around it.\n");
    if (error == UNEXPECTED_NUMBER_OF_COLLECTIBLES)
        ft_printf("Unexpected number of collectibles found. The map should contain at least 1 collectible\n");
    if (error == UNEXPECTED_NUMBER_OF_PLAYERS)
        ft_printf("Unexpected number of players found. The map should contain only 1 player.\n");
    if (error == UNEXPECTED_NUMBER_OF_EXITS)
        ft_printf("Unexpected number of exits found. The map should contain only 1 exit.\n");
    if (error == UNREACHABLE_POSITION)
        ft_printf("Unreachable position. An exit or a collectible can't be reached by the player. Make sure the position is not surrounded by walls");
    exit(EXIT_FAILURE);
}