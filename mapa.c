/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:28:07 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/05 18:25:22 by zwalad           ###   ########.fr       */
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
int mapchr(t_jinx *p, char c)
{
	int	i;
	int j;
	int n;

	i = 0;
	n = 0;
	while(p->maaaaap[i])
	{
		j = 0;
		while (p->maaaaap[i][j])
		{
			if (p->maaaaap[i][j] == c)
			{
				n++;
			}
			j++;
		}
		i++;
	}
	return(n);
}
int check_components(t_jinx *p)
{
	if (mapchr(p, 'C') < 1)
	{
		printf("need at least one collectible");
		exit(0);
	}
	if (mapchr(p, 'E') < 1)
	{
		printf("need at least one exit");
		exit(0);
	}
	if (mapchr(p, '0') < 1)
	{
		printf("need at least one free space");
		exit(0);
	}
	if (mapchr(p, 'P') != 1)
	{
		printf("need atleast one player");
		exit(0);
	}
	return (1);
}
int draw_map(t_jinx *p)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (p->maaaaap[i])
	{
		j = 0;
		x = 0;
		while (p->maaaaap[i][j])
		{
			if (p->maaaaap[i][j] == '1')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/wall.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (p->maaaaap[i][j] == '0')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/free.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (p->maaaaap[i][j] == 'C')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/collect.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (p->maaaaap[i][j] == 'E')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/exit.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (p->maaaaap[i][j] == 'P')
			{
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/free.xpm", &p->width, &p->height);
				p->player = mlx_xpm_file_to_image(p->mlx_ptr, "./img/start_banania.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				x += 80;
				j++;
			}
			if (p->maaaaap[i][j] == '\n')
				j++;
		}
		y += 80;
		i++;
	}
	return(0);
}
int check_components2(t_jinx *p)
{
	int	i;
	int j;
	
	i = 0;
	while (p->maaaaap[i])
	{
		j = 0;
		while (p->maaaaap[i][j])
		{
			if (p->maaaaap[i][j] == '0' || p->maaaaap[i][j] == 'E' || p->maaaaap[i][j] == '1' 
				|| p->maaaaap[i][j] == 'P' ||p->maaaaap[i][j] == 'C' || p->maaaaap[i][j] == '\n' 
				|| p->maaaaap[i][j] == '\0')
				{
					j++;
				}
				if (p->maaaaap[i][j] != '0' && p->maaaaap[i][j] != 'E' && p->maaaaap[i][j] != '1' 
				&& p->maaaaap[i][j] != 'P' && p->maaaaap[i][j] != 'C' && p->maaaaap[i][j] != '\n' 
				&& p->maaaaap[i][j] != '\0')
				{
					printf("invalid map");
					exit(1);
				}
		}
		i++;
	}
	return (0);
}
int putfloor(t_jinx *p, int x, int y)
{
	p->free_path = mlx_xpm_file_to_image(p->mlx_ptr, "./img/free.xpm", &p->width, &p->height);
				mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->free_path, x, y);
	return  (0);
}
int	wall_check(t_jinx *p, int keycode, int x, int y)
{
	static int	i;
	static int	j;

	i = y / 80;
	j = x / 80;
	if (keycode == 13 || keycode == 126)
	{
		if(p->maaaaap[i - 1][j] == '1')
			return (0);
	}
	if (keycode == 1 || keycode == 125)
	{
		if(p->maaaaap[i + 1][j] == '1')
			return (0);
	}
	if (keycode == 0 || keycode == 123)
	{
		if(p->maaaaap[i][j - 1] == '1')
			return (0);
	}
	if (keycode == 2 || keycode == 124)
	{
		if(p->maaaaap[i][j + 1] == '1')
			return (0);
	}
	 return (1); 
}
int	exit_block(t_jinx *p, int keycode, int x, int y)
{
	static int	i;
	static int	j;

	i = y / 80;
	j = x / 80;
	if (keycode == 13 || keycode == 126)
	{
		if(p->maaaaap[i - 1][j] == 'E')
			return (1);
	}
	if (keycode == 1 || keycode == 125)
	{
		if(p->maaaaap[i + 1][j] == 'E')
			return (1);
	}
	if (keycode == 0 || keycode == 123)
	{
		if(p->maaaaap[i][j - 1] == 'E')
			return (1);
	}
	if (keycode == 2 || keycode == 124)
	{
		if(p->maaaaap[i][j + 1] == 'E')
			return (1);
	}
	  return (0); 
}
int	spawny(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
int check_collec(t_jinx *p, int x, int y)
{
	x /= 80;
	y /= 80;
	if (p->maaaaap[y][x] == 'C')
		return (1);
	return (0);
}