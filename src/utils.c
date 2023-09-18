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

char *get_trimed_line(t_data *data, size_t index)
{
    char *line;

    if (index < data->height)
        line = ft_strtrim(get_next_line(data->fd), "\n");
    else
        line = get_next_line(data->fd);
    return (line);
}

void    declare_data_vars(t_data *data)
{
    data->collectibles = 0;
    data->players_found = 0;
    data->exits_found = 0;
}

//void floodfill(t_data *data)
//{

//}