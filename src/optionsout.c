#include "inhead.h"

void description()
{
  printf( "\n"
          "The program is for checking a network\n"
          "the given ip range is checked (in multiple threads) with ping and iplookup\n"
          "\n");
}

void version()
{
  printf("\n"
         "The program version is 1.3.2\n"
         "\n");
}

void usage(char *givencommand)
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
}

void help()
{
  printf("Vaild options are:\n"
         "\n"
         "Short options:\n"
         "\n"
         "-h\t\tDisplay's this help\n"
         "-v\t\tShow's program version\n"
         "-p\t\tConnects to a specific port\n"
         "-w\t\tOutput is without the blank lines\n"
         "-n\t\tNamelookup is compared with ip\n"
         "-c\t\tComma separated output\n"
         "-f\t\tPrints output to given file\n"
         "-b\t\tOutput without colors\n"
         "-j\t\tjson formatted output\n"
         "-l\t\tleft-justified output\n"
         "\n"
         "Long options:\n"
         "\n"
         "--help\t\t\tDisplay's this help\n"
         "--version\t\tShow's program version\n"
         "--port\t\t\tConnects to specific port\n"
         "--without-blank\t\tOutput is without the blank lines\n"
         "--namelookup\t\tNamelookup is compared with ip\n"
         "--commaseparated\tComma separated output\n"
         "--file\t\t\tPrints output to given file\n"
         "--nocolor\t\tOuput without colors\n"
         "--json\t\t\tjson formatted output\n"
         "--left\t\t\tleft-justified output\n"
         "\n"
         );
}
