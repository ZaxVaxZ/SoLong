/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:31:17 by ehammoud          #+#    #+#             */
/*   Updated: 2024/03/06 17:06:33 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct map_edges
{
	void	*upside;
	void	*trside;
	void	*tlside;
	void	*brside;
	void	*blside;
	void	*leftside;
	void	*downside;
	void	*rightside;
}	t_edges;

typedef struct map_shadows
{
	void	*cshad;
	void	*dshad;
	void	*lshad;
	void	*dlshad;
}	t_shadows;

typedef struct player
{
	void	*pleft;
	void	*pright;
	void	*enemy;
}	t_player;

typedef struct world
{
	void	*cd[18];
	void	*bend;
	void	*gend;
	void	*plat;
	void	*back;
}	t_world;

typedef struct textures
{
	t_world		w;
	t_player	p;
	t_edges		e;
	t_shadows	s;
}	t_tex;

typedef struct map
{
	int		px;
	int		py;
	int		mvs;
	int		rows;
	int		cols;
	int		ymod;
	int		frame;
	int		coins;
	int		speed;
	int		on_end;
	char	**map;
	void	*mlx;
	void	*mw;
	t_tex	tex;
}	t_map;

#endif