#include "inhead.h"

int headline(int optionport, int portnumber, int optionw, int optionname, char *filename)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  char ip[200] = {"IP"};
  char ping[200] = {"ping"};
  char iplookup[200] = {"ip-lookup"};
  char namelookup[200] = {"name-lookup"};
  char port[200];
  sprintf(port, "port %d", portnumber);

  if (optionw != 1)
    fprintf(outputfile, "\n");

  fprintf(outputfile, "%16s%8s%40s", ip, ping, iplookup);

  if (optionname == 1)
    fprintf(outputfile, "%16s", namelookup);
  if (optionport == 1)
    fprintf(outputfile, "%11s", port);

  fprintf(outputfile, "\n");

  if (optionw != 1)
    fprintf(outputfile, "\n\n");

  if (strcmp(filename, "stdout") != 0)
    fclose(outputfile);

  return 0;
}

int evaluation_ping(int re, char *givenip, int optioncso, char *filename, int optionnocolor)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  char ok[200] = {"ok"};
  char failed[200] = {"failed"};

  if (re == 0) {
    if (optioncso==1)
      fprintf(outputfile, "%s;%s;", givenip, ok);
    else if (optionnocolor == 1)
      fprintf(outputfile, "%16s%8s", givenip, ok);
    else
      fprintf(outputfile, "%16s\033[32;1m%8s\033[0m", givenip, ok);
  }
  else {
    if (optioncso==1)
      fprintf(outputfile, "%s;%s;", givenip, failed);
    else if (optionnocolor == 1)
      fprintf(outputfile, "%16s%8s", givenip, failed);
    else
      fprintf(outputfile, "%16s\033[31;1m%8s\033[0m", givenip, failed);
  }

  if (strcmp(filename, "stdout") != 0)
    fclose(outputfile);
  return 0;
}

int evaluation_port(int givenre, int optioncso, char *filename, int optionnocolor)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  char ok[200] = {"ok"};
  char failed[200] = {"failed"};

  if (givenre == 0) {
    if (optioncso == 1)
      fprintf(outputfile, "%s;", ok);
    else if (optionnocolor == 1)
      fprintf(outputfile, "%11s", ok);
    else
      fprintf(outputfile, "\033[32;1m%11s\033[0m", ok);
  }
  else {
    if (optioncso == 1)
      fprintf(outputfile, "failed;");
    else if (optionnocolor == 1)
      fprintf(outputfile, "%11s", failed);
    else
      fprintf(outputfile, "\033[31;1m%11s\033[0m", failed);
  }

  if (strcmp(filename, "stdout") != 0)
    fclose(outputfile);
  return 0;
}

int end(int sec, int ips, int optionw, char *filename)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  if ((sec == 1) && (ips > 1))
  fprintf(outputfile, "Finished %d ips in %d second\n", ips, sec);
  else if ((sec == 1) && (ips == 1))
  fprintf(outputfile, "Finished %d ip in %d second\n", ips, sec);
  else if (( sec > 1) && ( ips== 1))
  fprintf(outputfile, "Finished %d ip in %d seconds\n", ips, sec);
  else
  fprintf(outputfile, "Finished %d ips in %d seconds\n", ips, sec);

  if (optionw != 1)
  fprintf(outputfile, "\n");

  if (strcmp(filename, "stdout") != 0)
    fclose(outputfile);
  return 0;
}
