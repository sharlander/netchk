#include "inhead.h"

int headline(int optionport, int portnumber, int optionw, int optionname, char *filename)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

    if ((optionport == 1) && (optionname == 1)) {
        if (optionw != 1)
        fprintf(outputfile, "\n");
        fprintf(outputfile, "IP:\t\tping:\t\tip-lookup:\t\t\t\t\tname-lookup:\t\tport %d:\n"
               , portnumber);
        if (optionw != 1)
        fprintf(outputfile, "\n\n");
    }
    else if ((optionport != 1) && (optionname == 1)) {
       if(optionw != 1)
       fprintf(outputfile, "\n");
       fprintf(outputfile, "IP:\t\tping:\t\tip-lookup:\t\t\t\t\tnamelookup:\n");
       if(optionw != 1)
       fprintf(outputfile, "\n\n");
    }
    else if ((optionport == 1) && (optionname != 1)) {
       if(optionw != 1)
       fprintf(outputfile, "\n");
       fprintf(outputfile, "IP:\t\tping:\t\tip-lookup:\t\t\t\t\tport %d:\n", portnumber);
       if( optionw != 1)
       fprintf(outputfile, "\n\n");
    }
    else {
       if(optionw != 1)
       fprintf(outputfile, "\n");
       fprintf(outputfile, "IP:\t\tping:\t\tip-lookup:\n");
       if(optionw != 1)
       fprintf(outputfile, "\n\n");
    }

    fclose(outputfile);
    return 0;
}

int evaluation_ping(int re, char *givenip, int optioncso, char *filename)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  if (re == 0)
    if (optioncso==1)
      fprintf(outputfile, "%s;ok;", givenip);
    else
      fprintf(outputfile, "%s\t\033[32;1mok\033[0m\t\t", givenip);
  else
    if (optioncso==1)
      fprintf(outputfile, "%s;failed;", givenip);
    else
      fprintf(outputfile, "%s\t\033[31;1mfailed\033[0m\t\t", givenip);

  fclose(outputfile);
  return 0;
}

int evaluation_port(int givenre, int optioncso, char *filename)
{
  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0)
    outputfile = fopen(filename, "a");
  else
    outputfile = stdout;

  if (givenre == 0)
    if (optioncso==1)
      fprintf(outputfile, "ok;");
    else
      fprintf(outputfile, "\033[32;1mok\033[0m");
  else
    if (optioncso==1)
    fprintf(outputfile, "failed;");
    else
    fprintf(outputfile, "\033[31;1mfailed\033[0m");

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

  fclose(outputfile);
  return 0;
}
