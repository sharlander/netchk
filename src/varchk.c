# include "inhead.h"

int varchk(int argv, char *argc[], int maxarg )
{
  int b=0;
  int c=1;
  
  if ( ( argv < 2 ) ||
        ( argv > maxarg )
     )
  {
        errexptiprange();
        usage(argc[b]);
        exit(1);
  }

  if ( (strcmp(argc[c], "-h") == 0) || (strcmp(argc[c], "--help") == 0) )
  {
      description();
      usage(argc[b]);
      help();
      exit(0);
  }

  if ( (strcmp(argc[c], "-v") == 0) || (strcmp(argc[c], "--version") == 0) )
  {
    version();
    exit(0);
  }
   
    return 0;
}
