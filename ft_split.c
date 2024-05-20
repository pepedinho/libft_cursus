/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 00:19:32 by itahri            #+#    #+#             */
/*   Updated: 2024/05/20 23:27:33 by itahri           ###   ########.fr       */
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

static size_t	word_len(char const *word, char sep, int *bol, int *count)
{
	size_t	len;

	len = 0;
	while (word[len] && word[len] != sep)
		len++;
	if (bol && count)
	{
		*bol = 0;
		*count = *count + 1;
	}
	return (len);
}

static char	*compose(char const *word, char c, size_t len)
{
	size_t	i;
	char	*result;

	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < word_len(word, c, NULL, NULL))
	{
		result[i] = word[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**empty_return(void)
{
	char	**str;

	str = malloc(sizeof(char *) * 1);
	str[0] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		cnt;
	int		bol;
	char	**result;

	if (s[0] == '\0' || !s)
		return (empty_return());
	bol = 1;
	cnt = 0;
	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			bol = 1;
		if (s[i] != c && bol == 1)
			result[cnt - 1] = compose(&s[i], c, word_len(&s[i], c, &bol, &cnt));
		i++;
	}
	result[cnt] = NULL;
	return (result);
}
/*
int main(void)
{
	char **tab;
	//char invalid[] = "\0"; 

	tab = ft_split(" tripouille xxx  ", ' ');

	if (tab[0])
		printf("tab[0] : %s\n", tab[0]);
	printf("tab[1] : %s\n", tab[1]);
	if (tab[2] == NULL)
		printf("OK\n");
	printf("tab[2] : %s\n", tab[2]);
	printf("nb words : %d\n", ft_count_words("  tripouille  42  ", ' '));
	for (int i = 0;i < 3; i++) {
		free(tab[i]);
	}
	free(tab);
}
*/
