/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-22 22:08:30 by itahri            #+#    #+#             */
/*   Updated: 2024-03-22 22:08:30 by itahri           ###   ########fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int main()
{
  char  dest1[14];
  char  dest2[14];
  int	r1;
  int	r1;

  printf("ft output : %lu\n", ft_strlcpy(dest1, "lorem ipsum dolor sit amet", 0));
  printf("ft dest : %s\n\n", dest1);
  printf("original : %lu\n", strlcpy(dest2,"lorem ipsum dolor sit amet", 0));
  printf("original dest : %s\n", dest2);
  
}
*/
