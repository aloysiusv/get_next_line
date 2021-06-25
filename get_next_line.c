/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrandria <lrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 23:02:05 by lrandria          #+#    #+#             */
/*   Updated: 2021/06/23 20:39:17 by lrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(int fd, char **stock)
{
	char	buf[BUFFER_SIZE + 1];
	int		nbytes;
	char	*tmp;

	nbytes = 1;
	while (nbytes != 0)
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes == -1)
			return (-1);
		buf[nbytes] = 0;
		if (*stock == 0)
			*stock = ft_strdup(buf);
		else
		{
			tmp = *stock;
			*stock = ft_strjoin(tmp, buf);
			free(tmp);
		}
		if (*stock == NULL)
			return (-1);
		if (ft_strchr(*stock, '\n') != 0)
			break ;
	}
	return (1);
}

int	create_one_line(char **line, char **stock)
{
	char	*tmp;
	size_t	line_size;

	if (ft_strchr(*stock, '\n') == 0)
	{
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = 0;
		if (*line == NULL)
			return (-1);
		return (0);
	}
	else
	{
		line_size = ft_strclen(*stock, '\n');
		*line = ft_substr(*stock, 0, line_size);
		tmp = *stock;
		*stock = ft_strdup(*stock + line_size + 1);
		free(tmp);
		if (*line == NULL || *stock == NULL)
			return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char		*stock;
	int				read_status;
	
	read_status = read_file(fd, &stock);
	if (read_status == -1)
		return (-1);
	if (read_status == 0 && stock == 0)
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (-1);
		return (0);
	}
	return (create_one_line(line, &stock));
}

// #include <stdio.h>
// #include <fcntl.h>

// int	main(int ac, char *av[])
// {
// 	int	fd;
// 	char *line;
// 	int	ret_gnl;

// 	if (ac != 2)
// 		return (1);
// 	fd = open(av[1], O_RDONLY);
// 	line = 0;
// 	ret_gnl = 1;
// 	while (ret_gnl != 0)
// 	{
// 		ret_gnl = get_next_line(fd, &line);
// 		if (ret_gnl == -1)
// 			return (1);
// 		if (ret_gnl == 0)
// 		{
// 			printf("%d\n%s\n", ret_gnl, line);
// 			free(line);
// 			return (0);
// 		}
// 		printf("%d\n%s\n", ret_gnl, line);
// 		free(line);
// 	}
// 	return (0);
// }
