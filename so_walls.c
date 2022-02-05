/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_walls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:06:11 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/05 18:06:27 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "so_test.h"

int	map_x_walls(t_jinx *p, int x, int y)
{
	int k;
	
	k = 0;
	while (p->maaaaap[k][0] == '1' && p->maaaaap[k][x - 1] == '1' && (k + 1) < y)
	{
		k++;
		if ((k + 1) == y || (!p->maaaaap[k][x + 1] && !p->maaaaap[k][0]))
			return(1);			
	}	
	if (p->maaaaap[k][0] != '1' || p->maaaaap[k][x] != '1')
	{
		printf("you need walls in the left or the right of the map");
		return (0);
	}
	return (0);
}
int	map_y_walls(t_jinx *p, int x, int y)
{
	int k;
	
	k = 0;
	while (p->maaaaap[0][k] == '1' && p->maaaaap[y - 1][k] == '1' && (k + 1) < x)
	{
		if ((k + 1) < x || (!p->maaaaap[0][k] && !p->maaaaap[y - 1][k]))
			return (1);
		k++;
	}
	if (p->maaaaap[0][k] != '1' || p->maaaaap[y][k] != '1')
	{
		printf("you need walls in the top or bot of the map");
		return (0);
	}
	return (0);
}