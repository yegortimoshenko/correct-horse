#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "random.h"

int main(int argc, char *argv[]) {
  char *delim = " ";
  unsigned long n = 6;

  {
    char opt;
    while ((opt = getopt(argc, argv, "d:n:")) > 0) {
      switch (opt) {
      case 'd':
	delim = optarg;
	break;
      case 'n':
	sscanf(optarg, "%lu", &n);
	break;
      default:
	return EXIT_FAILURE;
      }
    }
  }

  puts(correct_horse_random_passphrase(delim, n));
}
