/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:13:19 by ehammoud          #+#    #+#             */
/*   Updated: 2024/04/25 13:46:05 by ehammoud         ###   ########.fr       */
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
	if (g->map[g->px][g->py] == 'X')
		free_up(g, 6, 0);
	if (g->map[g->px][g->py] == 'E' && !g->coins)
		free_up(g, 0, 0);
	g->on_end = (g->on_end || g->map[g->px][g->py] == 'E');
	if (g->map[g->px][g->py] == 'C')
		g->coins--;
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

int	animations(t_map *game)
{
	game->frame = (game->frame + 1) % (36 * game->speed);
	render_map(*game);
	return (0);
}

int	expose_hook(t_map *game)
{
	render_map(*game);
	return (0);
}
