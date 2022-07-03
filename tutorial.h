/* ************************************************************************** */
/*	  */
/*	 :::	  ::::::::	*/
/*	tutorial.h	  :+:	:+:	 :+:	*/
/*	  +:+ +:+	 +:+	 */
/*	By: acmaghou <acmaghou@student.42.fr>	+#+  +:+	 +#+	 */
/*	+#+#+#+#+#+	+#+	  */
/*	Created: 2022/07/03 11:47:30 by acmaghou	  #+#  #+#	 */
/*	Updated: 2022/07/03 16:30:17 by acmaghou	 ###	########.fr	 */
/*	  */
/* ************************************************************************** */

#ifndef TUTORIAL_H
# define TUTORIAL_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct  s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}			t_window;

typedef struct s_img
{
	t_window	*win;
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_square
{
	unsigned short int	x;
	unsigned short int	y;
	unsigned short int 	size;
	int					color;
}						t_square;

typedef struct s_player
{
	int px;
	int py;
	int color;
}		t_player;



#endif