/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:22:10 by cduverge          #+#    #+#             */
/*   Updated: 2021/01/18 15:21:56 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int check_caracteres(char *pln)
{
    int i;
    int ret = 0;

    for (i = 0; pln[i] != '\0'; ++i)
    {
        if (ft_strchr("0123456789*/-+=X.^", pln[i]) == NULL)
            ret = 1;
    }
    return(ret);
}

int check_power(char *pln)
{
    int ret = 0;
    int power;
    int cur;
    int i;
    int degree;
    int j = 0;
    char **tab;

    tab = ft_strsplit(pln, '=');
    while (j < 2)
    {
        i = 0;
        power = 0;
        cur = 1;
        while (tab[j][i])
        {
            if (tab[j][i] == 'X')
            {
                ++i;
                if (tab[j][i] == '^')
                {
                    degree = ft_atoi(tab[j] + i + 1);
                    if (power != degree)
                        ret = 1;
                    else if (power == degree && power != 0)
                        ++cur;
                }
                else
                {
                    if (power != 1)
                        ret = 1;
                    ++cur;
                }
            }
            if (tab[j][i] == '+')
                ++power;
            ++i;
        }
        if (power != 0 && cur != (power + 1))
            ret = 1;
        ++j;
    }
    return(ret);
}

int pars_string(char *pln)
{
    int ret = 0;

    if (check_caracteres(pln) == 1)
    {
        ret = 1;
        printf("\033[31mLa string ne doit contenir que des X, chiffres et symboles mathematiques simples.\033[37m\n");
    }
    if (check_power(pln) == 1)
    {
        ret = 1;
        printf("\033[31mLe polynome doit presenter ses puissances dans l'ordre croissant.\033[37m\n");
    }
    return(ret);
}