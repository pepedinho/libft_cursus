/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-23 02:26:00 by itahri            #+#    #+#             */
/*   Updated: 2024-03-23 02:26:00 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char*s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1 && s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

#include <string.h>
#include <stdio.h>
int main()
{
	char test_strcmp[] = "Bon";
	char test_strcmp2[] = "Bo";

	printf("moi : %d\n", ft_strncmp(test_strcmp, test_strcmp2, 3));
	printf("reel : %d\n", strncmp(test_strcmp, test_strcmp2, 3));
}