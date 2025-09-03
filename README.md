# Get Next Line

A C function that reads a file line by line, implementing efficient memory management and static variable usage.

## 📋 Overview

**get_next_line** is a 42 School project that challenges you to implement a function that returns one line at a time from a file descriptor. The function must handle multiple consecutive calls, manage memory efficiently, and work with any buffer size.

## ✨ Features

- **Line-by-line reading**: Read files one line at a time without loading everything into memory
- **Memory efficient**: Minimal memory usage with proper cleanup
- **Configurable buffer**: Works with any `BUFFER_SIZE` from 1 to very large values
- **Error handling**: Robust handling of invalid file descriptors and edge cases
- **Static variables**: Uses static variables to maintain state between function calls

## 🛠️ Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters
- `fd`: The file descriptor to read from

### Return Value
- **On success**: A string containing the next line (including `\n` if present)
- **On failure/EOF**: `NULL`

## 🏗️ Compilation

```bash
# Basic compilation with your main file
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c

# Test with different buffer sizes
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c your_main.c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c your_main.c
```

## 📂 Project Structure

```
get_next_line/
├── get_next_line.c           # Main function implementation
├── get_next_line_utils.c     # Helper functions (ft_strlen, ft_strjoin, etc.)
└── get_next_line.h           # Header file with prototypes
```

## 🚀 Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;
    
    if (fd == -1) {
        printf("Error opening file\n");
        return 1;
    }
    
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line: %s", line);
        free(line);
    }
    
    close(fd);
    return 0;
}
```

## 🧪 Testing

The function handles various edge cases and scenarios:

- ✅ Standard multi-line files
- ✅ Files ending without newline
- ✅ Empty files
- ✅ Single character files  
- ✅ Very long lines
- ✅ Files with empty lines
- ✅ Invalid file descriptors
- ✅ Various buffer sizes (1, 42, 9999, 10000000)

### Create Your Own Test

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    char *line;
    int line_count = 0;
    
    while ((line = get_next_line(fd)) != NULL) {
        printf("Line %d: [%s]", ++line_count, line);
        free(line);
    }
    
    close(fd);
    printf("Total lines read: %d\n", line_count);
    return 0;
}
```

## 🔧 Technical Implementation

### Core Algorithm
1. **Static buffer management**: Uses static variables to maintain state between calls
2. **Dynamic memory allocation**: Efficient string building with `ft_strjoin`
3. **Buffer reading**: Reads data in chunks of `BUFFER_SIZE`
4. **Line reconstruction**: Concatenates chunks until newline is found

### Key Functions
- `get_next_line()`: Main function that orchestrates line reading
- `get_line()`: Handles reading and buffering logic
- `separate_string()`: Manages line separation and remainder storage
- `find_index()`: Locates newline characters in buffer
- `ft_strjoin()`: Safe string concatenation
- `ft_strlen()`, `ft_strlcpy()`: String utility functions

### Memory Management
- All allocated memory is properly freed
- No memory leaks (tested with Valgrind)
- Handles edge cases like empty files and interrupted reads
- Static variable `remain` maintains state between calls

## 🎓 Learning Objectives

This project teaches essential C concepts:
- **Static variables**: Understanding persistence between function calls
- **Memory management**: Manual allocation and deallocation with malloc/free
- **File I/O**: Low-level file reading with `read()` system call
- **String manipulation**: Building strings character by character
- **Edge case handling**: Robust error management and boundary conditions

## 🔍 42 School Compliance

- ✅ **Allowed functions only**: `read`, `malloc`, `free`
- ✅ **No global variables**: Uses static variables appropriately
- ✅ **Proper error handling**: Returns NULL on errors
- ✅ **No memory leaks**: All allocated memory is freed
- ✅ **Buffer size agnostic**: Works with any positive BUFFER_SIZE

## 📝 Implementation Notes

- Preserves `\n` characters when present in the original file
- Returns lines without `\n` only when file doesn't end with newline
- Handles files of any size efficiently
- Static variable ensures proper state management across calls
- Robust error handling for invalid file descriptors

## 🚀 Getting Started

1. Clone the repository
2. Create a test file with some content
3. Write a simple main function (see usage example above)
4. Compile with your preferred BUFFER_SIZE
5. Test with different file types and sizes

---

*This project demonstrates fundamental C programming skills including memory management, file I/O, and static variable usage. Part of the 42 School curriculum.*