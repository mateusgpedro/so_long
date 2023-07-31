#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	if (argc != 2 || !is_valid_input(argv[1]))
		get_error(INVALID_INPUT);

    return 0;
}