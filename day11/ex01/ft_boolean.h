/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itollett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 10:11:56 by itollett          #+#    #+#             */
/*   Updated: 2020/08/01 20:09:39 by itollett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_BOOLEAN_H
# define __FT_BOOLEAN_H

# include <unistd.h>
# define ODD_MSG "I have an odd number of arguments.\n"
# define EVEN_MSG "I have an even number of arguments.\n"
# define FALSE 0
# define SUCCESS 0
# define TRUE 1
# define EVEN even

typedef unsigned short t_bool;

t_bool	even(int nbr)
{
	if (nbr % 2 == 0)
		return (FALSE);
	else
		return (TRUE);
}
#endif
