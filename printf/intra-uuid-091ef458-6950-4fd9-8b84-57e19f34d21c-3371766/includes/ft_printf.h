/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:50:52 by itollett          #+#    #+#             */
/*   Updated: 2020/11/30 18:56:52 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	char		flag;
	int			width;
	int			pres;
	int			len;
	int			flag_len;
	int			width_len;
	int			pres_len;
	int			pres_exist;
	int			minus;
	int			digit_len;
}				t_list;

char			ft_flags(const char *str, t_list *temp);
int				ft_width(const char *str, va_list factor, t_list *temp);
int				ft_pres(const char *str, va_list factor, t_list *temp);
size_t			ft_strlen(const char *string);
char			*ft_strdup(const char *s1);
void			ft_choise(const char *s, int i, va_list factor, t_list *temp);
int				ft_work(va_list factor, const char *s, t_list *opt);
int				ft_printf(const char *s, ...);
int				ft_strlen_int(int num);
int				ft_len(t_list *temp);
int				ft_print_str(t_list *list, va_list factor);
int				ft_putchar_arg(const char *s, va_list factor, t_list *opt);
int				ft_print_int(t_list *list, va_list factor);
int				ft_print_c(t_list *list, va_list factor);
int				ft_print_x(t_list *list, va_list factor, char x);
void			ft_putchar_fd(char c, int fd, t_list *l);
int				ft_print_p(t_list *list, va_list factor);
int				ft_print_u(t_list *list, va_list factor);
int				ft_common_print(const char *s);
int				ft_check(const char s);
int				ft_num_zero(t_list *list, int printed);
int				ft_check_pres(const char s, t_list *list);
int				ft_print_percent(t_list *l);
void			ft_restart(t_list *options);

#endif
