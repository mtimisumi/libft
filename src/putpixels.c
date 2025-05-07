/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmisumi <mmisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:30:20 by mmisumi           #+#    #+#             */
/*   Updated: 2025/05/06 20:45:00 by mmisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define BLACK 0x00000000
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#define YELLOW 0x00FFFF00
#define MAGENTA 0x00FF00FF

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

//y * line_length skips over y rows
//x * (bpp / 8) skips to the xth pixel of that row
//you will get a pointer to the correct pixels memory and write the color directly
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//!!everytime i return i should probably also free stuff!!
// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	if (!mlx)
// 		return (1);
	
// 	//create window
// 	mlx_win = mlx_new_window(mlx, 800, 600, "minilibx Example");
// 	if (!mlx_win)
// 		return (1);

// 	//create new image
// 	img.img = mlx_new_image(mlx, 800, 600);

// 	//get image data adress
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

// 	//draw red pixel at position 100 100
// 	my_mlx_pixel_put(&img, 400, 300, MAGENTA);

// 	//push image to window
// 	//0 0 to start drawing the pixel from top left corner
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

// 	mlx_loop(mlx);
// 	return (0);
// }

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
}			t_vars;

#define PI 3.14159265

int	is_in_star(int x, int y, int cx, int cy, int outer_r, int inner_r)
{
	double angle_step = PI / 5;
	double angle = -PI / 2;
	int points[10][2];

	for(int i = 0; i < 10; i++)
	{
		int r = (i % 2 == 0) ? outer_r : inner_r;
		points[i][0] = cx + r * cos(angle);
		points[i][1] = cy + r * sin(angle);
		angle += angle_step;
	}

	int inside = 0;
	for (int i = 0, j = 9; i < 10; j = i++)
	{
		int xi = points[i][0], yi = points[i][1];
		int xj = points[j][0], yj = points[j][1];

		if (((yi > y) != (yj > y)) &&
			(x < (xj - xi) * (y - yi) / (double)(yj - yi) + xi))
			inside = !inside;
	}
	return inside;
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 700, "yooooo");

	//create the image
	vars.img.img = mlx_new_image(vars.mlx, 1000, 700);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

	int y = 0;
	int x = 0;
	while (y < 700)
	{
		x = 0;
		while (x < 1000)
		{
			int red = (x * 255) / 1000;//so the red will be the most intense at the right where x is highest and no red left wher x is zero
			int green = (y * 255) / 700;//so green is most intense below and nothing at the top
			int blue = 128;//constant mid level for all pixels
			int color = (red << 16) | (green << 8) | blue;//shift them this amount to the right, since red is RROOOO it needs to be shifted the most and blue is lowest so doestn need to be shifted
			//line above is also how the computer knows which color it means, cause the << 16 can tell u something about the rbg representation
			
			if (is_in_star(x, y, 1000 / 2, 700 / 2, 150, 60))//to start in the middle and to igve it a outer radius
				color = BLACK;
			my_mlx_pixel_put(&vars.img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
