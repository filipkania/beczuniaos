#pragma once

#include <stddef.h>

size_t strlen(const char *str);

void strcat(char *dst, const char *src);

void *memcpy(void *dst, void *src, size_t size);

void *memset(void *dst, int value, size_t size);

int memcmp(const void *a, const void *b, size_t size);

void *memmove(const void *a, const void *b, size_t size);

char *itoa(int value, char *str);

char *reverse_string(char *str);