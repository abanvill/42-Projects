/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 14:07:34 by abanvill          #+#    #+#             */
/*   Updated: 2015/01/31 14:07:34 by abanvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_isprint(int c)
{
	return (c > 31 && c < 127);
}
