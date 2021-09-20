/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cduverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:37:04 by cduverge          #+#    #+#             */
/*   Updated: 2021/01/18 11:07:26 by cduverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft/libft.h"
# include <stdio.h>

float ft_sqrtf(float x);
float	ft_end_atof(char *s, unsigned long i, float res);
float	ft_atof(char *s);
float delta_sign(float *pln);
void calcul_with_delta_null(float *pln);
void calcul_with_delta_positive(float *pln, float delta);
void calcul_with_delta_negative(float *pln, float delta);
void resolve_null_degree(float *tabRes);
void resolve_degree_one(float *tabRes);
void resolve_second_degree(float *tabRes);
void resolve(float *tabRes, int degree);
int search_degree(char *pln);
void get_value_int(char *pln, float *tab);
void get_reduce_pln(char *pln, int degree);
void parsing(char *pln);
int print_primaries_informations(float *tabRes, int degree);
int pars_string(char *pln);
int check_caracteres(char *pln);
int check_power(char *pln);
int is_digit_string(char *str);
void del_space(char *pln);
int main(int ac, char **av);

#endif