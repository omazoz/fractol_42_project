/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omazoz <omazoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:10:30 by omazoz            #+#    #+#             */
/*   Updated: 2022/02/28 22:21:26 by omazoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	max_iter(t_env *env, t_mande_l v)
{
	while (v.k < MAX_ITER)
	{
		v.a = (v.x * v.x - v.y * v.y);
		v.b = (v.x * v.y + v.x * v.y);
		v.x = (v.a + v.ca);
		if (v.x < 0)
			v.x = -v.x;
		v.y = (v.b + v.cb);
		if (v.y < 0)
			v.y = -v.y;
		if ((v.x * v.x + v.y * v.y) > 4)
			break ;
		v.k++;
	}
	if (v.k == MAX_ITER)
		ft_image_put_pixel(&env->image, v.j, v.i, \
			g_colors[env->color][0]);
	else
	{
		v.k = (v.k + 1) % 9;
		if (v.k == 0)
			v.k++;
		ft_image_put_pixel(&env->image, v.j, v.i, \
			g_colors[env->color][v.k]);
	}
}

int	draw_burningship(t_env *env, t_calc *calc)
{
	t_mande_l	v;

	v.i = calc->area.min_y;
	while (v.i < calc->area.max_y)
	{
		v.j = 0;
		while (v.j < calc->area.max_x)
		{
			v.ca = ((float)v.j / HEIGHT) * (calc->max_i - calc->min_i) + \
				calc->min_i;
			v.cb = ((float)v.i / HEIGHT) * (calc->max_r - calc->min_r) + \
				calc->min_r;
			v.k = 0;
			v.x = 0;
			v.y = 0;
			max_iter(env, v);
			v.j++;
		}
		v.i++;
	}
	return (0);
}