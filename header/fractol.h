/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:08:33 by mmisumi           #+#    #+#             */
/*   Updated: 2025/05/07 13:12:20 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdio.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <math.h>

typedef struct s_complex
{
	double	real;
	double	i;
}			t_complex;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx_data;


int	main(void);

#endif

