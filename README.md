# 42 Madrid — Common Core

Repositorio con los proyectos desarrollados durante el Cursus de **42 Madrid** (Fundación Telefónica). Todos los proyectos están escritos en **C** siguiendo estrictamente la normativa de estilo de la escuela (*Norminette*) y compilados sin fugas de memoria.

---

## Proyectos

| Proyecto | Descripción | Conceptos clave |
| :--- | :--- | :--- |
| **[Libft](https://github.com/JJAdalid/JJAdalid/tree/master/Libft)** | Recreación desde cero de funciones estándar de la biblioteca de C (`libc`), además de utilidades adicionales para manipulación de cadenas, memoria y listas enlazadas. | Gestión de memoria dinámica (`malloc`/`free`), punteros, aritmética de punteros, estructuras de datos y creación de librerías estáticas (`.a`). |
| **[ft_printf](https://github.com/JJAdalid/JJAdalid/tree/master/Ft_printf)** | Reimplementación de la función `printf()` de la librería estándar `stdio.h`, soportando las conversiones `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` y `%`. | Funciones variádicas (`va_list`, `va_start`, `va_arg`, `va_end`), formateo de cadenas y conversión de bases numéricas. |
| **[get_next_line](https://github.com/JJAdalid/JJAdalid/tree/master/Get_next_Line)** | Función capaz de leer y devolver una línea completa cada vez desde un descriptor de archivo (*file descriptor*), gestionando lecturas sucesivas hasta el final del archivo. | Variables estáticas (*static variables*), manipulación de *buffers*, lectura de archivos (`read`) y prevención de *memory leaks*. |
| **[so_long](https://github.com/JJAdalid/JJAdalid/tree/master/So_long)** | Desarrollo de un videojuego 2D sencillo con vista cenital utilizando la librería gráfica `MiniLibX`, donde el jugador debe recoger todos los objetos del mapa y alcanzar la salida. | Programación gráfica básica, gestión de eventos (*hooks* de teclado y ventana), renderizado de *sprites* y validación de mapas mediante algoritmos de búsqueda de caminos (*flood fill*). |

---

## Detalles de cada proyecto

### 1. Libft
Primer proyecto del cursus. Consiste en construir una librería propia en C que servirá como base para el resto de entregas de 42.
* **Funciones de `libc`:** `isalpha`, `isdigit`, `memset`, `memcpy`, `strlcpy`, `strchr`, `strncmp`, `atoi`, `calloc`, `strdup`, entre otras.
* **Funciones adicionales:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_putstr_fd`, etc.
* **Bonus (Listas enlazadas):** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

### 2. ft_printf
Implementación modular de salida formateada por consola sin recurrir a la gestión de *buffer* original de `printf`.
* Manejo de distintos tipos de datos mediante argumentos variables.
* Conversión y representación de direcciones de memoria en hexadecimal (`%p`) y enteros sin signo (`%u`, `%x`, `%X`).

### 3. get_next_line
Desarrollo de una función con el prototipo `char *get_next_line(int fd);` que permite leer archivos de texto línea por línea independientemente del tamaño definido en `BUFFER_SIZE`.
* Persistencia de datos residuales entre llamadas mediante memoria estática.
* Soporte para lectura desde entrada estándar (`stdin`) y múltiples descriptores de archivo simultáneos (parte bonus).

### 4. so_long
Primer proyecto gráfico del cursus desarrollado con `MiniLibX`. El programa recibe como argumento un mapa en formato `.ber` y genera la ventana interactiva correspondiente.
* **Parseo y validación:** Comprobación de muros cerrados, forma rectangular, presencia de elementos obligatorios y verificación de ruta válida (*flood fill*) hacia todos los coleccionables y la salida.
* **Interactividad y renderizado:** Movimiento del personaje por turnos, conteo de pasos en terminal o pantalla y liberación limpia de imágenes y ventanas al cerrar el juego.

---

## Compilación y uso

Cada directorio incluye su propio `Makefile` con las reglas estándar (`all`, `clean`, `fclean`, `re`). Para compilar cualquiera de los proyectos:

```bash
cd Libft
make
