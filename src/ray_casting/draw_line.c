/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbisko <dbisko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:11:13 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/05 10:46:06 by dbisko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	calculate_wall_distance(t_game *game)
{
	double	perp_wall_dist;

	if (game->ray.side == 0)
		perp_wall_dist = (game->ray.map_x - game->player.x 
				+ (1 - game->ray.step_x) / 2.0) / game->ray.ray_dir_x;
	else
		perp_wall_dist = (game->ray.map_y - game->player.y 
				+ (1 - game->ray.step_y) / 2.0) / game->ray.ray_dir_y;
	return (perp_wall_dist);
}

int	get_wall_color(t_game *game)
{
	if (game->ray.side == 0) 
	{
		if (game->ray.ray_dir_x < 0)
			return (0xFFB6C1);  // East
		else
			return (0xE6E6FA);  // West
	}
	else 
	{
		if (game->ray.ray_dir_y < 0)
			return (0xADD8E6);  // North
		else
			return (0x90EE90);  // South
	}
}

// Compute wall stripe parameters.
void	get_line_params(t_game *game, t_line *line)
{
	line->wall_height = (int)(HEIGHT / game->ray.perp_wall_dist);
	line->draw_start = -line->wall_height / 2 + HEIGHT / 2;
	if (line->draw_start < 0)
		line->draw_start = 0;
	line->draw_end = line->wall_height / 2 + HEIGHT / 2;
	if (line->draw_end >= HEIGHT)
		line->draw_end = HEIGHT - 1;
	line->color = get_wall_color(game);
}

void	draw_wall_line(t_game *game, t_img *pov, int x)
{	// cast_and_render_minimap(game);
	double		perp_wall_dist;
	t_line		line;
	int			y;
	int			*img_data;
	int			line_length;

	perp_wall_dist = calculate_wall_distance(game);
	game->ray.perp_wall_dist = perp_wall_dist;
	get_line_params(game, &line);
	y = line.draw_start;
	while (y <= line.draw_end)
	{
		img_data = (int *)pov->addr;
		line_length = pov->size_line / 4;
		if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
			img_data[y * line_length + x] = line.color;
		y++;
	}
}
