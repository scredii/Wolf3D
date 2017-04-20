/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourgeu <abourgeu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 11:06:15 by abourgeu          #+#    #+#             */
/*   Updated: 2017/04/06 11:25:33 by abourgeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_read_map(char *av)
{
	int			ret;
	int			fd;
	char		*map;
	char		buf[BUFF_SIZE + 1];

	if (!(map = (char*)malloc(sizeof(char))))
		return (NULL);
	map[0] = '\0';
	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		if (!(map = ft_strjoinfree(map, buf, 1, 0)))
			return (NULL);
	}
	close(fd);
	return (map);
}
