/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:22:10 by cduverge          #+#    #+#             */
/*   Updated: 2021/01/18 15:21:56 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computorv1.h"

int search_degree(char *pln)
{
    int degree;
    int new_degree = 0;
    int i = 0;

    degree = 0;
    while (pln[i])
    {
        if (pln[i] == 'X')
        {
            ++i;
            if (pln[i] == '^')
                new_degree = ft_atoi(pln + i + 1);
            else
                new_degree = 1;
        }
        if (new_degree > degree)
            degree = new_degree;
        ++i;
    }
    return(degree);
}

float ft_sqrtf(float x) {
  float a;
  float b;
  float m;
  float xn;
  float res;

  if( x == 0.0)
     res = 0.0;
  else
  {
    m = 1.0;
    xn = x;
    while(xn >= 2.0)
    {
       xn *= 0.25;
       m *= 2.0;
    }
    while(xn < 0.5)
    {
       xn *= 4.0;
       m *= 0.5;
    }
    a = xn;
    b = 1.0 - xn;
    a *= (1.0 + 0.5 * b);
    b = 0.25 * (3.0 + b ) * b * b;
    while(b >= 1.0E-15)
    {
       a *= (1.0 + 0.5 * b);
       b = 0.25 * (3.0 + b) * b * b;
    }
    res = a * m;
  }
  return(res);
} 

float	ft_end_atof(char *s, unsigned long i, float res)
{
	unsigned long	dec;

	dec = 1;
	while (ft_isdigit(s[i]))
	{
		res *= 10;
		res += (int)(s[i++] - '0');
	}
	if (s[i] == ',' || s[i] == '.')
	{
		i++;
		while (ft_isdigit(s[i]))
		{
			dec *= 10;
			res += (float)(s[i++] - '0') / (float)dec;
		}
	}
	return (res);
}

float	ft_atof(char *s)
{
	float			res;
	int				signe;
	unsigned long	i;

	res = 0.f;
	signe = 1;
	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		if (s[i] == '+' || s[i] == '-')
		{
			if (s[i++] == '-')
				signe = -1;
		}
		res = ft_end_atof(s, i, res);
	}
	if (signe == -1)
		res = -res;
	return (res);
}

float delta_sign(float *pln)
{
    float a;
    float b;
    float c;
    float delta;

    printf("\033[33m\033[41mCalcul du delta : b^2 -4ac\033[40m\n");
    a = pln[2];
    b = pln[1];
    c = pln[0];
    printf("\033[33m\033[41ma = %.2f\nb = %.2f\nc = %.2f\033[40m\n", a, b, c);
    delta = b * b - 4 * a * c;
    printf("\033[33m\033[41m%.2f^2 - 4 * %.2f * %.2f = %.2f\033[40m\n", b, a, c, delta);
    return(delta);
}

void del_space(char *pln)
{
    char **tab;
    int k = 0;
    int i = 0;
    int j;

    tab = ft_strsplit(pln, ' ');
    ft_strclr(pln);
    while (tab[k])
    {
        j = 0;
        while (tab[k][j])
        {
            if (tab[k][j] == '-')
            {
                pln[i] = '+';
                ++i;
            }
            pln[i] = tab[k][j];
            ++i;
            ++j;
        }
        ++k;
    }
    pln[i] = '\0';
}

int is_digit_string(char *str)
{
    int ret;

    if (str[0] == '-')
    {
        if (str[1] == 'X')
            ret = -1;
        else
            ret = 0;
    }
    else if (str[0] == 'X')
        ret = 1;
    else
        ret = 0;
    return(ret);
}