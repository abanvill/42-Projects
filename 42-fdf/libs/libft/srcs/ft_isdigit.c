/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abanvill <abanvill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 18:24:55 by abanvill          #+#    #+#             */
/*   Updated: 2015/01/28 18:24:55 by abanvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}