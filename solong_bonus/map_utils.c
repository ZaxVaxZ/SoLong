/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:26:57 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/11 15:18:37 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

void	get_map_size(int fd, int *r, int *c, t_map *g)
{
	char	*line;
	int		tmpc;

	*r = 0;
	*c = 0;
	line = get_next_line(fd);
	while (line)
	{
		tmpc = 0;
		while (*line && *line != '\n' && ++tmpc)
		{
			if (*line == 'P')
				g->px = *r;
			if (*line == 'P')
				g->py = tmpc - 1;
			line++;
		}
		line -= tmpc;
		*c += !(*c) * tmpc;
		*c = *c * (tmpc == *c) - (tmpc != *c);
		free(line);
		(*r)++;
		line = get_next_line(fd);
	}
	close(fd);
}

char	**parse_map(int fd, t_map *game)
{
	int		j;
	int		i;
	char	*line;

	game->coins = 0;
	game->map = malloc((game->rows + 1) * sizeof(char *));
	if (!game->map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		game->map[i++] = ft_substr(line, 0, game->cols);
		j = 0;
		while (game->map[i - 1][j])
			game->coins += (game->map[i - 1][j++] == 'C');
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map[i] = NULL;
	if (!map_valid(game->map, game->rows, game->cols))
		return (NULL);
	return (game->map);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	if (arr)
		free(arr);
}

static t_deets	sepfunc(t_map game, char **hmap, int x, int y)
{
	t_deets	ret;
	t_deets	tmp;

	ret.discs = 0;
	ret.ends = 0;
	if (x < 0 || y < 0 || x >= game.rows || y >= game.cols
		|| game.map[x][y] == '1' || game.map[x][y] == 'G' || hmap[x][y] == 'V'
		|| game.map[x][y] == 'Q' || game.map[x][y] == 'X')
		return (ret);
	ret.ends = (game.map[x][y] == 'E');
	if (game.map[x][y] == 'C')
		ret.discs++;
	hmap[x][y] = 'V';
	tmp = sepfunc(game, hmap, x + 1, y);
	ret.discs += tmp.discs;
	ret.ends += tmp.ends;
	tmp = sepfunc(game, hmap, x - 1, y);
	ret.discs += tmp.discs;
	ret.ends += tmp.ends;
	tmp = sepfunc(game, hmap, x, y + 1);
	ret.discs += tmp.discs;
	ret.ends += tmp.ends;
	tmp = sepfunc(game, hmap, x, y - 1);
	ret.discs += tmp.discs;
	return (ret.ends += tmp.ends, ret);
}

t_deets	is_playable(t_map game, int x, int y)
{
	int		i;
	char	**tmp;
	t_deets	ret;

	i = 0;
	ret = (t_deets){0, 0};
	tmp = malloc(sizeof(char *) * (game.rows + 1));
	if (!tmp)
		return ((t_deets){-1, -1});
	while (i < game.rows)
	{
		tmp[i] = ft_substr(game.map[i], 0, ft_strlen(game.map[i]));
		if (!tmp[i])
		{
			free_arr(tmp);
			return (ret);
		}
		i++;
	}
	tmp[i] = NULL;
	ret = sepfunc(game, tmp, x, y);
	free_arr(tmp);
	return (ret);
}
