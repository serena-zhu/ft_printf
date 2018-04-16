# <a name="top">ft_printf</a>

Ft_printf is a variadic function that recreates much of printf's functionalities.

[Language & Functions Used](#language_functions) | [Installation & Usage](#installation_usage) | [Functionalities](#functionalities) 

## <a name="language_functions">Language & Functions Used</a>

The ft_printf function is written in C, using only the following functions from the standard C libaries: 

* write
* malloc
* free
* exit
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
$ gcc -Wall -Wextra -Werror -o program_name source_file -L ./libft -lft
```
<a href="#top">↥ back to top</a>

## <a name="functionalities">Functionalities</a>

#### `Flags`

* #
* 0
* -
* +
* space
* '

#### `Minimum Field Width`

* # [given as any hardcoded number e.g. ft_printf("%4d\n", number);]
* * [given as a variable e.g. ft_printf("%*d\n", 4, number); Note: if a negative number is provided, the absolute value will be used and a '-' flag will be added]

### `Precision`

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

### 'Color Management'

A color management functionality that is not supported by printf is added.

Specify colors in between {} and end color with {eoc}. If the closing bracket } is missing, the opening bracket { and the texts that follow will be printed to standard output. 

Example:
```
ft_printf("This will be{red} red text {eoc}and now the text color is back to default.");

(/color_management_output.PNG)
``` 
Supported colors are:

* black | red | green | yellow | blue | magenta | cyan | white | gray
* light red | light green | light yellow | light blue | light magenta | light cyan