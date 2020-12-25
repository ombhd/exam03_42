/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:22:16 by obouykou          #+#    #+#             */
/*   Updated: 2020/12/25 15:36:19 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcp.h"

void 	dims_calc(t_mp *mp)
{
	mp->rt.x = mp->x - (int)mp->x != 0.0000000000? (int)mp->x + 1 : (int)mp->x;
	mp->rt.y = mp->y - (int)mp->x != 0.0000000000? (int)mp->x + 1 : (int)mp->x;
	mp->rt.y = (int)mp->y + 1;
	
}

int		check_op(t_mp *mp)
{
	if (mp->spec != 'r' && mp->spec != 'R')
		return (1);
	
}
