#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int fd = open("abc", O_RDONLY);

	if (fd == -1)
	{
		perror("abc");
	}
	close(fd);
	return (0);
}