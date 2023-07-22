#include "../includes/so_long.h"

bool is_valid_input(char *input_file)
{
    char *extension;

    extension = ft_strrchr(input_file, '.');
    if (ft_strcmp(extension, ".ber") != 0)
    {
        error(INVALID_EXTENSION);
        return false;
    }
}