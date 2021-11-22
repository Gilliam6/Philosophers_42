/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:43:52 by rstephan          #+#    #+#             */
/*   Updated: 2021/11/20 15:43:53 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*src_m;
	unsigned char		*dst_m;
	unsigned char		*last_dst;
	const unsigned char	*last_src;

	dst_m = dst;
	src_m = src;
	last_dst = dst_m + len - 1;
	last_src = src_m + len - 1;
	if (dst_m == 0 && src_m == 0)
		return (dst);
	if (dst_m < src_m)
		while (len--)
			*dst_m++ = *src_m++;
	else
		while (len--)
			*last_dst-- = *last_src--;
	return (dst);
}
