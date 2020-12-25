/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mcp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:56:12 by obouykou          #+#    #+#             */
/*   Updated: 2020/12/25 17:42:55 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MCP_H_
# define _MCP_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

# define is_vld(w, h) (h > 0 && h <= 300 && w > 0 && w <= 300)

typedef struct	s_indexer
{
	int i;
	int j;
}				t_indexer;

typedef	struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_bgd
{
	int		w;
	int		h;
	char	c;
}				t_bgd;

typedef	struct	s_mp
{
	t_bgd	bg;
	char	spec;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
	t_point rt;
	t_point rb;
	char	**rec;
	t_indexer idx;
}				t_mp;

int		check_op(t_mp *mp);
int		corrupted(void);

#endif