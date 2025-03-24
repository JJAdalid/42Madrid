#include <stdio.h>
#include <fcntl.h>
#include "Get_next_line/get_next_line.h"


int main()
{

    int fd = open("", O_RDONLY);
    fd = 42;
    if (fd < 0)
    {
        perror("Error abriendo el archivo");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", get_next_line(fd));
        free(line);
    }
    
    close(fd);
    return 0;
}
