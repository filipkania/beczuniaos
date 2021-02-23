#pragma once

#include <stddef.h>

size_t strlen(const char *str);

void strcat(char *dst, const char *src);

void *memcpy(void *dst, void *src, size_t size);