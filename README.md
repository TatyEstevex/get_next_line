*This project has been created as part of the 42 curriculum by tde-alme.*

# get_next_line

## Description

`get_next_line` is a C function that reads and returns one line at a time from any file descriptor — a file, standard input, or a network socket. Each successive call picks up exactly where the last one left off, until the file descriptor is exhausted or an error occurs.

**Goal:** implement a reliable, memory-safe line reader that works correctly for any `BUFFER_SIZE` value (1 byte up to tens of thousands), across multiple file descriptors, without leaking memory.

**Prototype:**
```c
char *get_next_line(int fd);
```

Returns the next line (newline character included when present), or `NULL` on end-of-file or error. The caller owns the returned string and must free it.

**Project files:**

| File | Role |
|------|------|
| `get_next_line.c` | Core function + `ft_extract` helper |
| `get_next_line_utils.c` | `ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_substr` |
| `get_next_line.h` | Header — prototypes and `BUFFER_SIZE` macro |

---

### Algorithm

The function uses a static variable (stash) to persist unread data between calls. On each call, it reads from the file descriptor in chunks of BUFFER_SIZE bytes, appending each chunk to the stash until a newline is found or the file ends. Once a newline is present, ft_extract splits the stash: everything up to and including \n is returned to the caller, and the remainder stays in the stash for the next call. If no newline is found before EOF, the remaining stash is returned as-is.

This approach is correct for any buffer size — a BUFFER_SIZE of 1 or 100 000 produces identical output — and avoids reading the same byte twice. The static stash is freed and set to NULL on EOF or error, leaving no memory leaks between calls.

## Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
   get_next_line.c get_next_line_utils.c -o gnl
```

`BUFFER_SIZE` can be any positive integer. If not specified at compile time, define a default in `get_next_line.h`.

### Integration into another project

Add both `.c` files and the header to your project and include the header:

```c
#include "get_next_line.h"
```

### Example program

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

### Memory check

```bash
valgrind --leak-check=full ./gnl
```

## Resources

### Documentation & references

- [Linux `read(2)` man page](https://man7.org/linux/man-pages/man2/read.2.html) — the system call at the core of this project
- [Linux `open(2)` man page](https://man7.org/linux/man-pages/man2/open.2.html) — file descriptor creation
- [C static variables — cppreference](https://en.cppreference.com/w/c/language/storage_duration) — explains why `static` persists between calls
- Conversation with peers

### AI usage

Claude (Anthropic) was used during this project for **debugging only** — specifically to diagnose a segmentation fault caused by writing to a null pointer (`stash = NULL` instead of `*stash = NULL` inside `ft_extract`) and a double-free in the no-newline return path of `get_next_line`. The algorithm design, implementation, and all written code are the author's own work.