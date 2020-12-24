/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:14:46 by obouykou          #+#    #+#             */
/*   Updated: 2020/12/24 15:23:46 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcp.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

int		corrupted(int err)
{
	if (err == 1)
		ft_putstr("Error: Operation file corrupted\n");
	else
		ft_putstr("Error: Operation file is not valid\n");
	return (1);
}

int		check_args_file(int ac, char **av, FILE **f, t_mp *mp)
{
	if (ac != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	if (!(*f = fopen(av[1], "r+")) || fscanf(*f, "%d %d %c", &mp->bg.w, &mp->bg.h, &mp->bg.c) != 3)
		return (corrupted(1));
	return (0);
}

char **	alloc_fill_arr(int w, int h, int b_char)
{
	int i;
	char **matrix;

	matrix = (char **)malloc((h + 1) * sizeof(char *));
	matrix[h] = NULL;
	i = -1;
	while (++i < h)
	{
		matrix[i] = (char *)malloc(w + 1);
		memset(matrix[i], b_char, w);
		matrix[i][w] = '\0';
	}
	return (matrix);
}

int		main(int ac, char **av)
{
	FILE *f;
	t_mp *mp;
	int i;
	int j;
	int b;
	
	if (!(mp = (t_mp *)malloc(sizeof(t_mp))))
		return (1);
	if (check_args_file(ac, av, &f, mp))
		return (1);
	if (!is_vld(mp->bg.w, mp->bg.h) || !mp->bg.c)
		return (corrupted(2));
	mp->arr = alloc_fill_arr(mp->bg.w, mp->bg.h, mp->bg.c);
	b = 5;
	while ((b = fscanf(f, "\n%c %f %f %f %f %c"), mp->spec, mp->x, mp->y, mp->w, mp->h, mp->c) != EOF)
	{
		if (b != 5)
			return (corrupted(2));
		if (check_op(mp))
			return (corrupted(2));
		
		
	}
	fclose(f);
	return (0);
}