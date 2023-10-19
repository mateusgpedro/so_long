#include "../includes/so_long.h"

void init_map(t_data *data)
{
    data->sprites->collectibles_sprite = mlx_xpm_file_to_image(data->mlx, );
    data->sprites->empty_sprite = mlx_xpm_file_to_image();
    data->sprites->exit_sprite = mlx_xpm_file_to_image();
    data->sprites->player_sprite_down = mlx_xpm_file_to_image();
    data->sprites->player_sprite_up = mlx_xpm_file_to_image();
    data->sprites->player_sprite_left = mlx_xpm_file_to_image();
    data->sprites->player_sprite_right = mlx_xpm_file_to_image();

}