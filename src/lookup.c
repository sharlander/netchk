#include "inhead.h"

int lookup(char *givenip, int optionname, int optioncso, char *filename, int optionnocolor, int optionjson, int optionleft)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  char failed[200] = {"failed"};
  char noname[200] = {"noname"};
  char status[200];
  char status2[200];

  struct sockaddr_in sa;
  sa.sin_family = AF_INET;
  inet_pton(AF_INET, givenip, &sa.sin_addr);

  char node[NI_MAXHOST];

  getnameinfo((struct sockaddr*)&sa, sizeof(sa), node, sizeof(node), NULL, 0, 0);

  if ((strcmp(node, givenip) == 0) || (strcmp(node, "0.0.0.0") == 0)) {
    strcpy(status, failed);
    strcpy(status2, noname);
  }
  else {
    strcpy(status, node);
    namelookup(node);
    strcpy(status2, node);
  }

  if (optioncso == 1)
    fprintf(outputfile, "%s;", status);
  else if (optionjson == 1)
    fprintf(outputfile, ",{\"name\":\"iplookup\",\"value\":\"%s\"}", status);
  else if (optionnocolor == 1) {
    if (optionleft == 1)
      fprintf(outputfile, "%-40s", status);
    else
      fprintf(outputfile, "%40s", status);
  }
  else {
    if (strcmp(status, failed) == 0) {
      if (optionleft == 1)
        fprintf(outputfile, "\033[31;1m%-40s\33[0m", status);
      else
        fprintf(outputfile, "\033[31;1m%40s\33[0m", status);
    }
    else {
      if (optionleft == 1)
        fprintf(outputfile, "%-40s", status);
      else
        fprintf(outputfile, "%40s", status);
    }
  }

  if (optionname == 1) {
    if (optioncso==1)
      fprintf(outputfile, "%s;", status2);
    else if (optionjson == 1)
      fprintf(outputfile, ",{\"name\":\"namelookup\",\"value\":\"%s\"}", status2);
    else if (optionnocolor == 1) {
      if (optionleft == 1)
        fprintf(outputfile, "%-16s", status2);
      else
        fprintf(outputfile, "%16s", status2);
    }
    else {
      if (strcmp(status2, noname) == 0) {
        if (optionleft == 1)
          fprintf(outputfile, "\033[31;1m%-16s\033[0m", status2);
        else
          fprintf(outputfile, "\033[31;1m%16s\033[0m", status2);
      }
      else {
        if (optionleft == 1)
          fprintf(outputfile, "\033[32;1m%-16s\033[0m", status2);
        else
          fprintf(outputfile, "\033[32;1m%16s\033[0m", status2);
      }
    }
  }

  if (strcmp(filename, "stdout") != 0)
    fclose(outputfile);

  return 0;
}
