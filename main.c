#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main()
{
	int fd;
    char *line;
    int i;

	fd = open("test.txt", O_RDONLY);
    while ((i = get_next_line(fd, &line)) > 0)
    {
		printf("%s\n", line);
		printf("%d\n", i);
		free(line);
    }
    printf("%s\n", line);
    printf("%d\n", i);
    close(fd);
    system("leaks a.out");
    return (0);
}