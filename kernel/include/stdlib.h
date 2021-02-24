#pragma once

#define ASSERT(EX) (void)(EX || (__internal_assert(#EX, __FILE__, __LINE__, __FUNCTION__), 0))
#define ASSERT_NOT_REACHED() (void)(__internal_assert("was reached. Assertion", __FILE__, __LINE__, __FUNCTION__), 0)

void __ABORT();

void KERNEL_PANIC();

void __internal_assert(const char *msg, const char *file, int line, const char *function);