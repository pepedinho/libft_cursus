/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:57:04 by itahri            #+#    #+#             */
/*   Updated: 2024/03/23 19:09:19 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	is_negative;

	i = 0;
	result = 0;
	is_negative = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		is_negative = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	if (is_negative % 2 != 0)
		result = -result;
	return (result);
}


#include <stdio.h>
#include <stdlib.h>
int main()
{
	char nbr_test_atoi[] = "999999999999999999999999999999999999999999999999999";

	printf("reel : %d\n", atoi(nbr_test_atoi));
	printf("me : %d\n", ft_atoi(nbr_test_atoi));
}