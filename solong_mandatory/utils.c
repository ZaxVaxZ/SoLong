/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:59:52 by ehammoud          #+#    #+#             */
/*   Updated: 2024/06/04 11:27:23 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra_utils.h"

void	ft_putnbr(int x)
{
	char	c;

	if (x > 9)
		ft_putnbr(x / 10);
	c = (x % 10) + '0';
	write(1, &c, 1);
}

static int	valid_borders(char **m, int r, int c)
{
	int	i;

	i = -1;
	while (++i < c)
	{
		if (m[0][i] != '1' || m[r - 1][i] != '1')
			return (0);
	}
	i = -1;
	while (++i < r)
	{
		if (m[i][0] != '1' || m[i][c - 1] != '1')
			return (0);
	}
	return (1);
}

static int	handle_row(char *m, int *e, int *p, int *cc)
{
	int	j;

	if (!m || !*m)
		return (0);
	j = -1;
	while (m[++j])
	{
		*e += (m[j] == 'E');
		*p += (m[j] == 'P');
		*cc += (m[j] == 'C');
		if (m[j] != '0' && m[j] != '1' && m[j] != 'P'
			&& m[j] != 'C' && m[j] != 'E')
			return (0);
	}
	return (1);
}

int	map_valid(char **m, int r, int c)
{
	int	i;
	int	e;
	int	p;
	int	cc;

	i = -1;
	e = 0;
	p = 0;
	cc = 0;
	while (++i < r)
	{
		if (!handle_row(m[i], &e, &p, &cc))
			return (0);
	}
	return (e == 1 && p == 1 && cc >= 1 && valid_borders(m, r, c));
}

void	*get_tex(void *mlx, char *name)
{
	int	x;
	int	y;

	return (mlx_xpm_file_to_image(mlx, name, &x, &y));
}
