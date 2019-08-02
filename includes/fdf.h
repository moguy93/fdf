/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moguy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 17:54:10 by moguy             #+#    #+#             */
/*   Updated: 2019/02/14 05:28:05 by moguy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include "../libft/libft.h"

# define WIDTH 1400
# define HEIGTH 1000
# define PM ((t_pack*)pack)->map
# define PT ((t_pack*)pack)->tmp
# define PT2 ((t_pack*)pack)->tmp2
# define PX ((t_pack*)pack)->mlx
# define PS ((t_pack*)pack)->size
# define PRX ((t_pack*)pack)->rotat_x
# define PRY ((t_pack*)pack)->rotat_y
# define PRZ ((t_pack*)pack)->rotat_z
# define PC ((t_pack*)pack)->coord
# define PC1 ((t_pack*)pack)->coord1
# define PC2 ((t_pack*)pack)->coord2
# define SX size->speed_x
# define SY size->speed_y
# define SZ size->speed_z

typedef struct		s_size
{
	int				size_l;
	int				size_c;
	int				px;
	int				py;
	int				decal_x;
	int				decal_y;
	int				hmin;
	double			hrmin;
	int				hmax;
	double			hrmax;
	int				color_switch;
	double			speed_x;
	double			speed_y;
	double			speed_z;
}					t_size;

typedef struct		s_map
{
	int				heigth;
	int				color;
	double			x;
	double			y;
}					t_map;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				h;
	int				dx;
	int				dy;
	int				db;
	int				dr;
	int				dv;
	int				dc;
	int				coltmp;
	int				xinc;
	int				yinc;
	int				color;
	double			ddr;
	double			ddv;
	double			ddb;
}					t_coord;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*data;
	int				siz;
	int				end;
	int				bpp;
	int				*depth;
	double			scale;
}					t_mlx;

typedef struct		s_pack
{
	struct s_map	**map;
	struct s_map	**tmp;
	struct s_map	**tmp2;
	struct s_mlx	*mlx;
	struct s_size	*size;
	struct s_coord	*coord;
	struct s_coord	*coord1;
	struct s_coord	*coord2;
}					t_pack;

t_size				*ft_count_and_check(char *argv);

t_map				**ft_get_map(char *argv, t_size *size);

t_map				**ft_map_copy(t_map **map, t_size *size);

int					ft_is_hexa(char c);

int					ft_convert_color(char *color);

int					draw_line(t_mlx *mlx, t_coord *coord1, t_coord *coord2);

int					deal_key(int key, void *param);

void				ft_reaff_map(t_map **map, t_mlx *mlx, t_size *size);

void				ft_aff_map(t_map **map, t_mlx *mlx, t_size *size);

void				fill_pixel(char *data, t_coord *coord, t_mlx *mlx,
																	int color);

void				ft_text(t_mlx *mlx, t_size *size);

void				deal_decal(int key, void *pack);

void				deal_rotate(int key, void *pack);

void				ft_color_line(t_coord *coord1, t_coord *coord2, int i);

void				ft_free_map(t_map **map, t_size *size);

void				ft_free_coord(t_coord *coord);

void				init_rotation(t_pack *pack);

void				ft_rotate(t_map *map, t_size *size, int axe);

void				ft_change(t_pack *pack);

void				ft_change_white(t_map **map, t_map **tmp, t_size *size);

void				ft_change_blue(t_map **map, t_map **tmp, t_size *size);

void				ft_change_green(t_map **map, t_map **tmp, t_size *size);

void				ft_change_red(t_map **map, t_map **tmp, t_size *size);

void				ft_error(void);

void				ft_usage(void);

#endif
