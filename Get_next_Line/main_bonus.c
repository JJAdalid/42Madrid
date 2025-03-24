#include <stdio.h>
#include <fcntl.h>
#include "Get_next_line/get_next_line.h"

int main(int argc, char **argv)
{
    if (argc < 2) // ✅ Ahora permite varios archivos
    {
        printf("Uso: %s <archivo1> [archivo2] ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) // ✅ Bucle para leer varios archivos
    {
        printf("\n📂 Leyendo archivo: %s\n", argv[i]);

        int fd = open(argv[i], O_RDONLY);
        if (fd < 0)
        {
            perror("Error abriendo el archivo");
            continue; // ❌ No salir, seguir con el siguiente archivo
        }

        char *line;
        int line_count = 0;
        while ((line = get_next_line(fd)))
        {
            printf("[%d]: %s", line_count++, line);
            free(line);
        }

        close(fd);
    }

    return 0;
}