/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:22:10 by cduverge          #+#    #+#             */
/*   Updated: 2021/01/18 15:21:56 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int main(int ac, char **av)
{
    if (ac < 0)
        printf("\033[31mgros soucis\033[37m");
    else if (ac != 2)
        printf("\033[31mle polynome doit etre ecrit dans une seule string\033[37m");
    else
        parsing(av[1]);
    return(0);
}