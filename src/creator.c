#include "../includes/so_long.h"

bool get_coordinates(t_data *data)
{
    char **lines;
    int i;

    lines = NULL;
    i = 0;
    while (true)
    {
        lines[i] = ft_strdup(get_next_line(data->fd));
        if (lines[i][ft_strlen(lines[i])] == '\0')
            break;
        i++;
    }
    data->y = i;
    get_x(data, lines);
    return true;
}

bool get_x(t_data *data, char **lines)
{
    int i;

    i = data->y;
    data->x = ft_strlen(lines[i]);
    while (i-- > 0)
    {
        if (ft_strlen(ft_strtrim(lines[i], "\n")) != data->y)
            return false;
    }
    return true;
}