/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouykou <obouykou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 15:22:16 by obouykou          #+#    #+#             */
/*   Updated: 2020/12/28 19:20:02 by obouykou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mcp.h"

#define intig(r) (r - (int)r != 0.0000000000 ? (int)r + 1 : (int)r);

void 	dims_calc(t_mp *mp)
{
	mp->xt = 
	mp->rti.x = intig(mp->xt);
	mp->rti.y = intig(mp->yt);
	mp->rbi.x = (int)(mp->xt + mp->w);
	mp->rbi.y = (int)(mp->yt + mp->h); 
}

int		check_op(t_mp *mp)
{
	if (mp->spec != 'r' && mp->spec != 'R')
		return (1);
	dims_calc(mp);
	return (0);
}
