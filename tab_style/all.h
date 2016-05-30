/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:15:16 by thifranc          #+#    #+#             */
/*   Updated: 2016/05/30 15:33:47 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

# define STOP -666

void	print_tab(int **tab);
int		tablen(int **tab);

void	swapp(int **tab, int a, int b);
void	push(int **tab, int **b);
void	rotate(int **tab);
void	rev_rotate(int **tab, int last);
#endif
