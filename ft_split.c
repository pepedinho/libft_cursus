/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-24 00:19:32 by itahri            #+#    #+#             */
/*   Updated: 2024-03-24 00:19:32 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_words(char const *str, char sep)
{
	int		count;
	int		bol;
	size_t	i;

	bol = 1;
	i = 0;
	count = 0;
	while (str[i] == sep)
		i++;
	while (str[i])
	{
		if (str[i] == sep)
			bol = 1;
		else if (str[i] != sep && bol == 1)
		{
			count++;
			bol = 0;
		}
		i++;
	}
	return (count);
}

static size_t	size_of_word(char const *word, char sep)
{
	size_t	len;

	len = 0;
	while (word[len] && word[len] != sep)
		len++;
	return (len);
}

static char	*fill_line(char const *word, char c, size_t len)
{
	size_t	i;
	char	*result;

	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size_of_word(word, c))
	{
		result[i] = word[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char  **empty_return(void)
{
	char  **str;

	str = malloc(sizeof(char *) * 1);
	str[0] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		count;
	int		bol;
	char	**result;
	int		count_words;

	if (s[0] == '\0' || !s)
		return (empty_return());
	bol = 1;
	count = 0;
	count_words = ft_count_words(s, c);
	result = malloc(sizeof(char *) * (count_words + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			bol = 1;
		if (s[i] != c && bol == 1)
		{
			bol = 0;
			result[count] = fill_line(&s[i], c, size_of_word(&s[i], c));
			count++;
		}
		i++;
	}
	result[count] = NULL;
	return (result);
}
/*
int main(void)
{
	char **tab;
	char invalid[] = "\0"; 

	tab = ft_split(invalid, 0);

	if (tab[0])
		printf("tab[0] : %s\n", tab[0]);
	//printf("tab[1] : %s\n", tab[1]);
	//if (tab[2] == NULL)
	//	printf("OK\n");
	//printf("tab[2] : %s\n", tab[2]);
	//printf("nb words : %d\n", ft_count_words("  tripouille  42  ", ' '));
	//for (int i = 0;i < 3; i++) {
	//	free(tab[i]);
	//}
	//free(tab);
}
*/
