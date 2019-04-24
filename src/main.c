#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "random.h"

int main(int argc, char *argv[]) {
  char *delim = " ";
  unsigned long n = 6;

  for (;;)
    switch (getopt(argc, argv, "d:n:")) {
    case 'd':
      delim = optarg;
      break;
    case 'n':
      sscanf(optarg, "%lu", &n);
      break;
    case -1:
      goto passphrase;
    default:
      return EXIT_FAILURE;
    }

passphrase:
  puts(correct_horse_random_passphrase(delim, n));
}
