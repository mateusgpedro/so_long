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
	if (get_coordinates(data) == false)
		return (false);
	return (true);
}

void get_error(t_error error)
{
	if (error == INVALID_INPUT)
		ft_printf("Error\n Invalid input. Try again using ./so_long <filename>.ber");
	if (error == FILE_NOT_FOUND)
		ft_printf("Error\n Failed to find the respective file.");
}