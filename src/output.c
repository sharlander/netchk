#include "inhead.h"


int headline(int optionport, int portnumber, int optionw, int optionname)
{
    if ((optionport == 1) && (optionname == 1))
    {
        if( optionw != 1)
        printf("\n");
        printf("IP:\t\tping:\t\tip-lookup:\t\t\t\t\tname-lookup:\t\tport %d:\n"
               , portnumber);
        if (optionw != 1)
        printf("\n\n");
    }
    else if ((optionport != 1) && (optionname == 1)) {
       if( optionw != 1)
       printf("\n");
       printf("IP:\t\tping:\t\tip-lookup:\t\t\t\t\tnamelookup:\n");
       if( optionw != 1)
       printf("\n\n");
    }
    else if ((optionport == 1) && (optionname != 1)) {
       if( optionw != 1)
       printf("\n");
       printf("IP:\t\tping:\t\tip-lookup:\t\t\t\t\tport %d:\n", portnumber);
       if( optionw != 1)
       printf("\n\n");
    }
    else
    {
       if( optionw != 1)
       printf("\n");
       printf("IP:\t\tping:\t\tip-lookup:\n");
       if( optionw != 1)
       printf("\n\n");
    }
    return 0;
}

int evaluation_ping(int re, char *givenip, int optioncso)
{
  if (re == 0)
    if (optioncso==1)
      printf("%s;ok;", givenip);
    else
      printf("%s\t\033[32;1mok\033[0m\t\t", givenip);
  else
    if (optioncso==1)
      printf("%s;failed;", givenip);
    else
      printf("%s\t\033[31;1mfailed\033[0m\t\t", givenip);

  return 0;
}

int evaluation_port(int givenre, int optioncso)
{
  if (givenre == 0)
    if (optioncso==1)
      printf("ok;");
    else
      printf("\033[32;1mok\033[0m");
  else
    if (optioncso==1)
    printf("failed;");
    else
    printf("\033[31;1mfailed\033[0m");

  return 0;
}

int end( int sec, int ips, int optionw)
{
  if ((sec == 1) && (ips > 1))
  printf("\nFinished %d ips in %d second\n", ips, sec );
  else if ((sec == 1) && (ips == 1))
  printf("\nFinished %d ip in %d second\n", ips, sec );
  else if (( sec > 1) && ( ips== 1))
  printf("\nFinished %d ip in %d seconds\n", ips, sec );
  else
  printf("\nFinished %d ips in %d seconds\n", ips, sec );

  if( optionw != 1)
  printf("\n");

  return 0;
}
