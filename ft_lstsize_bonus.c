/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@contact.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:09:30 by itahri            #+#    #+#             */
/*   Updated: 2024/03/25 17:39:00 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}


#include <stdio.h>
int	main(void)
{
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

	return (0);
}