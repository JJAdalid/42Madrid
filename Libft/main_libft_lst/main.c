/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadalid- <jadalid-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:13:45 by jadalid-          #+#    #+#             */
/*   Updated: 2025/01/30 21:21:38 by jadalid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//para ejecutar hacer esto 
//gcc -o my_program main.c ft_lstnew_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstiter_bonus.c -I.

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

// Función para imprimir el contenido de un nodo
void print_content(void *content) {
    printf("%s\n", (char *)content);
}

// Función para liberar el contenido de un nodo
void delete_content(void *content) {
    free(content);  // Asumimos que se usó malloc en el contenido
}

// Función que se usará en ft_lstmap para modificar el contenido
void *to_uppercase(void *content) {
    char *str = (char *)content;
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - ('a' - 'A');
        }
    }
    return str;
}

int main() {
    // Crear nodos
    t_list *node1 = ft_lstnew(strdup("Hola"));
    t_list *node2 = ft_lstnew(strdup("Mundo"));
    t_list *node3 = ft_lstnew(strdup("!"));

    // Enlazar los nodos
    node1->next = node2;
    node2->next = node3;

    // Imprimir la lista original
    printf("Lista original:\n");
    ft_lstiter(node1, print_content);

    // Añadir un nodo al final con ft_lstadd_back
    t_list *new_node = ft_lstnew(strdup("Adicional"));
    ft_lstadd_back(&node1, new_node);
    printf("\nLista después de añadir al final:\n");
    ft_lstiter(node1, print_content);

    // Añadir un nodo al principio con ft_lstadd_front
    new_node = ft_lstnew(strdup("Nuevo Inicio"));
    ft_lstadd_front(&node1, new_node);
    printf("\nLista después de añadir al principio:\n");
    ft_lstiter(node1, print_content);

    // Obtener el último nodo con ft_lstlast
    t_list *last_node = ft_lstlast(node1);
    printf("\nÚltimo nodo: %s\n", (char *)last_node->content);

    // Obtener el tamaño de la lista con ft_lstsize
    int size = ft_lstsize(node1);
    printf("\nTamaño de la lista: %d\n", size);

    // Crear una nueva lista usando ft_lstmap para convertir el contenido a mayúsculas
    t_list *upper_list = ft_lstmap(node1, to_uppercase, delete_content);
    printf("\nLista modificada con ft_lstmap (todo a mayúsculas):\n");
    ft_lstiter(upper_list, print_content);

    // Eliminar la lista original
    ft_lstclear(&node1, delete_content);  // Esta línea libera la memoria de node1
    node1 = NULL;  // Asegúrate de no intentar acceder a node1 después de liberarlo

    // No intentar iterar ni acceder a node1 después de que fue limpiado
    printf("\nLista original después de ft_lstclear (no debe imprimirse nada):\n");
    if (node1 != NULL) {
        ft_lstiter(node1, print_content);  // Esta línea ahora no hace nada porque node1 es NULL
    }

    // Eliminar la lista modificada
    ft_lstclear(&upper_list, delete_content);

    return 0;
}