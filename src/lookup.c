# include "inhead.h"

int lookup(char *givenip, int optionname)
{
  struct sockaddr_in sa;
  sa.sin_family = AF_INET;
  inet_pton(AF_INET, givenip, &sa.sin_addr);

  char node[NI_MAXHOST];

  getnameinfo((struct sockaddr*)&sa, sizeof(sa), node, sizeof(node), NULL, 0, 0);

  if ((strcmp(node, givenip) == 0 ) || (strcmp(node, "0.0.0.0") == 0 ))
  {
    printf("\033[31;1mfailed\33[0m\t\t\t\t\t\t");

    if (optionname == 1)
      printf("\033[31;1mno name for lookup\033[0m\t");

    return 1;
  }
  else
  {
    printf("%s\t\t", node);
    if (optionname == 1) {
      namelookup(node);
      if (strcmp(node, givenip)==0)
        printf("\033[32;1m%s\033[0m\t\t", node);
      else
        printf("\033[31;1m%s\33[0m\t\t", node);
    }
    return 0;
  }
}
