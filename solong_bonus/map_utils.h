/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:27:00 by ehammoud          #+#    #+#             */
/*   Updated: 2024/01/29 14:43:26 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

# include <stdlib.h>
# include <fcntl.h>
# include "structs.h"
# include "get_next_line.h"
# include "extra_utils.h"

typedef struct details
{
	int	discs;
	int	ends;
}	t_deets;

char	**parse_map(int fd, t_map *game);
t_deets	is_playable(t_map game, int x, int y);
void	get_map_size(int fd, int *r, int *c, t_map *g);

#endif