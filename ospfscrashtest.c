#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include "ospfs.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		printf("usage: %s filename nwrites_to_crash", argv[0]);
		return -1;
	}
	
	int fd;
	fd = open("test/foobar", O_RDONLY | O_CREAT, 0666);
	if (fd == -1) {
		printf("Error in opening file.\n");
		return -1;
	}
	int arg = atoi(argv[1]);
	int retval = ioctl(fd, OSPFS_IOCTL_CMD, arg);
	if (retval == -1)
		printf("Error...\n");
	close(fd);
}

