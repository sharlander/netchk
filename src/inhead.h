#ifndef INHEAD_H
#define INHEAD_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int lookup(char *givenip, int optionname, int optioncso, char *filename, int optionnocolor, int optionjson);
int namelookup (char *givenname);
void description();
void version();
void usage(char *givencommand);
void help();
int headline(int optionport, int portnumber, int optionw, int optionname, char *filename);
int evaluation_ping(int re, char *givenip, int optioncso, char *filename, int optionnocolor, int optionjson);
int evaluation_port(int givenre, int optioncso, char *filename, int optionnocolor, int optionjson);
int end(int sec, int ips, int optionw, char *filename);
int portconnection(int givenport, char *givenip);

void errrange();
void errip();
void errnegip();
void errvalran();
void errinvalport();
void errexptiprange();
void errdupopt();
void errmaxarg();
