/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:22:16 by obouykou          #+#    #+#             */
/*   Updated: 2020/12/29 09:52:05 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "micro_paint.h"

int		intig(float r)
{
	return (r - (int)r != 0.0000000000 ? (int)r + 1 : (int)r);
}

int		test_index(t_mp *mp, int i, int j)
{
	int b;
	
	b = j >= mp->xt && j <= mp->xb && i >= mp->yt && i <= mp->yb;
	if (b && mp->spec)
		return (1);
	else if (b && (i == intig(mp->yt) || i == intig(mp->yb) || j == (int)mp->xt || j == (int)mp->xb))
		return (1);
	return (0);
}

void	fill_rec(t_mp *mp)
{
	int i;
	int j;

	i = -1;
	while (++i < mp->bg.h)
	{
		j = -1;
		while (++j < mp->bg.w)
			if (test_index(mp, i, j))
				mp->rec[i][j] = mp->c;
	}
}

int		check_op(t_mp *mp)
{
	if (mp->spec != 'r' && mp->spec != 'R')
		return (1);
	if (mp->h <= 0.0000000000 || mp->w <= 0.0000000000)
		return (1);
	mp->spec = (mp->spec == 'R');
	mp->xb = mp->xt + mp->w;
	mp->yb = mp->yt + mp->h;
	fill_rec(mp);
	return (0);
}
