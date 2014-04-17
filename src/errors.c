#include "inhead.h"

int errrange()
{
    printf("\n"
          "Error: Expected a ip range!\n"
          );
    return 0;
}

int erroptions()
{
    return 0;
}

int errip()
{
    printf("Error: not a valid ip\n"
          );
    return 0;
}

int errnegip()
{
    printf("Error: negative ip range detected\n"
          );
    return 0;
}

int errvalran()
{
    printf("Error: not a valid range\n"
          );
    return 0;
}

int errinvalport()
{
    printf("Error: not a valid Port\n"
          );
    return 0;
}

int errexptiprange()
{
    printf("Error: Invalid parameters!\n"
          );
    return 0;
}

int errdupopt()
{
    printf("Error: Duplicated option detected!\n"
          );
    return 0;
}