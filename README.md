# <a name="top">ft_printf</a>

Ft_printf is a variadic function that recreates much of printf's functionalities.

## Contents

[Language & Functions Used](#language_functions) | [Installation & Usage](#installation_usage) | [Format Specification Fields](#fields) 

## <a name="language_functions">Language & Functions Used</a>

The ft_printf function is written in C, using only the following functions from the standard C libraries: 

* write
* stdarg

<a href="#top">↥ back to top</a>

## <a name="installation_usage">Installation & Usage</a>

#### `Step 1` - clone the repo at the root of your project folder

```bash
$ git clone https://github.com/serena-zhu/ft_printf.git
```

#### `Step 2` - compile library

```bash
$ make
```

The Makefile will compile a static library called libftprintf.a, which can be compiled with your program source files as follows:

```bash
$ gcc -Wall -Wextra -Werror -o program_name source_file -L ./ft_printf -lftprintf
```
<a href="#top">↥ back to top</a>

## <a name="fields">Format Specification Fields</a>

#### `Flags`

* \#
* 0
* \-
* \+
* space
* '

#### `Minimum Field Width`

* \# [given as any hardcoded number e.g. ft_printf("%4d\n", number);]
* \* [given as a variable e.g. ft_printf("%*d\n", 4, number); Note: if a negative number is provided, the absolute value will be used and a '-' flag will be added]

#### `Precision`

* .# [given as any hardcoded number e.g. ft_printf("%.2f\n", number);]
* .* [given as a variable e.g. ft_printf("%.*f\n", 2, number);]

#### `Length modifiers`

* hh
* h
* l
* ll
* j
* z
* L

#### `Conversion Specifiers`

* s, S
* p
* d, D, i
* o, O
* u, U
* x, X
* c, C
* e, E
* f, F
* g, G
* n

#### `Color Management`

This function includes a color management functionality that is different from printf.

To use: specify colors in between {} and end color with {eoc}. If the closing bracket } is missing, the opening bracket { and the texts that follow will be printed to standard output. 

Example main.c:
```
#include "ft_printf.h"

int	main(void)
{
	ft_printf("This will be{red} red text {eoc}and now the text color is back to default.\n");
	return (0);
}
```
![color_output](/color_management_output.PNG)

Supported colors are:

* black | red | green | yellow | blue | magenta | cyan | white | gray
* light red | light green | light yellow | light blue | light magenta | light cyan

<a href="#top">↥ back to top</a>
