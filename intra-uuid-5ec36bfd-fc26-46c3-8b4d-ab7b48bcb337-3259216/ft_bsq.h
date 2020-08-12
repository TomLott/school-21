/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaryn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 10:06:38 by acaryn            #+#    #+#             */
/*   Updated: 2020/08/12 10:06:42 by acaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	*g_characters;
void	ft_free(char *str1, char **str2, int att);
int		error(void);
void	ft_print(int **temp, int row, int column);
int		**ft_change(int **temp, int maxi, int maxj, int maxs);
int		max(int **t, int row, int column, int i);
void	find(int row, int column, int i, int **t2);
int		ft_final_check(char *buff);
int		ft_atoi(char *buff);
int		ft_charact_check(char *row);
int		ft_valid(char *temp);
int		*ft_strdupint(char *row, int column, int *mas);
int		**ft_translate(int row, int column, char **massive);
void	ft_defining(char *buff, int j);
char	*ft_strdup(char *src, int k);
int		ft_massive(int att, char *buff, int j, int k);
int		ft_strlenspecial(char *buff);
char	*ft_read(char *argv);
char	*ft_read_file(char *argv);
int		ft_create_massive(char *argv, int att);
#endif
