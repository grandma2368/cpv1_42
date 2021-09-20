/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:22:10 by cduverge          #+#    #+#             */
/*   Updated: 2021/01/18 15:21:56 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void get_value_int(char *pln, float *tab)
{
    int k = 0;
    int ret;
    char **tabSplit;

    tabSplit = ft_strsplit(pln, '+');
    while (tabSplit[k])
    {
        ret = is_digit_string(tabSplit[k]);
        if (ret == 1)
            tab[k] = 1;
        else if (ret == -1)
            tab[k] = -1;
        else
            tab[k] = ft_atof(tabSplit[k]);
       ++k;
    }
}

int print_primaries_informations(float *tabRes, int degree)
{
    int power;
    int i;
    printf("\033[32mForme reduite du polynome: \033[33m");

    power = 0;
    for (i = 0; i <= degree; i++)
    {
        if (tabRes[i] != 0)
        {
            if (i != 0 && tabRes[i] > 0)
                printf(" + %.2f * X^%i ", tabRes[i], i);
            else
                printf(" %.2f * X^%i ", tabRes[i], i);
            power = i;
        }
    }
    printf(" = 0\n\033[32mDegree du polynome: \033[33m %i\n", power);
    return(power);
}

void get_reduce_pln(char *pln, int degree)
{
    char **tabPln;
    float tabRes[degree + 1];
    int power;

    tabPln = ft_strsplit(pln, '=');
    
    int maxOne = search_degree(tabPln[0]);
    float tabOne[maxOne + 1];
    get_value_int(tabPln[0], tabOne);
    int maxTwo = search_degree(tabPln[1]);
    float tabTwo[maxTwo + 1];
    get_value_int(tabPln[1], tabTwo);
 
    int i = 0;
    while (i <= degree)
    {
        if (i <= maxOne && i <= maxTwo)
            tabRes[i] = tabOne[i] - tabTwo[i];
        else if (i > maxTwo)
            tabRes[i] = tabOne[i];
        else
            tabRes[i] = -1 * tabTwo[i];
        ++i;
    }
    power = print_primaries_informations(tabRes, degree);
    if (power > 2)
    {
        printf("\033[31mle polynome presente un degree trop eleve pour etre traite\n\033[37m");
        return ;
    }
    resolve(tabRes, power);
}

void parsing(char *pln)
{
    int degree;

    del_space(pln);
    pln = ft_strcapitalize(pln);
    if (ft_strchr(pln, '=') == NULL)
    {
        int len = ft_strlen(pln);
        pln[len] = '=';
        pln[len + 1] = '0';
        pln[len + 2] = '\0';
    }
    if (pars_string(pln) == 0)
    {
        degree = search_degree(pln);
        get_reduce_pln(pln, degree);
    }
}