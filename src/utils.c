/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:16:26 by maguimar          #+#    #+#             */
/*   Updated: 2023/08/03 14:25:31 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char *get_trimed_line(t_data *data, int index)
{
    char *line;

    if (index < data->height)
        line = ft_strtrim(get_next_line(data->fd), "\n");
    else
        line = get_next_line(data->fd);
    return (line);
}

void    declare_data_vars(t_data *data, char *file_name)
{
    data->collectibles = 0;
    data->players_found = 0;
    data->exits_found = 0;
    data->file_name = file_name;
}

void duplicate_map(t_data *data)
{
    int i;

    i = 0;
    data->map_dup = ft_calloc(data->height + 1, sizeof(char *));
    while (i < data->height)
    {
        data->map_dup[i] = ft_strdup(data->map[i]);
        i++;
    }
}

bool floodfill(t_data *data, char **map, int x, int y)
{
    static int exits;
    static int collectibles;

    if (y < 0 || x < 0 || y > data->height || x > data->width
        || map[y][x] == '1' || map[y][x] == 'X')
        return (false);
    if (map[y][x] == 'E')
    {
        exits++;
        map[y][x] = 'X';
        return (false);
    }
    if (map[y][x] == 'C')
        collectibles++;
    map[y][x] = 'X';
    floodfill(data, map, x - 1, y);
    floodfill(data, map, x + 1, y);
    floodfill(data, map, x, y +  1);
    floodfill(data, map, x, y +  1);
    if (exits == data->exits_found && collectibles == data->collectibles)
        return (true);
    else
        return (false);
}