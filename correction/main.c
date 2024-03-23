#include <stdio.h>
#include <bsd/string.h>

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
}
