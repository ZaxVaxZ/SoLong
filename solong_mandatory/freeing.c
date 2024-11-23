/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:34:33 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/11 17:13:15 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "freeing.h"

static void	free_tex_2(t_map g)
{
	int	i;

	if (g.tex.s.cshad)
		mlx_destroy_image(g.mlx, g.tex.s.cshad);
	if (g.tex.s.lshad)
		mlx_destroy_image(g.mlx, g.tex.s.lshad);
	if (g.tex.s.dlshad)
		mlx_destroy_image(g.mlx, g.tex.s.dlshad);
	if (g.tex.s.dshad)
		mlx_destroy_image(g.mlx, g.tex.s.dshad);
	if (g.tex.w.back)
		mlx_destroy_image(g.mlx, g.tex.w.back);
	if (g.tex.w.gend)
		mlx_destroy_image(g.mlx, g.tex.w.gend);
	if (g.tex.w.bend)
		mlx_destroy_image(g.mlx, g.tex.w.bend);
	if (g.tex.w.plat)
		mlx_destroy_image(g.mlx, g.tex.w.plat);
	i = -1;
	while (++i < 18)
	{
		if (g.tex.w.cd[i])
			mlx_destroy_image(g.mlx, g.tex.w.cd[i++]);
	}
}

static void	free_textures(t_map g)
{
	if (g.tex.e.leftside)
		mlx_destroy_image(g.mlx, g.tex.e.leftside);
	if (g.tex.e.upside)
		mlx_destroy_image(g.mlx, g.tex.e.upside);
	if (g.tex.e.rightside)
		mlx_destroy_image(g.mlx, g.tex.e.rightside);
	if (g.tex.e.downside)
		mlx_destroy_image(g.mlx, g.tex.e.downside);
	if (g.tex.e.blside)
		mlx_destroy_image(g.mlx, g.tex.e.blside);
	if (g.tex.e.brside)
		mlx_destroy_image(g.mlx, g.tex.e.brside);
	if (g.tex.e.tlside)
		mlx_destroy_image(g.mlx, g.tex.e.tlside);
	if (g.tex.e.trside)
		mlx_destroy_image(g.mlx, g.tex.e.trside);
	if (g.tex.p.pleft)
		mlx_destroy_image(g.mlx, g.tex.p.pleft);
	if (g.tex.p.pright)
		mlx_destroy_image(g.mlx, g.tex.p.pright);
	if (g.tex.p.enemy)
		mlx_destroy_image(g.mlx, g.tex.p.enemy);
	free_tex_2(g);
}

static void	msg_prnt(int msg)
{
	if (msg == 0)
		write(1, "\n\n\n\n\n\n\n\n\nThanks for playing!\n", 30);
	if (msg == 1)
		write(2, "Error\nFailed to create mlx pointer.\n", 36);
	if (msg == 2)
		write(2, "Error\nFailed to create mlx window.\n", 35);
	if (msg == 3)
		write(2, "Error\nFailed to malloc for the map.\n", 36);
	if (msg == 4)
		write(2, "Error\nFailed to reach the ending.\n", 34);
	if (msg == 5)
		write(2, "Error\nFailed to collect all coins.\n", 35);
	if (msg == 6)
		write(1, "\n\n\n\n\n\n\n\n\nYou lose! Good day, sir!\n", 34);
	if (msg == 7)
		write(2, "Error\nFailed to malloc helper array.\n", 37);
	if (msg == 8)
		write(2, "Error\nTexture file missing or corrupted.\n", 41);
	if (msg == 9)
		write(2, "Error\nMap invalid due to characters.\n", 37);
	if (msg == 10)
		write(2, "Error\nMap is too big!\n", 22);
}

int	free_up(t_map *game, int msg, int ex)
{
	int		i;

	free_textures(*game);
	if (game->mlx && game->mw)
		mlx_destroy_window(game->mlx, game->mw);
	if (game->mlx)
		free(game->mlx);
	i = 0;
	while (game->map && game->map[i])
		free(game->map[i++]);
	if (game->map)
		free(game->map);
	msg_prnt(msg);
	exit (ex);
}
