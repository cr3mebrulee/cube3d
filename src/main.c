/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:49:07 by dbisko            #+#    #+#             */
/*   Updated: 2025/02/14 16:32:13 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int ac, char **av)
{
	char	*filename;
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (2);
	game->opts.debug_output_level = 0;
	if (opts_fill(ac -1, &av[1], game))
		return(5);
	filename = av[1];
	init_game(game);
	if (parse_file(filename, game))
	{
		free_game(game);
		return (3);
	}
	if (game->opts.debug_output_level & DBG_PRINT_MAP)
		print_map(game);
	free_game(game);
	return (0);
}
