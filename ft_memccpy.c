/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivaniuk <nivaniuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 14:46:11 by nivaniuk          #+#    #+#             */
/*   Updated: 2021/02/14 11:05:49 by nivaniuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memccpy(void *dst, const void *src, int c, int n)
{
	unsigned char	*r;
	unsigned char	*s;

	s = (unsigned char*)src;
	r = (unsigned char*)dst;
	while (n--)
	{
		*r = *s;
		if (*r == (unsigned char)c)
			return (r + 1);
		r++;
		s++;
	}
	return (0);
}
