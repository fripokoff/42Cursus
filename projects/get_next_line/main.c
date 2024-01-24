#include "get_next_line.h"
#include <stdio.h>


int		main(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("1.txt", O_RDONLY);
	if (fd == -1)
		return(0);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
