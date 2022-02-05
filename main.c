/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:14:38 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/05 18:03:32 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_test.h"
#include	"get_next_line.h"

char *player_banania(int keycode)
{
	char	*up = "./img/banania_up.xpm";
	char	*down = "./img/banania_down.xpm";
	char	*left = "./img/banania_left.xpm";
	char	*right = "./img/banania_right.xpm";
	
	if (keycode == 13 || keycode == 126)
		return (up);
	if (keycode == 1 || keycode == 125)
		return (down);
	if (keycode == 0 || keycode == 123)
		return (left);
	if (keycode == 2 || keycode == 124)
		return (right);
	return (down);
} 
int map_check(int argc, char **argv)
{
	int 	i;
	char	*ber = ".ber";
	int 	len;

	i = 0;
	len = ft_strlen(argv[1]) - 4;
	if (argc == 2)
	{
		while (argv[1][len] == ber[i])
		{
			len++;
			i++;
			if (!argv[1][len] && !ber[i])
				return(1);
			if (argv[1][len] != ber[i])
			{
				printf("your map is invalid!\n");
				return(0);
			}
		}
	}
	printf("your map is invalid!\n");
	return(0);
}
char	**map(int argc, char **argv, char **map)
{
	int		i;
	int		j;
	char	*str;
	char 	*p;
	char	*le_free;
	int fd;
	
	i = 0;
	fd = open(argv[1], O_RDONLY);
	le_free = get_next_line(fd);
	while (le_free)	
	{
		i++;
		free(le_free);
		le_free = get_next_line(fd);
	}
	free(le_free);
	printf("%d\n", i);
	map = malloc(sizeof(char *) * i + 1);
	close(fd);
	str = ft_strdup("");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		exit(1);
		return(0);
	}
	p =  str;
	str = get_next_line(fd);
	free(p);
	p = NULL;
	i = 0;
	while (str != NULL)
	{
		map[i] = malloc(ft_strlen(str) + 1);
		if (!map[i])
		{
			free(str);
			str = NULL;
			return (NULL);
		}
		map[i] = ft_strdup(str);
		map[i+1] = NULL;
		p = str;
		str = get_next_line(fd);
		free(p);
		//free(str);
		i++;
	}
	free(str);
	str = NULL;
	return (map);
}
int	ft_move_y(int keycode, t_jinx *p, int x, int y)
{
	if (keycode == 125 || keycode == 1)
	{
		y += 80;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	if (keycode == 126 || keycode == 13)
	{
		y -= 80;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	return (y);
} 
int	ft_move_x(int keycode, t_jinx *p, int x, int y)
{
	if (keycode == 124 || keycode == 2)
	{
		x += 80;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	if (keycode == 123 || keycode == 0)
	{
		x -= 80;
		mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
	}
	
	return (x);
}
int	mouse(int keycode, t_jinx *p)
{
	exit(1);
	return (0);
}
int	ft_mouve(int keycode, t_jinx *p)
{
	static int x = 0;
	static int y = 0;
	static int i = 0;
	static int c = 0;
	int k;
	
	if (i == 0)
	{
		while (x == 0)
		{
			x = spawny(p->maaaaap[y], 'P');
			y++;
		}
		i++;
		y--;
		x *= 80;
		y *= 80;
	}
	if (check_collec(p, x, y) == 1)
		c++;
	k = mapchr(p, 'C');
	printf("k = %d ,, c == %d\n", k, c);
	if (k <= c && exit_block(p, keycode, x, y))
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit(1);
		return (0);
	}
	k = mapchr(p, 'C');
	if (k != c && exit_block(p, keycode, x, y))
		return (0);
	if (wall_check(p, keycode, x, y))
	{
		if (keycode == 124 || keycode == 2 || keycode == 123 || keycode == 0
		|| keycode == 125 || keycode == 1 || keycode == 126 || keycode == 13)
		{
			putfloor(p, x, y);
		}
		p->player_path = player_banania(keycode);
		p->player = mlx_xpm_file_to_image(p->mlx_ptr, p->player_path, &p->width, &p->height);
		if (keycode == 124 || keycode == 2 || keycode == 123 || keycode == 0)
		{
			x = ft_move_x(keycode, p, x, y);
			putfloor(p, x, y);
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
				printf("your move is : %d\n", i++);
		}
		if (keycode == 125 || keycode == 1 || keycode == 126 || keycode == 13)
		{
			y = ft_move_y(keycode, p, x, y);
			putfloor(p, x, y);
			mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->player, x, y);
			printf("your move is : %d\n", i++);
		}
		if (keycode == 12 || keycode == 53)
		{
			mlx_destroy_window(p->mlx_ptr, p->win_ptr);
			exit(1);
			return (0);
		}
	}
	return (0);
}
int main(int argc, char *argv[])
{
	int 	i;
	int 	j;
	int		keycode;
	t_jinx	p;
	
	if (!map_check(argc, argv))
		{
			exit (1);
			return (0);
		}
	p.maaaaap = map(argc, argv, p.maaaaap);
	while (p.maaaaap[i])
	{
		j = 0;
		while (p.maaaaap[i][j])
			j++;
		i++;
	}
	j = ft_strlen(p.maaaaap[0]) - 1;
	if(!map_x_walls(&p, j, i) || !map_y_walls(&p, j, i))
	{
		exit(1);
		return (0);
	}
	if(!check_components(&p))
		return(0);	
	check_components2(&p);
	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, j * 80, i * 80, "so_long");
	draw_map(&p);
	mlx_key_hook(p.win_ptr, ft_mouve, &p);
	mlx_hook(p.win_ptr, 17, (1L<<17), mouse, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}