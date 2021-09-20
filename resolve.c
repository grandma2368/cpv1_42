/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:22:10 by cduverge          #+#    #+#             */
/*   Updated: 2021/01/18 15:21:56 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

void calcul_with_delta_null(float *pln)
{
    float a;
    float b;
    float c;
    float res;

    printf("\033[33m\033[41mDelta null => on calcule X un reel solution du polynome\033[40m\n");
    printf("\033[33m\033[41mX = -b/(2a)\033[40m\n");
    a = pln[2];
    b = pln[1];
    c = pln[0];
    res = -b / (2 * a);
    if (b>= 0)
        printf("\033[33m\033[41mX = -%.2f/(2 * %.2f)\033[40m\n", b, a);
    else
        printf("\033[33m\033[41mX = %.2f/(2 * %.2f)\033[40m\n", -b, a);
    printf("\033[36mle delta est null, il y a donc une solution a ce polynome :\033[32m X = %.2f\n\033[37m", res);
}

void calcul_with_delta_positive(float *pln, float delta)
{
    float a;
    float b;
    float resOne;
    float resTwo;

    printf("\033[33m\033[41mDelta positif => on calcule X1 et X2 deux reels solutions du polynome\033[40m\n");
    printf("\033[33m\033[41mX1 = (-b + delta)/(2a)\033[40m\n");
    a = pln[2];
    b = pln[1];
    delta = ft_sqrtf(delta);
    resOne = (-b-delta)/(2*a);
    if (b >= 0)
        printf("\033[33m\033[41mX1 = (-%.2f + %.2f)/(2 * %.2f)\033[40m\n", b, delta, a);
    else
        printf("\033[33m\033[41mX1 = (%.2f + %.2f)/(2 * %.2f)\033[40m\n", -b, delta, a);
    printf("\033[33m\033[41mX2 = (-b + delta)/(2a)\033[40m\n");
    resTwo = (-b+delta)/(2*a);
    if (b >= 0)
        printf("\033[33m\033[41mX2 = (-%.2f - %.2f)/(2 * %.2f)\033[40m\n", b, delta, a);
    else
        printf("\033[33m\033[41mX2 = (%.2f - %.2f)/(2 * %.2f)\033[40m\n", -b, delta, a);
    printf("\033[36mle delta est positif, il y a donc deux solutions a ce polynome :\033[32m X1 = %.2f et X2 = %.2f\n\033[37m", resOne, resTwo);

}

void calcul_with_delta_negative(float *pln, float delta)
{
    float a;
    float b;
    float im;
    float res;

    printf("\033[33m\033[41mDelta negatif => on calcule X1 et X2 deux imaginaires solutions du polynome\033[40m\n");
    printf("\033[33m\033[41mPartie imaginaire = (i * delta)/(2a)\033[40m\n");
    a = pln[2];
    b = pln[1];
    delta = ft_sqrtf(-delta);
    im = delta / (2 * a);
    printf("\033[33m\033[41mPartie imaginaire = (i * %.2f)/(2 * %.2f)\033[40m\n", delta, a);
    printf("\033[33m\033[41mPartie reelle = -b/(2a)\033[40m\n");
    res = (-b) / (2 * a);
    if (b >= 0)
        printf("\033[33m\033[41mPartie reelle = - %.2f /(2 * %.2f)\033[40m\n", b, a);
    else
        printf("\033[33m\033[41mPartie reelle = %.2f /(2 * %.2f)\033[40m\n", -b, a);
    printf("\033[36mle delta est negatif, il y a donc deux solutions imaginaires a ce polynome :\033[32m X1 = %.2f + %.2fi et X2 = %.2f - %.2fi\n\033[37m", res, im, res, im);
}

void resolve_null_degree(float *tabRes)
{
    if (tabRes[0] == 0)
        printf("\033[36mcette equation n'a pas d'inconnue, puisque X^0 vaut 1 : \033[32m 0 = 0 est une egalite correcte, cette equation a donc l'ensemble des reels pour solution !\n");
    else
        printf("\033[36mcette equation n'a pas d'inconnue, puisque X^0 vaut 1 : \033[31m %.2f  = 0 n'est pas une egalite correcte, cette equation n'a donc pas de solution !\n", tabRes[0]);
}

void resolve_degree_one(float *tabRes)
{
    float res;
    if (tabRes[1] == 0)
    {
        resolve_null_degree(tabRes);
        return ;
    }
    else if (tabRes[1] == 1)
    {
        printf("\033[33m\033[41mEtape intermediaide\033[40m\n");
        res = -1 * tabRes[0];
        if (tabRes[0] >= 0)
            printf("\033[41m%.2f - %.2f + X = - %.2f\033[40m\n", tabRes[0], tabRes[0], tabRes[0]);
        else
            printf("\033[41m%.2f + %.2f + X = %.2f\033[40m\n", res, res, res);
    }
    else if (tabRes[1] == -1)
    {
        printf("\033[33m\033[41mEtapes intermediaides\033[40m\n");
        res = -1 * tabRes[0];
        if (tabRes[0] >= 0)
        {
            printf("\033[41m%.2f - %.2f - X = - %.2f\033[40m\n", tabRes[0], tabRes[0], tabRes[0]);
            printf("\033[41m-X * -1 = - %.2f * -1\033[40m\n", tabRes[0]);
        }
        else
        {
            printf("\033[41m%.2f + %.2f - X = %.2f\033[40m\n", tabRes[0], res, res);
            printf("\033[41m-X * -1 = %.2f * -1\033[40m\n", res);
        }
    }
    else
    {
        printf("\033[33m\033[41mEtapes intermediaides\033[40m\n");
        if (tabRes[0] >= 0)
        {
            if (tabRes[1] >= 0)
                printf("\033[41m%.2f - %.2f + %.2f * X = - %.2f\033[40m\n", tabRes[0], tabRes[0], tabRes[1], tabRes[0]);
            else
                printf("\033[41m%.2f - %.2f %.2f * X = - %.2f\033[40m\n", tabRes[0], tabRes[0], tabRes[1], tabRes[0]);
            printf("\033[41m(%.2f * X) / %.2f = - %.2f / %.2f\033[40m\n", tabRes[1], tabRes[1], tabRes[0], tabRes[1]);
        }
        else
        {
            res = -1 * tabRes[0];
            if (tabRes[1] >= 0)
                printf("\033[41m%.2f + %.2f + %.2f * X = %.2f\033[40m\n", tabRes[0], res, tabRes[1], res);
            else
                printf("\033[41m%.2f + %.2f %.2f * X = %.2f\033[40m\n", tabRes[0], res, tabRes[1], res);
            printf("\033[41m(%.2f * X) / %.2f = %.2f / %.2f\033[40m\n", tabRes[1], tabRes[1], tabRes[0], tabRes[1]);
        }
        res = (-1 * tabRes[0]) / tabRes[1];
    }
    printf("\033[36mcette equation a une solution :\033[32m %.2f\n", res);
}

void resolve_second_degree(float *tabRes)
{
    float delta;

    printf("\033[33m\033[41mEtapes intermediaides\033[40m\n");
    delta = delta_sign(tabRes);
    if (delta > 0)
        calcul_with_delta_positive(tabRes, delta);
    else if (delta == 0)
        calcul_with_delta_null(tabRes);
    else
        calcul_with_delta_negative(tabRes, delta);
}

void resolve(float *tabRes, int degree)
{
    if (degree == 0)
        resolve_null_degree(tabRes);
    else if (degree == 1)
        resolve_degree_one(tabRes);
    else
        resolve_second_degree(tabRes);
}