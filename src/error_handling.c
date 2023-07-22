#include "../includes/so_long.h"

void    error(t_error error)
{
	if (error == INVALID_EXTENSION)
		ft_printf("Error\n Invalid extension! Try \"<filename>.ber\"");

	exit(EXIT_FAILURE);
}