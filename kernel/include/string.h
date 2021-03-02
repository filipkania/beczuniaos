#pragma once

#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>

#define dbgln(format, args...) __internal__debug(__FILE__, __LINE__, format, ##args)

size_t strlen(const char *str);

int strcat(char *dst, const char *src);

void *memcpy(void *dst, void *src, size_t size);

void *memset(void *dst, int value, size_t size);

int memcmp(const void *a, const void *b, size_t size);

void *memmove(const void *a, const void *b, size_t size);

char *itoa(int value);

char *reverse_string(char *str);

char *formatstr(const char *format, ...);

char *__internal__format(const char *format, va_list params);

void __internal__debug(const char *file, int line, const char *format, ...);