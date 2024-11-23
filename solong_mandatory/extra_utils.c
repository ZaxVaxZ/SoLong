/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:10:59 by ehammoud          #+#    #+#             */
/*   Updated: 2024/04/18 18:22:13 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra_utils.h"

static char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;
	size_t	n;

	n = ft_strlen(s1);
	dst = malloc((n + 1) * sizeof(char));
	if (dst)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			dst[i] = s1[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;
	size_t	j;
	size_t	n;

	if (!s)
		return (NULL);
	if (!len)
		return (ft_strdup(""));
	n = ft_strlen(s);
	if (start >= n || len == 0 || s[0] == '\0')
		return (ft_strdup(""));
	if (start + len > n)
		j = n - start;
	else
		j = len;
	news = malloc((j + 1) * sizeof(char));
	if (!news)
		return (NULL);
	j = 0;
	i = start;
	while (s[i] != '\0' && j < len)
		news[j++] = s[i++];
	news[j] = '\0';
	return (news);
}

static void	ft_strrev(char *str)
{
	size_t	i;
	size_t	n;
	char	t;

	i = 0;
	n = ft_strlen(str);
	while (i < n / 2)
	{
		t = str[i];
		str[i] = str[n - 1 - i];
		str[n - 1 - i] = t;
		i++;
	}
}

char	*ft_itoa(int n)
{
	char	ret[20];
	int		i;
	int		neg;
	long	x;

	neg = 1 - 2 * (n < 0);
	x = (long) n * neg;
	i = 0;
	while (x / 10 != 0)
	{
		ret[i++] = x % 10 + 48;
		x /= 10;
	}
	ret[i++] = x % 10 + 48;
	if (neg == -1)
		ret[i++] = '-';
	ret[i] = '\0';
	ft_strrev(ret);
	return (ft_strdup(ret));
}
