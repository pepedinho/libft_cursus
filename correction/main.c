#include <stdio.h>
#include <bsd/string.h>
#include <stdlib.h>

#include "../libft.h"

static void	del(void *content)
{
	free(content);
}

void *change_capitalization(void *str) {
    char *s = (char *)str;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] -= 32; // Convertir en majuscule
        }
    }
    return ((void *)s);
}

// Fonction pour afficher les éléments de la liste
static void    print_list(t_list *lst) {
    while (lst) {
        printf("%s -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

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

void print_content(void *content) {
    printf("%s", (char *)content); // Supposons que le contenu soit une chaîne de caractères
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
	//ft_lstnew
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


	//ft_lstadd_front
			// Création de quelques éléments pour la liste chaînée
	t_list *elem1 = malloc(sizeof(t_list));
	t_list *elem2 = malloc(sizeof(t_list));
	t_list *elem3 = malloc(sizeof(t_list));

	if (!elem1 || !elem2 || !elem3)
	{
		perror("Erreur d'allocation mémoire");
		return (1);
	}

	// Initialisation du contenu des éléments
	elem1->content = "[1]->";
	elem1->next = NULL;

	elem2->content = "[2]->";
	elem2->next = NULL;

	elem3->content = "[3]->";
	elem3->next = NULL;

	// Création de la liste chaînée
	t_list *lst = NULL; // Initialisation de la liste chaînée

	// Ajout des éléments à la liste chaînée
	ft_lstadd_front(&lst, elem2); // Ajout de elem2 en tête
	ft_lstadd_front(&lst, elem1); // Ajout de elem1 en tête
	ft_lstadd_front(&lst, elem3); // Ajout de elem3 en tête

	// Affichage des éléments de la liste chaînée
	t_list *current = lst; // Pointeur pour parcourir la liste
	while (current)
	{
		printf("%s", (char *)current->content);
		current = current->next;
	}
	printf("\n");
	// Libération de la mémoire des éléments
	free(elem1);
	free(elem2);
	free(elem3);

	//FT_LSTSIZE
	// Création de quelques éléments de la liste
	t_list *elem1_testsize = malloc(sizeof(t_list));
	t_list *elem2_testsize = malloc(sizeof(t_list));
	t_list *elem3_testsize = malloc(sizeof(t_list));

	// Initialisation du contenu des éléments (pour cet exemple, on utilise des int)
	int content1_ts = 42;
	int content2_ts = 64;
	int content3_ts = 128;

	elem1_testsize->content = &content1_ts;
	elem1_testsize->next = elem2_testsize;
	elem2_testsize->content = &content2_ts;
	elem2_testsize->next = elem3_testsize;
	elem3_testsize->content = &content3_ts;
	elem3_testsize->next = NULL;
    
    t_list *test = ft_lstnew("youhou");
    ft_lstadd_front(&elem1_testsize, test);

	// Appel de la fonction ft_lstsize pour compter le nombre d'éléments
	int size = ft_lstsize(elem1_testsize);

	// Affichage du résultat
	printf("Taille de la liste : %d\n", size);

	// Libération de la mémoire (optionnel dans ce cas car nous utilisons des pointeurs alloués statiquement)
	free(elem1_testsize);
	free(elem2_testsize);
	free(elem3_testsize);

	//FT_LSTLAST
	// Création manuelle de la liste chaînée
    t_list *lst_testlast = NULL;

    // Création des éléments de la liste
    t_list *elem1_testlast = (t_list *)malloc(sizeof(t_list));
    t_list *elem2_testlast = (t_list *)malloc(sizeof(t_list));
    t_list *elem3_testlast = (t_list *)malloc(sizeof(t_list));

    // Initialisation des données
    elem1_testlast->content = "42";
    elem2_testlast->content = "21";
    elem3_testlast->content = "84";

    // Liaison des éléments pour former la liste chaînée
    elem1_testlast->next = NULL;
    elem2_testlast->next = elem1_testlast;
    elem3_testlast->next = elem2_testlast;

    // Assignation du premier élément à la liste
    lst_testlast = elem1_testlast;

    // Test de la fonction ft_lstlast
    t_list *last = ft_lstlast(lst_testlast);

    // Affichage du dernier élément de la liste
    if (last)
    {
        printf("Le dernier élément de la liste est : %s\n", (char *)last->content);
    }
    else
    {
        printf("La liste est vide.\n");
    }

    // Libération de la mémoire allouée pour les éléments
    free(elem1_testlast);
    free(elem2_testlast);
    free(elem3_testlast); 

	//FT_LSTDELONE
	// Création de la liste chaînée
	t_list *elem1 = malloc(sizeof(t_list));
	t_list *elem2 = malloc(sizeof(t_list));
	t_list *elem3 = malloc(sizeof(t_list));

	// Allocation de mémoire pour le contenu des éléments (exemple avec des entiers)
	int *content1 = malloc(sizeof(int));
	int *content2 = malloc(sizeof(int));
	int *content3 = malloc(sizeof(int));

	*content1 = 42;
	*content2 = 21;
	*content3 = 84;

	elem1->content = content1;
	elem1->next = elem2;

	elem2->content = content2;
	elem2->next = elem3;

	elem3->content = content3;
	elem3->next = NULL;

	// Affichage de la liste avant la suppression
	t_list *current = elem1;
	printf("Liste avant la suppression :\n");
	while (current)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");

	// Utilisation de ft_lstdelone pour supprimer elem2
	printf("\nSuppression de l'élément 2 :\n");
	ft_lstdelone(elem2, &del);

	// Affichage de la liste après la suppression
	current = elem1;
	printf("Liste après la suppression :\n");
	while (current->next)
	{
		printf("%d -> ", *(int *)current->content);
		current = current->next;
	}
	printf("NULL\n");

	// Libération de la mémoire
	free(content1);
	free(content3);
	free(elem1);
	free(elem3);

	//LSTCLEAR
	// Initialisation de la liste avec quelques éléments
    t_list *lst = NULL;
    t_list *new_node;

    // Ajout de quelques éléments à la liste
    for (int i = 0; i < 5; i++)
    {
        new_node = malloc(sizeof(t_list)); // Allocation d'un nouvel élément
        if (!new_node)
        {
            perror("Erreur d'allocation de mémoire");
            exit(EXIT_FAILURE);
        }

        new_node->content = malloc(sizeof(int)); // Allocation d'un espace pour un entier
        if (!new_node->content)
        {
            perror("Erreur d'allocation de mémoire");
            exit(EXIT_FAILURE);
        }

        *(int *)(new_node->content) = i; // Affectation d'une valeur à l'entier

        new_node->next = lst; // Ajout de l'élément en tête de liste
        lst = new_node;
    }

    // Affichage de la liste avant la suppression
    printf("Liste avant suppression:\n");
    t_list *current = lst;
    while (current)
    {
        printf("%d -> ", *(int *)(current->content));
        current = current->next;
    }
    printf("NULL\n");

    // Appel de ft_lstclear pour nettoyer la liste
    ft_lstclear(&lst->next->next, &del);


    printf("Liste apres suppression:\n");
	current = lst;
	//printf("%d -> ", *(int *)(current->content));

    while (current)
    {
        printf("%d -> ", *(int *)(current->content));
        current = current->next;
    }
    printf("NULL\n");

    // Vérification que la liste a été correctement vidée
    if (!current)
    {
        printf("La liste a été correctement vidée.\n");
    }
    else
    {
        printf("Erreur: La liste n'a pas été correctement vidée.\n");
    }

	//FT_LSTITER
	 t_list *element_test_lstiter1 = malloc(sizeof(t_list));
    element_test_lstiter1->content = "Element 1";
    
    t_list *element_test_lstiter2 = malloc(sizeof(t_list));
    element_test_lstiter2->content = "Element 2";
    
    t_list *element_test_lstiter3 = malloc(sizeof(t_list));
    element_test_lstiter3->content = "Element 3";
    
    // Construction de la liste chaînée
    element_test_lstiter1->next = element_test_lstiter2;
    element_test_lstiter2->next = element_test_lstiter3;
    element_test_lstiter3->next = NULL;

    // Appel de ft_lstiter avec la fonction print_content
    ft_lstiter(element_test_lstiter1, &print_content);

    // Libération de la mémoire allouée pour les éléments de la liste
    free(element_test_lstiter1);
    free(element_test_lstiter2);
    free(element_test_lstiter3);

	//LSTMAP
	t_list *lst_test_lstmap = NULL;
    ft_lstadd_back(&lst_test_lstmap, ft_lstnew(strdup("salut")));
    ft_lstadd_back(&lst_test_lstmap, ft_lstnew(strdup("la")));
    ft_lstadd_back(&lst_test_lstmap, ft_lstnew(strdup("team!")));

    printf("Liste initiale : ");
    print_list(lst_test_lstmap);

    // Application de ft_lstmap avec la fonction de changement de capitalisation
    t_list *new_lst_test_lstmap = ft_lstmap(lst_test_lstmap, &change_capitalization, free);

    printf("Nouvelle liste avec la capitalisation modifiée : ");
    print_list(new_lst_test_lstmap);

    // Libération de la mémoire
    while (new_lst_test_lstmap) {
        t_list *temp = new_lst_test_lstmap;
        new_lst_test_lstmap = new_lst_test_lstmap->next;
        free(temp);
    }
}
