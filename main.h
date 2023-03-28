#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
int convert_to_given_format(int n, int format, int is_upper_hex);
int print_string(char *str);
int _printf(const char *format, ...);
#endif
