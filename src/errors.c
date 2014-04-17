#include "inhead.h"

void errrange() {
  printf( "\n"
          "Error: Expected a ip range!\n");
}

void errip() {
  printf("Error: not a valid ip\n");
}

void errnegip() {
  printf("Error: negative ip range detected\n");
}

void errvalran() {
  printf("Error: not a valid range\n");
}

void errinvalport() {
  printf("Error: not a valid port\n");
}

void errexptiprange() {
  printf("Error: Invalid parameters!\n");
}

void errdupopt() {
  printf("Error: Duplicated option detected!\n");
}

void errmaxarg() {
  printf("Error: Too many arguments\n");
}
