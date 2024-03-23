/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:32:14 by itahri            #+#    #+#             */
/*   Updated: 2024/03/23 18:16:27 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	size_t	temp_i;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			temp_i = i;
			while (haystack[temp_i] == needle[j] && needle[j])
			{
				temp_i++;
				j++;
			}
			if (temp_i == ft_strlen(needle))
				return (&haystack[i]);
		}
	}
	return (NULL);
}
