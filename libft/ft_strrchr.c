/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:47:01 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:47:02 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s1, int c)
{
	char	*s2;

	s2 = (char *)s1;
	while (*s2)
		s2++;
	if (c == 0)
		return (s2);
	while (s2 != s1)
	{
		s2--;
		if (*s2 == c)
			return (s2);
	}
	return (s2 = 0);
}
