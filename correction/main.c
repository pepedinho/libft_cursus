#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

#include "../libft.h"


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

char test_ft_mappi(unsigned int index, char c) {
	(void)index;
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A'; 
    }
    return c;
}

void	print_test_ietri(unsigned int i, char *s)
{
	(void)i;
	printf("%c", *s);
}

char test_to_upper(unsigned int index, char c)
{
	(void)index;

	if (c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}


int main(void)
{
	printf("\n--------------------\nMEMMOVE: \n");
	//memmove
	char str_test_memmove[15] = "test";
	char dst_test_memmove[15] = "salut salut";

	printf("%s\n", dst_test_memmove);
	printf("-_-_-_-_-_-_-_-_-_-_-_-_-\n");
	ft_memmove(dst_test_memmove, str_test_memmove, 4);
	printf("%s\n", dst_test_memmove);


	printf("\n--------------------\nMEMSET: \n");
	//memset	
	char str_test_memset[] = "oui je test";
    printf("%p\n", ft_memset(str_test_memset, 'A', 10));

	printf("\n--------------------\nSTRLCPY : \n");
	//strlcpy
	char src_strlcpy[10] = "salut";
	char dest_strlcpy[10] = "oui";
	char src2_strlcpy[10] = "salut";
	char dest2_strlcpy[10] = "oui";

	printf("vrai fonction : \n\n");
	printf("%s\n", dest_strlcpy);
	printf("%ld\n", ft_strlcpy(dest_strlcpy, src_strlcpy, 14));
	printf("%s\n", dest_strlcpy);

	printf("--------------------\n");
	printf("ma fonction : \n\n");

	printf("%s\n", dest2_strlcpy);
	printf("%ld\n", ft_strlcpy(dest2_strlcpy, src2_strlcpy, 14));
	printf("%s\n", dest2_strlcpy);

	printf("\n--------------------\nSTRLCAT: \n");
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

	printf("\n--------------------\nSTRCHR: \n");
	//strchr
	const char test_strchr[] = "salut la compagnie";
		//strchr
	printf("me : %s\n", ft_strchr(test_strchr, 'c'));
	printf("reel : %s\n", strchr(test_strchr, 'c'));
		//strrchr
	printf("me : %s\n", ft_strrchr(test_strchr, 'a'));
	printf("reel : %s\n", strrchr(test_strchr, 'a'));

	printf("\n--------------------\nSTRNCMP: \n");
	//strncpm
	char test_strcmp[] = "Bon";
	char test_strcmp2[] = "Bo";


	printf("moi : %d\n", ft_strncmp(test_strcmp, test_strcmp2, 3));
	printf("reel : %d\n", strncmp(test_strcmp, test_strcmp2, 3));

	printf("\n--------------------\nMEMCHR: \n");
	//memchr
	char	test_ft_memset[] = "salut";
	int		car = 'a';

	printf("%s\n", (char *)ft_memchr(test_ft_memset, car, 4));
	printf("%s\n", (char *)memchr(test_ft_memset, car, 4));

	printf("\n--------------------\nMEMCMP: \n");
	//memcmp
	char s1_test_memcmp[] = "Bonjour";
    char s2_test_memcmp[] = "Bonsoir";

    printf("me : %d\n", ft_memcmp(s1_test_memcmp, s2_test_memcmp, 3));
    printf("reel : %d\n", memcmp(s1_test_memcmp, s2_test_memcmp, 3));

	printf("\n--------------------\nATOI: \n");
	//atoi
	char nbr_test_atoi[] = "-2147483648";

	printf("reel : %d\n", atoi(nbr_test_atoi));
	printf("me : %d\n", ft_atoi(nbr_test_atoi));

	printf("\n--------------------\nCALLOC: \n");
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
	{
        while (i < 10)
        {
            if (result[i] == '\0')
                printf("c'est bon %d\n", i);
            i++;
        }
	}

	printf("\n--------------------\nSTRDUP: \n");
	//strdup
	char	test_strdup[] = "ceci est un test";
	char 	*ptr;

	ptr = strdup(test_strdup);
	printf("reel : %s, size(%ld)\n", ptr, ft_strlen(ptr));
	ptr = ft_strdup(test_strdup);
	printf("me : %s, size(%ld)\n", ptr, ft_strlen(ptr));
	
	printf("\n--------------------\nSUBSTR: \n");
	//ft_substr
	char	str_substr[] = "ceci est un test";
	char	*result_substr;

	result_substr = ft_substr(str_substr, 12, 3);
	printf("%s\n", result_substr);

	printf("\n--------------------\nSTRSTR: \n");
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

	printf("\n--------------------\nSTRJOIN: \n");
	//ft_strjoin
	char	test_str_join[] = "ceci est ";
	char	test_str_join2[] = "un test";

	printf("\n--------------------\nSTRTRIM: \n");
	//ft_strtrim
	char	set[] = "asult";
	char	str[] = "salut la compagnie salfut";

	printf("%s\n", ft_strtrim(str, set));

	printf("%s\n", ft_strjoin(test_str_join, test_str_join2));

	printf("\n--------------------\nSPLIT: \n");
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

	printf("\n--------------------\nITOA: \n");
	//ft_itoa 
	printf("%s\n", ft_itoa(-2147483648));

	printf("\n--------------------\nSTRMAPI: \n");
	//ft_strmapi
	char str_test_mapi[] = "ceci est un test";
	printf("avant : %s\n", str_test_mapi);
	printf("apres : %s\n", ft_strmapi(str_test_mapi, &test_to_upper));

	printf("\n--------------------\nSTRITERI: \n");
	//ft_striteri
	char str_test_striteri[] = "ceci est un test";

	ft_striteri(str_test_striteri, &print_test_ietri);

	printf("\n--------------------\nPUTNBR_NB: \n");
	//ft_putnbr_fd
	//printf("putnbr_fd : ");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");

	//BONUS
	   int *integer_content = malloc(sizeof(int));
    *integer_content = 42;
    t_list *new_node_int = ft_lstnew(integer_content);
    

    char *string_content = "Hello, world!";
    t_list *new_node_str = ft_lstnew(string_content);
    
    if (new_node_int) {
        printf("Nouveau noeud avec contenu entier : %d\n", *(int*)new_node_int->content);
    } else {
        printf("Erreur lors de la création du nouveau noeud avec contenu entier.\n");
    }
    
    if (new_node_str) {
        printf("Nouveau noeud avec contenu chaîne de caractères : %s\n", (char*)new_node_str->content);
    } else {
        printf("Erreur lors de la création du nouveau noeud avec contenu chaîne de caractères.\n");
    }
    
    free(integer_content);
    free(new_node_int);
    free(new_node_str);
    
}
