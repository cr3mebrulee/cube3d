/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taretiuk <taretiuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:30:27 by dbisko            #+#    #+#             */
/*   Updated: 2025/03/14 13:08:41 by taretiuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	remove_newline(char *line)
{
	if (!line)
		return ;
	while (*line)
	{
		if (*line == '\n')
		{
			*line = '\0';
			break ;
		}
		line++;
	}
}

int	print_invalid_line_error(t_bool map_started, t_line_result res)
{
	if (map_started)
	{
		if (res.error == LINE_ERR_MAP_OUT_OF_ORDER)
			ft_putstr_fd("Error\nInvalid file content order.\n", 2);
		else if (res.error == LINE_ERR_INVALID_MAP_CHAR)
			ft_putstr_fd("Error\nInvalid character in map.\n", 2);
	}
	else
	{
		ft_putstr_fd("Error\nInvalid input line.\n", 2);
	}
	return (1);
}

int	check_empty_file(char *line)
{
	if (!line)
	{
		ft_putstr_fd("Error\nFile is empty.\n", 2);
		return (1);
	}
	return (0);
}

char	*handle_empty_line(char *line, int fd)
{
	free(line);
	return (get_next_line(fd));
}
