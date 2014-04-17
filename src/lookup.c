#include "inhead.h"

int lookup(char *givenip, int optionname, int optioncso, char *filename)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  char failed[200] = {"failed"};
  char noname[200] = {"noname"};

  struct sockaddr_in sa;
  sa.sin_family = AF_INET;
  inet_pton(AF_INET, givenip, &sa.sin_addr);

  char node[NI_MAXHOST];

  getnameinfo((struct sockaddr*)&sa, sizeof(sa), node, sizeof(node), NULL, 0, 0);

  if ((strcmp(node, givenip) == 0) || (strcmp(node, "0.0.0.0") == 0)) {
    if (optioncso == 1)
      fprintf(outputfile, "%s;", failed);
    else
      fprintf(outputfile, "\033[31;1m%40s\33[0m", failed);

    if (optionname == 1) {
      if (optioncso==1)
        fprintf(outputfile, "%s;", noname);
      else
        fprintf(outputfile, "\033[31;1m%16s\033[0m", noname);
    }

    if (strcmp(filename, "stdout") != 0)
      fclose(outputfile);
    return 1;
  }
  else {
    if (optioncso==1)
      fprintf(outputfile, "%s;", node);
    else
      fprintf(outputfile, "%40s", node);

    if (optionname == 1) {
      namelookup(node);
      if (strcmp(node, givenip)==0) {
        if (optioncso==1)
          fprintf(outputfile, "%s;", node);
        else
          fprintf(outputfile, "\033[32;1m%16s\033[0m", node);
      }
      else {
        if (optioncso==1)
          fprintf(outputfile, "%s;", node);
        else
          fprintf(outputfile, "\033[31;1m%16s\33[0m", node);
      }
    }
    if (strcmp(filename, "stdout") != 0)
      fclose(outputfile);
    return 0;
  }
}
