/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:42:52 by taretiuk          #+#    #+#             */
/*   Updated: 2025/02/26 13:15:13 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	finalize(t_game *game, char *message, int retval)
{
	if (game)
	{
		free_game(game);
	}
	if (message)
		printf("%s\n", message);
	return (retval);
}
