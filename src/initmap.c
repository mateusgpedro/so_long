#include "../includes/so_long.h"

void init_map(t_data *data)
{
    data->sprites->collectibles_sprite = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE, &data->width, &data->height);
    data->sprites->empty_sprite = mlx_xpm_file_to_image(data->mlx, EMPTY, &data->width, &data->height);
    data->sprites->exit_closed_sprite = mlx_xpm_file_to_image(data->mlx, EXIT_CLOSED, &data->width, &data->height);
    data->sprites->exit_opened_sprite = mlx_xpm_file_to_image(data->mlx, EXIT_OPEN, &data->width, &data->height);
    data->sprites->player_sprite_down = mlx_xpm_file_to_image(data->mlx, PLAYER_DOWN, &data->width, &data->height);
    data->sprites->player_sprite_up = mlx_xpm_file_to_image(data->mlx, PLAYER_UP, &data->width, &data->height);
    data->sprites->player_sprite_left = mlx_xpm_file_to_image(data->mlx, PLAYER_LEFT, &data->width, &data->height);
    data->sprites->player_sprite_right = mlx_xpm_file_to_image(data->mlx, PLAYER_RIGHT, &data->width, &data->height);
    render_map(data);
}

void render_map(t_data *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (data->map[y][x] == '1')
                mlx_put_image_to_window(data->mlx,
                data->window, data->sprites->wall_sprite,
                x * SIZE, y * SIZE);
            else if (data->map[y][x] == '0')
                mlx_put_image_to_window(data->mlx,
                data->window, data->sprites->empty_sprite,
                x * SIZE, y * SIZE);
            else if (data->map[y][x] == 'P')
                mlx_put_image_to_window(data->mlx,
                data->window, data->sprites->player_sprite_right,
                x * SIZE, y * SIZE);
            else if (data->map[y][x] == 'C')
                mlx_put_image_to_window(data->mlx,
                data->window, data->sprites->collectibles_sprite,
                x * SIZE, y * SIZE);
            else if (data->map[y][x] == 'E')
                mlx_put_image_to_window(data->mlx,
                data->window, data->sprites->exit_closed_sprite,
                x * SIZE, y * SIZE);
            x++;
        }
        y++;
    }
}