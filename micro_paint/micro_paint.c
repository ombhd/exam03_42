/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:14:46 by obouykou          #+#    #+#             */
/*   Updated: 2021/01/06 19:52:24 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

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

int		corrupted(void)
{
	ft_putstr("Error: Operation file corrupted\n");
	return (1);
}

int		check_args_file(int ac, char **av, FILE **f, t_mp *mp)
{
	if (ac != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	if (!(*f = fopen(av[1], "r")) || fscanf(*f, "%d %d %c\n", &mp->bg.w, &mp->bg.h, &mp->bg.c) != 3)
		return (corrupted());
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

void	print_arr(char **arr)
{
	if (arr)
		while (*arr)
		{
			ft_putstr(*arr++);
			ft_putchar('\n');
		}
}

void	print_mcp(t_mp *mp, int b)
{
	if (!mp)
	{
		puts("\nYour struct is NULL");
		return ;
	}
	printf("number of read values = b =|%d|\n", b);
	printf("spec=|%c|\tX=|%f|\tY=|%f|\tW=|%f|\tH=|%f|\tCHAR|%c|\n",mp->spec, mp->xt, mp->yt, mp->w, mp->h, mp->c);
	
}

void	free_arr(char **arr)
{
	int i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

int		intig(float r)
{
	int i;

	i = r - (int)r != 0.000000 ? (int)r + 1 : (int)r;
	// printf("\nr=|%f|\t(int)r=|%d|\t r - (int)r = |%f| (int)r + 1 = |%d|\n", r, (int)r, r - (int)r, (int)r + 1);
	return (i);
}

int		test_index(t_mp *mp, float i, float j)
{
	int b;
	//#####################################################################################
	// HERE ###############################################################################
	//#####################################################################################
	b = j >= mp->xt && j <= mp->xb && i >= mp->yt && i <= mp->yb;
	if (b && mp->spec)
		return (1);
	else if (b && (i == intig(mp->yt) || i == (int)mp->yb || j == intig(mp->xt) || j == (int)mp->xb))
		return (1);
	return (0);
}

void	fill_rec(t_mp *mp)
{
	int i;
	int j;

	i = - 1;
	while (++i < mp->bg.h)
	{
		j = - 1;
		while (++j < mp->bg.w)
			if (test_index(mp, i, j))
				mp->rec[i][j] = mp->c;
	}
}

int		check_op(t_mp *mp)
{
	if ((mp->spec != 'r' && mp->spec != 'R') || 
		mp->h <= 0.00000000 || mp->w <= 0.00000000)
		return (1);
	mp->spec = (mp->spec == 'R');
	mp->xb = mp->xt + mp->w;
	mp->yb = mp->yt + mp->h;
	fill_rec(mp);
	return (0);
}

int		main(int ac, char **av)
{
	FILE *f;
	t_mp *mp;
	t_mp mcp;
	char **arr;
	int b;
	
	mp = &mcp;
	*mp = (struct s_mp){0};
	if (check_args_file(ac, av, &f, mp))
		return (1);
	if (!is_vld(mp->bg.w, mp->bg.h) || !mp->bg.c)
		return (corrupted());
	arr = alloc_fill_arr(mp->bg.w, mp->bg.h, mp->bg.c);
	mp->rec = arr;
	while ((b = fscanf(f, "%c %f %f %f %f %c\n", &mp->spec, &mp->xt, &mp->yt, &mp->w, &mp->h, &mp->c)) != EOF)
	{
		if (b != 6 && mp->spec != 0)
			return (corrupted());
		if (check_op(mp))
			return (corrupted());
	}
	print_arr(arr);
	free_arr(arr);
	fclose(f);
	return (0);
}