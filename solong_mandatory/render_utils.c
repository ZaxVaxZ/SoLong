/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:00:45 by ehammoud          #+#    #+#             */
/*   Updated: 2024/04/24 21:30:31 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_utils.h"

void	get_textures(t_map *g)
{
	g->on_end = 0;
	g->tex.e.upside = get_tex(g->mlx, "./tex/UpTile.xpm");
	g->tex.e.leftside = get_tex(g->mlx, "./tex/RightTile.xpm");
	g->tex.e.rightside = get_tex(g->mlx, "./tex/LeftTile.xpm");
	g->tex.e.downside = get_tex(g->mlx, "./tex/DownTile.xpm");
	g->tex.e.trside = get_tex(g->mlx, "./tex/TRTile.xpm");
	g->tex.e.tlside = get_tex(g->mlx, "./tex/TLTile.xpm");
	g->tex.e.brside = get_tex(g->mlx, "./tex/BRTile.xpm");
	g->tex.e.blside = get_tex(g->mlx, "./tex/BLTile.xpm");
	g->tex.p.pleft = get_tex(g->mlx, "./tex/PLeft0.xpm");
	g->tex.p.pright = get_tex(g->mlx, "./tex/PRight0.xpm");
	g->tex.p.enemy = get_tex(g->mlx, "./tex/Enemy.xpm");
	g->tex.w.back = get_tex(g->mlx, "./tex/BackTile.xpm");
	g->tex.w.plat = get_tex(g->mlx, "./tex/PlatformTile.xpm");
	g->tex.w.bend = get_tex(g->mlx, "./tex/BadEnding.xpm");
	g->tex.w.gend = get_tex(g->mlx, "./tex/HappyEnding.xpm");
	g->tex.s.dshad = get_tex(g->mlx, "./tex/DownShadow.xpm");
	g->tex.s.lshad = get_tex(g->mlx, "./tex/LeftShadow.xpm");
	g->tex.s.dlshad = get_tex(g->mlx, "./tex/DLShadow.xpm");
	g->tex.s.cshad = get_tex(g->mlx, "./tex/CornerShadow.xpm");
	get_cd_tex(g);
	check_textures(g, g->tex);
}

static void	draw_edge(t_map g, t_tex t, int x, int y)
{
	if (!x)
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.e.upside, y * 64, x * 64);
		if (!y)
			mlx_put_image_to_window(g.mlx, g.mw, t.e.tlside, y * 64, x * 64);
		if (y == g.cols - 1)
			mlx_put_image_to_window(g.mlx, g.mw, t.e.trside, y * 64, x * 64);
	}
	else if (!y)
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.e.rightside, y * 64, x * 64);
		if (x == g.rows - 1)
			mlx_put_image_to_window(g.mlx, g.mw, t.e.blside, y * 64, x * 64);
	}
	else if (y == g.cols - 1)
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.e.leftside, y * 64, x * 64);
		if (x == g.rows - 1)
			mlx_put_image_to_window(g.mlx, g.mw, t.e.brside, y * 64, x * 64);
	}
	else if (x == g.rows - 1)
		mlx_put_image_to_window(g.mlx, g.mw, t.e.downside, y * 64, x * 64);
}

static void	draw_shadow(t_map g, t_tex t, int i, int j)
{
	int	val;

	if (i && j < g.cols - 1 && g.map[i - 1][j + 1] == '1'
		&& g.map[i - 1][j] != '1' && g.map[i][j + 1] != '1')
		val = 4;
	else
		val = (i && g.map[i - 1][j] == '1') + 2
			* (j < g.cols - 1 && g.map[i][j + 1] == '1');
	if (val == 0)
		mlx_put_image_to_window(g.mlx, g.mw, t.w.back, j * 64, i * 64);
	if (val == 1)
		mlx_put_image_to_window(g.mlx, g.mw, t.s.dshad, j * 64, i * 64);
	if (val == 2)
		mlx_put_image_to_window(g.mlx, g.mw, t.s.lshad, j * 64, i * 64);
	if (val == 3)
		mlx_put_image_to_window(g.mlx, g.mw, t.s.cshad, j * 64, i * 64);
	if (val == 4)
		mlx_put_image_to_window(g.mlx, g.mw, t.s.dlshad, j * 64, i * 64);
}

static void	draw(t_map g, t_tex t, int i, int j)
{
	draw_shadow(g, t, i, j);
	if (g.map[i][j] == '1')
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.w.plat, j * 64, i * 64);
		draw_edge(g, t, i, j);
	}
	if (g.map[i][j] == 'E' || (g.map[i][j] == 'P' && g.on_end))
	{
		mlx_put_image_to_window(g.mlx, g.mw, t.w.bend, j * 64, i * 64);
		if (!g.coins)
			mlx_put_image_to_window(g.mlx, g.mw, t.w.gend, j * 64, i * 64);
	}
	if (g.map[i][j] == 'P')
		mlx_put_image_to_window(g.mlx, g.mw, t.p.pleft, j * 64, i * 64);
	if (g.map[i][j] == 'X')
		mlx_put_image_to_window(g.mlx, g.mw, t.p.enemy, j * 64, i * 64);
	if (g.map[i][j] == 'C' && g.frame < 18 * g.speed)
		mlx_put_image_to_window(g.mlx, g.mw, \
			t.w.cd[g.frame / g.speed], j * 64, i * 64);
	else if (g.map[i][j] == 'C')
		mlx_put_image_to_window(g.mlx, g.mw, \
			t.w.cd[35 - (g.frame / g.speed)], j * 64, i * 64);
}

void	render_map(t_map g)
{
	int		i;
	int		j;
	char	*cn;

	i = -1;
	while (g.map[++i])
	{
		j = -1;
		while (g.map[i][++j])
			draw(g, g.tex, i, j);
	}
	mlx_string_put(g.mlx, g.mw, 20, 23, 0xff00, "Discs: ");
	cn = ft_itoa(g.coins);
	mlx_string_put(g.mlx, g.mw, 75, 23, 0xff00, cn);
	free(cn);
	mlx_string_put(g.mlx, g.mw, 20, 42, 0xff00, "Moves: ");
	cn = ft_itoa(g.mvs);
	mlx_string_put(g.mlx, g.mw, 75, 42, 0xff00, cn);
	free(cn);
}
