# include "inhead.h"

int namelookup ( char *givenname )
{
  struct hostent *dns;
  if ( gethostbyname(givenname) == 0)
      return -1;
  dns = gethostbyname(givenname);

  sprintf(givenname, "%u.%u.%u.%u",
          (unsigned char) dns->h_addr_list[0][0],
          (unsigned char) dns->h_addr_list[0][1],
          (unsigned char) dns->h_addr_list[0][2],
          (unsigned char) dns->h_addr_list[0][3]);

  return 0;

}
