#include "inhead.h"

int portconnection(int givenport, char *givenip)
{
    int connect_socket;
    struct sockaddr_in connect_address;

    connect_socket=socket(AF_INET, SOCK_STREAM, 0);
    if (connect_socket == -1) {
      printf("Error: could not create a new socket\n");
      exit(1);
    }

    connect_address.sin_family = AF_INET;
    connect_address.sin_port = htons(givenport);
    connect_address.sin_addr.s_addr = inet_addr(givenip);

    if ((connect(connect_socket, (struct sockaddr *)&connect_address, sizeof(connect_address))) == -1)
      return 1;
    else
      return 0;

    close(connect_socket);
    return 0;
}
