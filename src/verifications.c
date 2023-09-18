/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:16:21 by maguimar          #+#    #+#             */
/*   Updated: 2023/08/03 14:24:31 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "get_next_line.h"

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

bool validate_map(t_data *data, char *str)
{
	data->fd = open(str, O_RDONLY);
	if (data->fd < 0)
	{
		get_error(FILE_NOT_FOUND);
		return (false);
	}
	get_height(data);
    get_x(data);
    verify_file_data(data);
    verify_walls(data);
    store_map(data);
    return (true);
}

void verify_file_data(t_data *data)
{
    char    *tmp;
    size_t     i;
	size_t		j;

    i = 0;
    data->fd = open(data->file_name, O_RDONLY);
    while (i < data->height)
    {
		j = 0;
		tmp = get_trimed_line(data, i);
        while (j < data->width)
		{
			if (tmp[j] != '1' && tmp[j] != '0' && tmp[j] != 'P' && tmp[j] != 'E' && tmp[j] != 'C')
				get_error(UNKNOWN_CHARACTER);
            j++;
		}
        i++;
        free(tmp);
    }
    close(data->fd);
}

void verify_walls(t_data *data)
{
    size_t      i;
    size_t      j;
    char    *tmp;

    i = 0;
    data->fd = open(data->file_name, O_RDONLY);
    while (i < data->height)
    {
        j = 0;
        tmp = get_trimed_line(data, i);
        while ((i == 0 || i == data->height) && j < data->width)
        {
            if (tmp[j] != '1')
                get_error(MAP_NOT_CLOSED_BY_WALLS);
            j++;
        }
        if (tmp[0] != '1' || tmp[data->width - 1] != '1')
            get_error(MAP_NOT_CLOSED_BY_WALLS);
        i++;
        free(tmp);
    }
    close(data->fd);
}

void check_characters(t_data *data)
{
    if (data.)
}
