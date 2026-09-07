#ifndef PIG_LATIN_H
#define PIG_LATIN_H
#include <stdbool.h>

char *translate(const char *phrase);
char *translate_word(const char *phrase);
bool is_vowel(char c);

#endif
