# ft_printf
Printf function recoded.

Contains an additional color management not supported by system's printf function:
Specify colors in between {} and end color with {eoc} like so: ft_printf("This will be{red} red text {eoc}and now text color is back to normal");
Colors supported are:
black, red, green, yellow, blue, magenta, cyan, white, gray;
light red, light green, light yellow, light blue, light magenta, light cyan.
If the color specified in {} is not a supported color, the default color will be used.
If the closing bracket } is missing, the opening bracket { and the texts that follow will be printedto standard output. 
