#include "inhead.h"


int headline(int givenopt, int portnumber, int optionw)
{
    if (givenopt == 1 )
    {
        if( optionw != 1)
        printf("\n");
        printf("IP:\t\tping:\t\tip-lookup:\t\t\t\t\tport %d:"
               , portnumber);
        if( optionw != 1)
        printf("\n\n");
    }
      else
    {
       if( optionw != 1)
       printf("\n");
       printf("IP:\t\tping:\t\tip-lookup:");
       if( optionw != 1)
       printf("\n\n");
    }
    return 0;
}

int evaluation_ping(int re, char *givenip)
{
  if (re == 0)
    printf("\n%s\t\033[32;1mok\033[0m\t\t", givenip);
  else
    printf("\n%s\t\033[31;1mfailed\033[0m\t\t", givenip);
  
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