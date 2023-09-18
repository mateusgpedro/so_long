#include "../includes/so_long.h"

void    get_height(t_data *data)
{
    char* tmp;

    while (true)
    {
        tmp = get_next_line(data->fd);
        if (!tmp)
        {
            break;
        }
        free(tmp);
		data->height++;
    }
    free(tmp);
    close(data->fd);
}

void    get_width(t_data *data)
{
    char    *tmp;
    int     i;

    data->fd = open(data->file_name, O_RDONLY);
    i = 0;
    while (i < data->height)
    {
        if (i < data->height)
            tmp = ft_strtrim(get_next_line(data->fd), "\n");
        else
            tmp = get_next_line(data->fd);
        if (data->width != (int) ft_strlen(tmp) && i > 0)
        {
            get_error(INVALID_MAP_SIZE_X);
            exit(EXIT_FAILURE);
        }
        data->width = (int) ft_strlen(tmp);
        free(tmp);
        i++;
    }
    close(data->fd);
}

void store_map(t_data *data)
{
    int      i;
    int      j;
    char    *tmp;

    i = 0;
    data->fd = open(data->file_name, O_RDONLY);
    data->map = ft_calloc(data->height + 1, sizeof(char *));
    while (i < data->height)
    {
        j = 0;
        tmp = get_trimed_line(data, i);
        data->map[i] = tmp;
        while (j < data->width)
        {
            if (tmp[j] == 'C')
                data->collectibles++;
            else if (tmp[j] == 'E')
                data->exits_found++;
            else if (tmp[j] == 'P')
            {
                data->players_found++;
                data->player_position.y = i;
                data->player_position.x = j;
            }
            j++;
        }
        i++;
    }
    close(data->fd);
}