#ifndef UTF8RUS_H
#define UTF8RUS_H

#include <stddef.h>  // for size_t
#include <stdbool.h> // for bool in plain C contexts

#ifdef __cplusplus
extern "C" {
#endif

// Calculate UTF-8 string length (optional utility)
size_t strlen_utf8(const char* s);

// Convert UTF-8 Cyrillic (including Ukrainian) to font-mapped 8-bit text
char* utf8Rus(const char* str, bool uppercase);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // UTF8RUS_H
