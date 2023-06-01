int _printf(const char *format, ...);
int print_unsigned(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size);
