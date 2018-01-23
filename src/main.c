#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "random.h"

int main(int argc, char *argv[]) {
  char *delim = " ";
  unsigned long n = 6;

  for (;;) {
    switch (getopt(argc, argv, "d:n:")) {
    case 'd':
      delim = optarg;
      continue;
    case 'n':
      sscanf(optarg, "%lu", &n);
      continue;
    case -1:
      break;
    default:
      return EXIT_FAILURE;
    }

    break;
  }

  puts(correct_horse_random_passphrase(delim, n));
}
