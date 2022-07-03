

#include "tutorial.h"

int	gen_trgb(int opacity, int red, int green, int blue)
{
	if (opacity > 255 || red > 255 || green > 255 || blue > 255)
		return (0);
	return (opacity << 24 | red << 16 | green << 8 | blue);
}

int	get_opacity(int trgb)
{
	return ((trgb >> 24) & 0XFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0XFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0XFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

t_img   *new_image(t_window *win, int height, int width)
{
	t_img   *img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
	return (NULL);
	img->win = win;
	img->w = width;
	img->h = height;
	img->img_ptr = mlx_new_image(win->mlx_ptr, width, height);
	img->addr = mlx_get_data_addr(img->img_ptr, &(img->bpp),
	&(img->line_len), &(img->endian));
	return (img);
}

t_window	*new_window(int height, int width, char *str)
{
	t_window	*win;
	void		*mlx_ptr;
	void		*win_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
	return (NULL);
	win_ptr = mlx_new_window(mlx_ptr, width, height, str);
	if (!win_ptr)
	return (NULL);
	win = (t_window *)malloc(sizeof(t_window));
	win->mlx_ptr = mlx_ptr;
	win->win_ptr = win_ptr;
	win->height = height;
	win->width = width;
	return (win);
}

// void	draw_square(t_square square, t_img *img)
// {
//	 unsigned short int  i;
//	 unsigned short int  j;

//	 i = 0;
//	 while (i < square.size && i < img->h)
//	 {
//	 j = 0;
//	 while (j < square.size && j < img->w)
//	 {
//	 put_pixel_img(img, j + square.x, i + square.y, square.color);
//	 j++;
//	 }
//	 i++;
//	 }
// }

void	draw_player(t_player player, t_img *img)
{
	put_pixel_img(img, player.px, player.py, player.color);
}

int exit_tutorial(t_img *img)
{
	free(img->win);
	free(img);
	exit(EXIT_SUCCESS);
}

int main(void)
{
	t_window	*win;
	t_img		*img;
	// t_square	square;
	t_player	player;

	win = new_window(400, 400, "Tutorial");
	if (!win)
	return (-1);
	img = new_image(win, 400, 400);
	if (!img)
	return (-1);
	printf("Created an image [%d x %d]\n", img->w, img->h);
	player = (t_player){200, 200, gen_trgb(0, 255, 0, 0)};
	draw_player(player, img);
	// square = (t_square){100, 100, 200, gen_trgb(0, 0, 128, 0)};
	// draw_square(square, img);
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, img->img_ptr, 0, 0);
	mlx_hook(win->win_ptr, 17, 0, exit_tutorial, img);
	mlx_loop(win->mlx_ptr);
	free(win);
	free(img);
	return (0);
}
