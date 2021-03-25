/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apita-da <apita-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:42:05 by apita-da          #+#    #+#             */
/*   Updated: 2021/03/14 12:10:46 by apita-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFFER_SIZE 42
# define NONE 0xFF000000
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define MAGENTA 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFF
# define KEY_UP_W 13
# define KEY_UP_ARR 126
# define KEY_DOWN_S 1
# define KEY_DOWN_ARR 125
# define KEY_LEFT_A 0
# define KEY_LEFT_ARR 123
# define KEY_RIGHT_D 2
# define KEY_RIGHT_ARR 124
# define KEY_MOV_LEFT_Q 12
# define KEY_MOV_RIGHT_E 14
# define KEY_RUN 7
# define KEY_SLOW 6

typedef struct	s_img
{
	void		*img_ptr;
	char		*addr;
	int			*data;
	int			bpp;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct	s_map
{
	char		**mapa;
	char		*line;
	char		*parse;
	char		*tfile;
	int			fd;
	int			res_x;
	int			res_y;
	int			num_line;
	int			len;
	double		pos_x;
	double		pos_y;
	char		face;
	int			cel_colors;
	int			flo_colors;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			num_sprite;
}				t_map;

typedef struct	s_ray
{
	int			x;
	int			wall;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			map_x;
	int			map_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	double		speed;
	int			tex_color;
	int			tex_y;
	int			tex_x;
	double		wall_x;
	double		wall_y;
	double		tex_pos;
	double		step;
	double		rotspeed;
	double		olddir_x;
	double		oldplane_x;
}				t_ray;
typedef struct	s_mov
{
	int			key_w;
	int			key_s;
	int			key_a;
	int			key_d;
	int			key_q;
	int			key_e;
	int			key_x;
	int			key_z;
}				t_mov;
typedef struct	s_spr
{
	void		*spr_ptr;
	int			*data;
	int			bpp;
	int			spr_size;
	int			endian;
	double		*spr_x;
	double		*spr_y;
	double		sprite_x;
	double		sprite_y;
	int			spr_wi;
	int			spr_he;
	int			color;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			drawstarty;
	int			drawendy;
	int			drawstartx;
	int			drawendx;
	int			stripe;
	int			tex_x;
	int			tex_y;
	float		*zbuffer;
	double		spritedist;
}				t_spr;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			c;
}				t_color;

typedef struct	s_big
{
	t_img		img;
	t_img		tex[4];
	t_mlx		mlx;
	t_map		map;
	t_ray		ray;
	t_mov		mov;
	t_spr		spr;
	t_color		color;
	int			save;
	int			check;
	int			c_map;
	int			player;
	int			i;
}				t_big;

void			hooks(t_big *big);
void			init(t_big *big);
void			init_map(t_big *big);
void			init_game(t_big *big);
void			init_mov(t_big *big);
void			init_ray(t_big *big);
void			init_ray2(t_big *big);
void			init_spr(t_big *big);
void			initial_pos(t_big *big);
void			pos_init(t_big *big);
int				cont_spr(char *parse);
t_map			*readmap(t_big *big, char *file);
int				get_lines(t_big *big, char *line);
void			get_lines0(t_big *big, char *line);
int				get_mapa(t_big *big, char *line);
char			*parse_map(t_big *big, char *line);
void			check_caracteres(t_big *big);
void			check_close_map(t_big *big);
void			make_square(t_big *big);
void			change_char(t_big *big);
int				valid_map(t_big *big);
void			floodfill(int x, int y, t_big *big);
void			fill_map(t_big *big);
void			get_map(t_big *big);
void			parse_sprites(t_big *big);
int				error_sprite(t_big *big);
int				get_sprites(t_big *big);
void			tmp(t_big *big, int i, int j);
void			sort_spr(t_big *big);
void			get_resolution(t_big *big);
char			text_north(t_big *big, char *line);
char			text_south(t_big *big, char *line);
char			text_west(t_big *big, char *line);
char			text_east(t_big *big, char *line);
char			text_sprite(t_big *big, char *line);
void			colors_flo(t_big *big, char *line);
void			colors_cel(t_big *big, char *line);
int				get_params(t_big *big);
void			print_textura(t_big *big, int i);
void			get_texture(t_big *big);
void			get_spr_tex(t_big *big);
int				raycasting(t_big *big);
void			draw_map(t_big *big);
void			calc_wall(t_big *big);
void			calc_ray_hit(t_big *big);
void			calc_step(t_big *big);
void			spr_raycasting(t_big *big);
void			calc_drawstartend(t_big *big);
void			calc_transform(int i, t_big *big);
void			write_sprites(t_big *big);
void			verline_sprites(t_big *big);
void			openwin(t_big	*big);
int				main(int ac, char **av);
int				game(t_big *big);
int				error(char *error);
void			map_error(char *error);
int				exitwin(t_big *big);
int				key_release(int keycode, t_big *big);
int				key_press(int keycode, t_big *big);
void			move_down(t_big *big);
void			move_up(t_big *big);
void			move_right_left(t_big *big);
void			move_rot_r(t_big *big);
void			move_rot_l(t_big *big);
void			movement(t_big *big);
void			bmp_image(t_big *big, int fd);
void			save_bmp(t_big *big);
void			bmp_header(t_big *big, int fd);
void			my_mlx_pixel_put(t_big *data, int x, int y, int color);
int				intlen(int i);
int				get_next_line(int fd, char **line);
char			*ft_strchr(const char *str, int c);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
int				rgb_int(int red, int green, int blue);
char			check_blanks(char *strs);
char			**ft_split(char const *s, char c);
char			*str_join(char *buf, char *add);
void			ft_bzero(void *str, size_t nb);
void			*ft_memset(void *str, int c, size_t nb);
char			*ft_strdup(const char *s1);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isdigit(int c);
int				check_comas(char *str);
void			check_chars(char *line);
int				valid_coma(char *line, int i);
void			print_mapa(t_big *big);
int				get_color(char *line, t_big *big);
void			check_line(t_big *big);
void			replace_sprites(t_big *big);
#endif
