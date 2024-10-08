/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuo <ykuo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:13:30 by ykuo              #+#    #+#             */
/*   Updated: 2022/11/13 16:13:31 by ykuo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*get_icon_name(int type)
{
	if (type == CAM)
		return ("./images/cam_icon.xpm");
	if (type == AMB)
		return ("./images/amb_icon.xpm");
	if (type == LIGHT)
		return ("./images/light_icon.xpm");
	if (type == SP)
		return ("./images/sp_icon.xpm");
	if (type == PL)
		return ("./images/pl_icon3.xpm");
	if (type == CY)
		return ("./images/cy_icon.xpm");
	if (type == CO)
		return ("./images/co_icon.xpm");
	return (NULL);
}

void	init_icons(t_data *d)
{
	int		i;
	char	*img_name;

	i = 0;
	while (i < d->nbr_objs)
	{
		d->objs[i].icon.w = 80;
		d->objs[i].icon.h = 80;
		img_name = get_icon_name(d->objs[i].type);
		if (!img_name)
			print_err("mlx_img icon error", d);
		d->objs[i].icon.mlx_img = mlx_xpm_file_to_image(d->mlx_ptr, \
		img_name, &d->objs[i].icon.w, &d->objs[i].icon.h);
		if (!d->objs[i].icon.mlx_img)
			print_err("mlx_img icon error", d);
		d->objs[i].icon.addr = \
		mlx_get_data_addr(d->objs[i].icon.mlx_img, &d->objs[i].icon.bpp, \
		&d->objs[i].icon.line_len, &d->objs[i].icon.endian);
		if (d->objs[i].type != CAM)
			paint_image(&d->objs[i].icon, encode_rgb(d->objs[i].color), \
			WHITE);
		i++;
	}
}

int	init_mlx(t_data *d)
{
	d->mlx_ptr = mlx_init();
	if (!d->mlx_ptr)
		print_err("Failed init window.", d);
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "miniRT");
	if (!d->win_ptr)
		print_err("Failed to launch window.", d);
	d->img.mlx_img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	if (!d->img.mlx_img)
		print_err("mlx new image error", d);
	d->img.addr = mlx_get_data_addr(d->img.mlx_img, &d->img.bpp,
			&d->img.line_len, &d->img.endian);
	d->menu_back.mlx_img = mlx_new_image(d->mlx_ptr, WIDTH, GUI_HEIGHT);
	if (!d->menu_back.mlx_img)
		print_err("mlx new image error", d);
	d->menu_back.addr = mlx_get_data_addr(d->menu_back.mlx_img, \
	&d->menu_back.bpp, &d->menu_back.line_len, &d->menu_back.endian);
	init_icons(d);
	return (0);
}

void	draw_imgs(t_data *d)
{
	int		i;
	int		j;

	ft_bzero(d->img.addr, d->img.line_len * HEIGHT);
	i = 0;
	while (i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			img_pix_put(&d->img, j, i, ray_tracing(d, j, i));
		i++;
	}
	d->img_changed = 1;
}

int	render_frame(t_data *d)
{
	if (d->win_ptr == NULL)
		return (1);
	if (d->img_changed == 1)
	{
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img.mlx_img, 0, 0);
		if (d->display_gui == 1)
			draw_gui(d);
		else
		{
			mlx_putstr(d, 10, HEIGHT - 10, \
			"Press N to hide the object");
			mlx_putstr(d, WIDTH / 2 - 70, HEIGHT - 10, \
			"Press M to hide the menu");
			mlx_putstr(d, WIDTH - 158, HEIGHT - 10, \
			"Press P to save the scene");
		}
		d->img_changed = 0;
	}
	return (0);
}
