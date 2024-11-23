/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 21:34:49 by ehammoud          #+#    #+#             */
/*   Updated: 2024/04/24 21:38:44 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREEING_H
# define FREEING_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "structs.h"

int	free_up(t_map *game, int msg, int ex);

#endif