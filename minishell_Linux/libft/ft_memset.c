/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:18:00 by snino             #+#    #+#             */
/*   Updated: 2022/08/10 16:42:54 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*simv;

	if (!s || !n)
		return (NULL);
	simv = (char *) s;
	while (n > 0)
	{
		*simv++ = (char) c;
		n--;
	}
	return (s);
}
