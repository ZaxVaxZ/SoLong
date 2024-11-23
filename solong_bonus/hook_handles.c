/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:13:19 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/11 16:56:35 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_handles.h"

static int	move(t_map *g, int xm, int ym)
{
	if (g->px + xm > g->rows || g->px + xm < 0 || g->py + ym > g->cols
		|| g->py + ym < 0 || g->map[g->px + xm][g->py + ym] == '1')
		return (0);
	g->px += xm;
	g->py += ym;
	g->mvs++;
	write(1, "Moves: ", 7);
	ft_putnbr(g->mvs);
	write(1, "\n", 1);
	if (g->map[g->px][g->py] == 'X' || g->map[g->px][g->py] == 'Q'
		|| g->map[g->px][g->py] == 'G')
		free_up(g, 6, 0);
	if (g->map[g->px][g->py] == 'E' && !g->coins)
		free_up(g, 0, 0);
	g->on_end = (g->on_end || g->map[g->px][g->py] == 'E');
	g->coins -= (g->map[g->px][g->py] == 'C');
	g->map[g->px - xm][g->py - ym] = '0';
	if (g->on_end && g->map[g->px][g->py] != 'E')
	{
		g->map[g->px - xm][g->py - ym] = 'E';
		g->on_end = 0;
	}
	g->map[g->px][g->py] = 'P';
	render_map(*g);
	return (0);
}

int	handle_keys(int keycode, t_map *g)
{
	int	xm;
	int	ym;

	xm = 0;
	ym = 0;
	if (keycode == 53)
		free_up(g, 0, 0);
	else if (keycode == 13 || keycode == 126)
		xm = -1;
	else if (keycode == 0 || keycode == 123)
		ym = -1;
	else if (keycode == 1 || keycode == 125)
		xm = 1;
	else if (keycode == 2 || keycode == 124)
		ym = 1;
	else
		return (0);
	return (move(g, xm, ym));
}

int	move_enemies(t_map *game, int i, int j, int e)
{
	int	off;

	if (game->map[i][j] == 'Q' || game->map[i][j] == 'G')
	{
		if (game->map[i][j + game->enemy_dir[e]] != '0'
			&& game->map[i][j + game->enemy_dir[e]] != 'C'
			&& game->map[i][j + game->enemy_dir[e]] != 'P')
			game->enemy_dir[e] = 1 - 2 * (game->enemy_dir[e] > 0);
		off = game->enemy_dir[e];
		if (game->map[i][j + off] == '0')
			game->map[i][j + off] = 'Q';
		else if (game->map[i][j + off] == 'C')
			game->map[i][j + off] = 'G';
		else if (game->map[i][j + off] == 'P')
			free_up(game, 6, 0);
		else
			return (1);
		if (game->map[i][j] == 'G')
			game->map[i][j] = 'C';
		else
			game->map[i][j] = '0';
		return (1 + (off > 0));
	}
	return (1);
}

int	animations(t_map *game)
{
	int		i;
	int		j;
	int		e;

	e = 0;
	i = 0;
	game->frame = (game->frame + 1) % (36 * game->speed);
	while (game->frame % (9 * game->speed) == 0 && i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			if (game->map[i][j] == 'Q' || game->map[i][j] == 'G')
				e++;
			j += move_enemies(game, i, j, e - 1);
		}
		i++;
	}
	render_map(*game);
	return (0);
}

int	expose_hook(t_map *game)
{
	render_map(*game);
	return (0);
}
