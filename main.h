int _printf(const char *format, ...);
int print_unsigned(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
