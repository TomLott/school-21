#ifndef CUB_CUB_H
#define CUB_CUB_H
# include "../libft/libft.h"
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
#include "../minilibx_mms_20200219/mlx.h"
# include <math.h>
# define OK 42
# define SCALE 10
# define MOVESPEED 2
# define TANGLE 0.3
# define MOVE_SCR 64.0

typedef struct s_sprite
{
	int x;
	int y;
	int ord;
	double dist;
}				t_sprite;

typedef struct s_win
{
	void *mlx_ptr;
	void *win;
	int x;
	int y;
}				t_win;

typedef struct s_img
{
	void *addr;
	void *img;
	int bits_per_pixel;
	int line_length;
	int endian;
}				t_img;

typedef struct s_ray
{
	double x;
	double y;
	int hit;
	int n;
	int side;
}				t_ray;
/*
typedef struct s_hit
{
	double x;
	double y;
}				t_hit;*/

typedef struct s_map
{
	int x;
	int y;
	char **table;
	int sprite;
	int counter;
	int line_num;

}				t_map;

typedef struct s_err
{
	int n;
	int x;
}				t_err;

typedef struct s_dist
{
	double side_x;
	double side_y;
	double delta_x;
	double delta_y;
	double wall_dist;
	double step_x;
	double step_y;
}				t_dist;

typedef struct s_pl
{
	double x;
	double y;
	char symbol;
	double dir_x;
	double dir_y;
	double start;
	double end;
}				t_pl;

typedef struct s_tex
{
	unsigned int f;
	unsigned int c;
	int x;
	int y;
	unsigned int *addr;
	void *img;
	int bits_per_pixel;
	int line_length;
	int endian;
	double pos_x;
	double pos_y;
	int sprite;
	double dist;
	double inv;
	double tr_x;
	double tr_y;
	int sp_scr_x;
	int hig;
	int wid;
	int start_x;
	int end_x;
	int start_y;
	int end_y;
	double *sp_buf;
	int tex_x;
	int tex_y;
}				t_tex;

typedef struct s_tex_n
{
	unsigned int *addr;
	void *img;
	int x;
	int y;
	int bits_per_pixel;
	int line_length;
	int endian;
	int pos_x;
	int pos_y;

}				t_tex_n;

typedef struct s_tex_s
{
	unsigned int *addr;
	void *img;
	int x;
	int y;
	int bits_per_pixel;
	int line_length;
	int endian;
	int pos_x;
	int pos_y;
}				t_tex_s;

typedef struct s_tex_e
{
	unsigned int *addr;
	void *img;
	int x;
	int y;
	int bits_per_pixel;
	int line_length;
	int endian;
	int pos_x;
	int pos_y;
}				t_tex_e;

typedef struct s_tex_w
{
	unsigned int *addr;
	void *img;
	int x;
	int y;
	int bits_per_pixel;
	int line_length;
	int endian;
	int pos_x;
	int pos_y;
}				t_tex_w;

typedef struct s_cam
{
	double 	x;
	double	y;
	double	plane_y;
	double	plane_x;
	double	posX;
	double	posY;
	int		map_x;
	int		map_y;
	int		i;
}				t_cam;

typedef struct	s_hight
{
	int hight;
	int start;
	int end;
	int h;
	int tex_num;
	double wall_x;
	int tex_x;
	int j; /** for floor**/
}				t_hight;

typedef struct s_all
{
	t_win	win;
	t_map	map;
	t_pl	pl;
	t_err	err;
	t_tex	tex;
	t_ray	ray;
//	t_hit	hit;
	t_img	img;
	t_cam	cam;
	t_dist	dist;
	t_tex_e tex_e;
	t_tex_n tex_n;
	t_tex_s tex_s;
	t_tex_w tex_w;
	t_sprite *sp;
	int 	flag;
	int		save;
}				t_all;

int	file_format(char *s, char *format);
int ft_work(char *arg, int i, t_all *all);
void ft_start(char *arg, int i);
int ft_parse(char *arg, t_all *all);
int	ft_isspace(char *line, int *i);
int	file_format(char *s, char *format);
int	ft_map(t_all *all, char *line, int *i);
int ft_errormessage(int i);
int ft_colour(char *line, int *i, t_all *all);
int ft_check_map(t_all *all);
void ft_free(char **s);
int zero_check(char **table, int i, int j);
int map_ok(int i, int j, t_all *a);
int	ft_stringlen(t_all *all, char *line);
void ft_purgatorium(t_all *all, t_list **head);
int ft_player_parser(t_all *all, int i);
void ft_checking_each(char **table, t_all *all);
int line_parse(char *line, t_all *all);
void ft_begining_all(t_all *all, int save);
void ft_rays_hits(t_all *all);
void ft_screen(t_all *all);
void ft_draw_screen(t_all *all);
void ft_floor(t_all *all, t_cam *c, t_dist *d, t_hight *hig);
int ft_texture_w(t_all *all, char *line, int *i, t_tex_w *n);
int ft_texture_e(t_all *all, char *line, int *i, t_tex_e *n);
int ft_texture_s(t_all *all, char *line, int *i, t_tex_s *n);
int ft_texture_n(t_all *all, char *line, int *i, t_tex_n *n);
int ft_texture(t_all *all, char *line, int *i, t_tex *n);
void ft_wallcast_n(t_all *all, t_cam *c, t_tex_n *n, t_hight *h);
void ft_wallcast_e(t_all *all, t_cam *c, t_tex_e *n, t_hight *h);
void ft_wallcast_s(t_all *all, t_cam *c, t_tex_s *n, t_hight *h);
void ft_wallcast_w(t_all *all, t_cam *c, t_tex_w *n, t_hight *h);
void ft_sprite(t_all *all, t_dist *d, t_cam *c);
void	ft_lstadd_back_sp(t_sprite **lst, t_sprite *new);
t_sprite *ft_lstnew_sp(int x, int y);
t_sprite	*ft_lstlast_sp(t_sprite *lst);
void ft_cam_plane(t_all *all, t_cam *c);
void ft_spr_cast(t_sprite *sp, t_all *a, t_tex *t);
void ft_screenshot(t_all *all);
void close_prog(t_all *all);

#endif //CUB_CUB_H
