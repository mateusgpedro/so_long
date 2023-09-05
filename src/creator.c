#include "../includes/so_long.h"

void get_y(t_data *data)
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
		data->y++;
    }
    free(tmp);
    close(data->fd);
}

void get_x(t_data *data)
{
    char    *tmp;
    size_t     i;

    data->fd = open(data->file_name, O_RDONLY);
    i = 0;
    while (i < data->y)
    {
        if (i < data->y)
            tmp = ft_strtrim(get_next_line(data->fd), "\n");
        else
            tmp = get_next_line(data->fd);
        if (data->x != ft_strlen(tmp) && i > 0)
        {
            get_error(INVALID_MAP_SIZE_X);
            exit(EXIT_FAILURE);
        }
        data->x = ft_strlen(tmp);
        free(tmp);
        i++;
    }
}