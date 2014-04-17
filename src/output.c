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

int evaluation_ping(int re, char *givenip, int optioncso, char *filename, int optionnocolor, int optionjson)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  char ok[200] = {"ok"};
  char failed[200] = {"failed"};
  char status[200];

  if (re == 0)
    strcpy(status, ok);
  else
    strcpy(status, failed);

  if (optioncso == 1)
    fprintf(outputfile, "%s;%s;", givenip, status);
  else if (optionjson == 1)
    fprintf(outputfile, "{\"%s\":{\"name\":\"ping\",\"value\":\"%s\"}", givenip, status);
  else if (optionnocolor == 1)
    fprintf(outputfile, "%16s%8s", givenip, ok);
  else {
    if (strcmp(status, ok) == 0)
      fprintf(outputfile, "%16s\033[32;1m%8s\033[0m", givenip, status);
    else
      fprintf(outputfile, "%16s\033[31;1m%8s\033[0m", givenip, status);
  }

  if (strcmp(filename, "stdout") != 0)
    fclose(outputfile);
  return 0;
}

int evaluation_port(int givenre, int optioncso, char *filename, int optionnocolor, int optionjson)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  char ok[200] = {"ok"};
  char failed[200] = {"failed"};
  char status[200];

  if (givenre == 0)
    strcpy(status, ok);
  else
    strcpy(status, failed);

    if (optioncso == 1)
      fprintf(outputfile, "%s;", status);
    else if (optionjson == 1)
      fprintf(outputfile, ",{\"name\":\"port\",\"value\":\"%s\"}", status);
    else if (optionnocolor == 1)
      fprintf(outputfile, "%11s", status);
    else
      fprintf(outputfile, "\033[32;1m%11s\033[0m", status);

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
