# ft_printf

## 📋 Overview

`ft_printf` is a custom implementation of the standard C `printf()` function. This project demonstrates my ability to work with variadic functions, string parsing, and modular code design.

By recreating one of the most versatile and widely-used C functions from scratch, I gained a deeper understanding of formatted output, type conversions, and efficient memory handling.

## ✨ Features

### Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer address (hexadecimal) |
| `%d` | Decimal number |
| `%i` | Integer (base 10) |
| `%u` | Unsigned decimal |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Percent sign |

### Bonus Features

- Flag combinations: `-0.` with field width
- Additional flags: `# +` (including space)

## 🛠️ Technical Implementation

### Architecture

My implementation follows a modular design with separate handlers for each conversion type, making the code:
- Maintainable
- Extensible
- Easy to debug

### Key Components

- **Parser**: Analyzes the format string and identifies conversion specifications
- **Dispatcher**: Routes each conversion to the appropriate handler function
- **Handlers**: Specialized functions for each conversion type
- **Buffer Management**: Optimized character output
- **Memory Management**: No memory leaks

## 📊 Performance

- **Speed**: Optimized for efficiency
- **Memory**: Minimal memory footprint
- **Compatibility**: Behaves like the original `printf()`

## 📝 Usage

### Compilation

```bash
# Clone the repository
git clone https://github.com/Melis-Pablo/ft_printf.git
cd ft_printf

# Build the library
make

# Build with bonus features
make bonus
```

### Integration

```bash
# Compile your program with ft_printf
cc -Wall -Wextra -Werror your_program.c -L. -lftprintf -o your_program
```

### Code Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");

    int number = 42;
    ft_printf("Decimal: %d\n", number);
    ft_printf("Hexadecimal: %x\n", number);

    char *ptr = "pointer";
    ft_printf("Pointer address: %p\n", ptr);

    return (0);
}
```

## 🧩 Function Prototype

```c
int ft_printf(const char *format, ...);
```

**Parameters:**
- `format`: String containing text and conversion specifications
- `...`: Variable arguments corresponding to the conversion specifications

**Return Value:**
- The number of characters printed
- Negative value if an error occurs

## 💭 Reflections

### Challenges Overcome

- **Variadic Functions**: Learning to work with va_list and related macros
- **Format Parsing**: Correct interpretation of format strings with nested specifications
- **Edge Cases**: Handling special cases like NULL pointers and extreme values
- **Code Structure**: Designing a flexible architecture that can be extended

### Key Learnings

- **Modular Design**: Breaking complex problems into manageable components
- **Type Handling**: Converting various data types to string representations
- **Memory Efficiency**: Balancing performance with memory usage
- **Deep C Knowledge**: Understanding type conversions and bit manipulations

## 📚 See Also

For detailed project requirements, see the [ft_printf.md](ft_printf.md) file.

---

*This project is part of the 42 School Common Core curriculum.*
