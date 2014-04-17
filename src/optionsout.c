#include "inhead.h"

int description()
{
  printf( "\n"
          "The Programm is for checking a network\n"
          "the given ip range is checked (in multiple threads) with ping and iplookup\n"
          "\n");
  return 0;
}

int version()
{
  printf("\n"
         "The Programm version is 1.2.2\n"
         "\n");
  return 0;
}

int usage(char *givencommand)
{
  printf("Usage:\n"
         "%s network.startip endip\n"
         "\n"
         "Example:\n"
         "%s 10.254.3.1 254\n"
         "\n"
         "Letters in the ip are taken as a 0:\n"
         "10.254.example.1 = 10.254.0.1\n"
         "\n", givencommand, givencommand);
  return 0;
}

int help()
{
  printf("Vaild options are:\n"
         "\n"
         "Short options:\n"
         "\n"
         "-h\t\tDisplay's this help\n"
         "-v\t\tShow's programm version\n"
         "-p\t\tConnects to a specific port\n"
         "-w\t\tOutput is without the blank lines\n"
         "-n\t\tNamelookup is compared with ip\n"
         "-c\t\tComma separated output\n"
         "\n"
         "Long options:\n"
         "\n"
         "--help\t\t\tDisplay's this help\n"
         "--version\t\tShow's programm version\n"
         "--port\t\t\tConnects to specific port\n"
         "--without-blank\t\tOutput is without the blank lines\n"
         "--namelookup\t\tNamelookup is compared with ip\n"
         "--commaseparated\tComma separated output\n"
         "\n"
         );

  return 0;
}
