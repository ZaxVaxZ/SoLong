/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:11:06 by ehammoud          #+#    #+#             */
/*   Updated: 2024/04/24 21:37:50 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTRA_UTILS_H
# define EXTRA_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"

size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
void	ft_putnbr(int x);
int		map_valid(char **m, int r, int c);
void	*get_tex(void *mlx, char *name);

#endif