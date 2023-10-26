/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maguimar <maguimar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:16:18 by maguimar          #+#    #+#             */
/*   Updated: 2023/08/03 14:21:23 by maguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_data *data;
	
	data = ft_calloc(1, sizeof(t_data));
    init_data(data, argv[1]);
	if (argc != 2 || !is_valid_input(argv[1]))
		get_error(INVALID_INPUT);
	validate_map(data, argv[1]);
    data->mlx = mlx_init();
    data->window = mlx_new_window(data->mlx, (data->width * SIZE), (data->height * SIZE), "so_long");
    init_map(data);
    mlx_loop(data->mlx);
    return (0);
}