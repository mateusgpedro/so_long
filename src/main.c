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
	if (argc != 2 || !is_valid_input(argv[1]))
		get_error(INVALID_INPUT);
	validate_map(data, argv[1]);
    return 0;
}