# include "inhead.h"

int lookup(char *givenip)
{
  struct sockaddr_in sa;
  sa.sin_family = AF_INET;
  inet_pton(AF_INET, givenip, &sa.sin_addr);

  char node[NI_MAXHOST];

  getnameinfo((struct sockaddr*)&sa, sizeof(sa), node, sizeof(node), NULL, 0, 0);

  if ((strcmp(node, givenip) == 0 ) || (strcmp(node, "0.0.0.0") == 0 ))
  {
    printf("\033[31;1mfailed\33[0m\t\t\t\t\t\t");
    return 1;
  }
  else
  {
  printf("%s\t\t", node);
  return 0;
  }
}