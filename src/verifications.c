#include "../includes/so_long.h"

bool is_valid_input(char *str)
{
	char *s;
	s = ft_strrchr(str, '.');
	if (!s)
		return (false);
	if (ft_strcmp(s, ".ber\0") != 0)
		return (false);
	return (true);
}

bool validate_map(char *str)
{
	int fd;
	char **lines;
	
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		get_error(FILE_NOT_FOUND);
		return (false);
	}
	while ()
	
	return (true);
}

void get_error(t_error error)
{
	if (error == INVALID_INPUT)
		ft_printf("Error\n Invalid input. Try again using ./so_long <filename>.ber");
	if (error == FILE_NOT_FOUND)
		ft_printf("Error\n Failed to find the respective file.");
}