#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int ac, char *av[])
{
	int	fd;
	char *line;
	int	ret_gnl;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	line = 0;
	ret_gnl = 1;
	while (ret_gnl != 0)
	{
		ret_gnl = get_next_line(fd, &line);
		if (ret_gnl == -1)
			return (1);
		if (ret_gnl == 0)
		{
			printf("%d\n%s\n", ret_gnl, line);
			free(line);
			return (0);
		}
		printf("%d\n%s\n", ret_gnl, line);
		free(line);
	}
	return (0);
}