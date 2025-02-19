#include <stdio.h>
#include <fcntl.h>
#include "Get_next_line/get_next_line.h"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Error abriendo el archivo");
        return 1;
    }

    char *line;
    int line_count = 0; // Contador de líneas para detectar bucles infinitos
    while ((line = get_next_line(fd)))
    {
        printf("[%d]: %s", line_count++, line);
        free(line);

        // Si el número de líneas es sospechosamente alto, detener para evitar crash
        if (line_count > 1000)
        {
            printf("⚠️  Error: posible bucle infinito en get_next_line\n");
            break;
        }
    }

    close(fd);
    return 0;
}
