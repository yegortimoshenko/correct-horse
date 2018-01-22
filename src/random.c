#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "dictionary.h"

static uint16_t correct_horse_random_uint16() {
  uint16_t n;
  assert(!getentropy(&n, sizeof(n)));
  return n;
}

const char *correct_horse_random_word() {
  return correct_horse_dictionary[correct_horse_random_uint16()];
}

char *correct_horse_random_passphrase(char *delim, unsigned long n) {
  char *buf;
  size_t sz;

  FILE *out = open_memstream(&buf, &sz);

  for (size_t i = 0; i < n;) {
    fputs(correct_horse_random_word(), out);
    if (n != ++i)
      fputs(delim, out);
  }

  fclose(out);
  return buf;
}
