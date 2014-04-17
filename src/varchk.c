#include "inhead.h"

int varchk(int argc, char *argv[], int maxarg)
{
  int b=0;
  int c=1;

  if ((argc < 2) || (argc > maxarg)) {
    errexptiprange();
    usage(argv[b]);
    exit(1);
  }

  if ((strcmp(argv[c], "-h") == 0) || (strcmp(argv[c], "--help") == 0)) {
    description();
    usage(argv[b]);
    help();
    exit(0);
  }

  if ((strcmp(argv[c], "-v") == 0) || (strcmp(argv[c], "--version") == 0)) {
    version();
    exit(0);
  }

  return 0;
}
