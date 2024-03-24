#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>



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


int main(void)
{

	//memmove
	char str[15] = "test";
	char dst[15] = "salut salut";

	printf("%s\n", dst);
	printf("---------------------\n");
	ft_memmove(dst, str, 4);
	printf("%s\n", dst);

	//memset	
	char str[] = "oui je test";
    printf("%p\n", ft_memset(str, 'A', 10));

	//strlcpy
	char src[10] = "salut";
	char dest[10] = "oui";
	char src2[10] = "salut";
	char dest2[10] = "oui";

	printf("vrai fonction : \n\n");
	printf("%s\n", dest);
	printf("%ld\n", ft_strlcpy(dest, src, 14));
	printf("%s\n", dest);

	printf("--------------------\n");
	printf("ma fonction : \n\n");

	printf("%s\n", dest2);
	printf("%ld\n", ft_strlcpy(dest2, src2, 14));
	printf("%s\n", dest2);

	//strlcat
	char source[10] = "salut";
	char destination[10] = "oui";
	char source2[10] = "salut";
	char destination2[10] = "oui";

	printf("vrai fonction : \n\n");
	printf("%s\n", destination);
	printf("%ld\n", strlcat(destination, source, 1100));
	printf("%s\n", destination);

	printf("--------------------\n");
	printf("ma fonction : \n\n");

	printf("%s\n", destination2);
	printf("%ld\n", ft_strlcat(destination2, source2, 1100));
	printf("%s\n", destination2);

	//strchr
	const char test_strchr[] = "salut la compagnie";
		//strchr
	printf("me : %s\n", ft_strchr(test_strchr, 'c'));
	printf("reel : %s\n", strchr(test_strchr, 'c'));
		//strrchr
	printf("me : %s\n", ft_strrchr(test_strchr, 'a'));
	printf("reel : %s\n", strrchr(test_strchr, 'a'));

	//strncpm
	char test_strcmp[] = "Bon";
	char test_strcmp2[] = "Bo";

	printf("moi : %d\n", ft_strncmp(test_strcmp, test_strcmp2, 3));
	printf("reel : %d\n", strncmp(test_strcmp, test_strcmp2, 3));

	//memchr
	char	test_ft_memset[] = "salut";
	int		car = 'a';

	printf("%s\n", ft_memchr(test_ft_memset, car, 4));
	printf("%s\n", memchr(test_ft_memset, car, 4));

	//memcmp
	char s1_test_memcmp[] = "Bonjour";
    char s2_test_memcmp[] = "Bonsoir";

    printf("me : %d\n", ft_memcmp(s1_test_memcmp, s2_test_memcmp, 3));
    printf("reel : %d\n", memcmp(s1_test_memcmp, s2_test_memcmp, 3));

	//atoi
	char nbr_test_atoi[] = "-2147483648";

	printf("reel : %d\n", atoi(nbr_test_atoi));
	printf("me : %d\n", ft_atoi(nbr_test_atoi));

	//calloc
	char *result;
    int i = 0;

    result = calloc(10, 0);
    if (result == NULL)
    {
        printf("NULL\n");
        free(result);
    }
    else
        while (i < 10)
        {
            if (result[i] == '\0')
                printf("c'est bon %d\n", i);
            i++;
        }
    i = 0;
    result = ft_calloc(10, 0);
    if (result == NULL)
    {
        printf("NULL\n");
        free(result);
    }
    else
        while (i < 10)
        {
            if (result[i] == '\0')
                printf("c'est bon %d\n", i);
            i++;
        }

	//strdup
	char	test_strdup[] = "ceci est un test";
	char 	*ptr;

	ptr = strdup(test_strdup);
	printf("reel : %s\n", ptr, ft_strlen(ptr));
	ptr = ft_strdup(test_strdup);
	printf("me : %s\n", ptr, ft_strlen(ptr));
	
	//ft_substr
	char	str[] = "ceci est un test";
	char	*result;

	result = ft_substr(str, 12, 3);
	printf("%s\n", result);

	//strstr
	const char *haystack1 = "hello world";
    const char *needle1 = "world";
    const char *haystack2 = "hello world";
    const char *needle2 = "goodbye";
    const char *haystack3 = "hello world";
    const char *needle3 = "";
    const char *haystack4 = "";
    const char *needle4 = "hello";

    printf("Test 1:\n");
    printf("ft_strstr: %s\n", ft_strstr(haystack1, needle1));
    printf("strstr: %s\n", strstr(haystack1, needle1));

    printf("Test 2:\n");
    printf("ft_strstr: %s\n", ft_strstr(haystack2, needle2));
    printf("strstr: %s\n", strstr(haystack2, needle2));

    printf("Test 3:\n");
    printf("ft_strstr: %s\n", ft_strstr(haystack3, needle3));
    printf("strstr: %s\n", strstr(haystack3, needle3));

    printf("Test 4:\n");
    printf("ft_strstr: %s\n", ft_strstr(haystack4, needle4));
    printf("strstr: %s\n", strstr(haystack4, needle4));

	//ft_strjoin
	char	test_str_join[] = "ceci est ";
	char	test_str_join2[] = "un test";

	//ft_strtrim
	char	set[] = "asult";
	char	str[] = "salut la compagnie salfut";

	printf("%s\n", ft_strtrim(str, set));

	printf("%s\n", ft_strjoin(test_str_join, test_str_join2));

	//ft_split
	char	str_test_for_split[] = "          ceci       est        un      test      ";
	char	**test_result_split;
	int		index_split;
	int		count_split;

	printf("%s\n", str_test_for_split);
	test_result_split = ft_split(str_test_for_split, ' ');
	index_split = 0;
	count_split = ft_count_words(str_test_for_split, ' ');

	printf("nombre de mots : %d\n", count_split);
	while (index_split < count_split)
	{
		printf("%s\n", test_result_split[index_split]);
		index_split++;
	}

	//ft_itoa 
	printf("%s\n", ft_itoa(-2147483648));
}
