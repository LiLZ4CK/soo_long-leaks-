/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_test.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:06:38 by zwalad            #+#    #+#             */
/*   Updated: 2022/02/05 00:56:28 by zwalad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_TEST_H
# define SO_TEST_H

# include	"mlx.h"
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<fcntl.h>
# include	"libft.h"

typedef struct t_jinx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*new_img;
	char	*player_path;
	char	*free_path;
	char	**maaaaap;
	int		width;
	int		height;
	
}	t_jinx;

int		map_check(int argc, char **argv);
int		ft_mouve(int keycode, t_jinx *p);
int		mouse(int keycode, t_jinx *p);
int		map_y_walls(t_jinx *p, int x, int y);
int		map_x_walls(t_jinx *p, int x, int y);
int		check_components(t_jinx *p);
int		draw_map(t_jinx *p);
int		check_components2(t_jinx *p);
int		keep_map(t_jinx *p);
int		putfloor(t_jinx *p, int x, int y);
int		wall_check(t_jinx *p, int keycode, int x, int y);
int		spawny(char *s, char c);
int 	check_collec(t_jinx *p, int x, int y);
int		exit_block(t_jinx *p, int keycode, int x, int y);
int 	mapchr(t_jinx *p, char c);




#endif 