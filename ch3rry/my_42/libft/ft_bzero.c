/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caellis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:59:39 by caellis           #+#    #+#             */
/*   Updated: 2019/04/09 13:03:50 by caellis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*buff;

	if (n == 0 || s == NULL)
		return ;
	buff = (unsigned char *)s;
	while (n--)
		*(buff++) = (unsigned char)0;
}
