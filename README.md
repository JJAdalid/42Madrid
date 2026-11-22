# 42 Madrid — Common Core

Repositorio con los proyectos desarrollados durante el Cursus de **42 Madrid** (Fundación Telefónica). Todos los proyectos están escritos en **C** siguiendo estrictamente la normativa de estilo de la escuela (*Norminette*) y compilados sin fugas de memoria.

---

## Proyectos

| Proyecto | Descripción | Conceptos clave |
| :--- | :--- | :--- |
| **[Libft](./Libft)** | Recreación desde cero de funciones estándar de la biblioteca de C (`libc`), además de utilidades adicionales para manipulación de cadenas, memoria y listas enlazadas. | Gestión de memoria dinámica (`malloc`/`free`), punteros, aritmética de punteros, estructuras de datos y creación de librerías estáticas (`.a`). |
| **[ft_printf](./Ft_printf)** | Reimplementación de la función `printf()` de la librería estándar `stdio.h`, soportando las conversiones `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` y `%`. | Funciones variádicas (`va_list`, `va_start`, `va_arg`, `va_end`), formateo de cadenas y conversión de bases numéricas. |
| **[get_next_line](./Get_next_Line)** | Función capaz de leer y devolver una línea completa cada vez desde un descriptor de archivo (*file descriptor*), gestionando lecturas sucesivas hasta el final del archivo. | Variables estáticas (*static variables*), manipulación de *buffers*, lectura de archivos (`read`) y prevención de *memory leaks*. |

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

---

## Compilación y uso

Cada directorio incluye su propio `Makefile` con las reglas estándar (`all`, `clean`, `fclean`, `re`). Para compilar cualquiera de los proyectos:

```bash
cd Libft
make
