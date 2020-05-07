#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>
int main(int argc, char **argv)
{
    int ret;
    int fd;
    char *line;
    int val;

    fd = open("test.txt", O_RDONLY);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%s\n",line);
        free(line);
    }
    free(line);
}