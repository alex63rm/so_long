/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejarod <alejarod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:40:32 by alejarod          #+#    #+#             */
/*   Updated: 2023/03/07 19:40:50 by alejarod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
//#include <readline/readline.h>

int main() {
    char *line;

    // Mostrar el prompt al usuario y leer la línea de entrada
    line = readline("Ingresa una línea de texto: ");

    // Imprimir la línea de entrada
    printf("La línea ingresada es: %s\n", line);

    // Liberar la memoria asignada para la línea de entrada
    free(line);

    return 0;
}