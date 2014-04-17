#include "inhead.h"

int main (int argc, char *argv[])
{
    int ipstart=1, ipend=2;
    int t,u;
    int portnumber=1;
    int maxarg=3;
    int poscounter = 0;
    int position[argc];

    int optionport=5,optionpcounter=0, pposition=0;
    int optionw=5,optionwcounter=0, wposition=0;
    int optionname=5, optionnamecounter=0, nameposition;
    int optioncso=5, optioncsocounter=0, csoposition;
    int optionf=5, optionfcounter=0, fposition;
    int optionnocolor=5, optionnocolorcounter=0, nocolorposition;
    int optionjson=5, optionjsoncounter=0, jsonposition;

    char *filename = {"stdout\0"};

    for (t=1; t<argc; t++) {

        if (strcmp(argv[t], "--port") == 0) {
            optionport = 1;
            optionpcounter += 1;
            pposition = t;
            maxarg += 2;
            portnumber = atoi(argv[t+1]);
        }

        if (strcmp(argv[t], "--file") == 0) {
            optionf = 1;
            optionfcounter += 1;
            fposition = t;
            maxarg +=2;
            filename = argv[t+1];
        }

        if (strcmp(argv[t], "--without-blank") == 0) {
            optionw = 1;
            optionwcounter += 1;
            wposition = t;
            maxarg += 1;
        }

        if (strcmp(argv[t], "--namelookup") == 0) {
            optionname = 1;
            optionnamecounter += 1;
            maxarg += 1;
            nameposition = t;
        }

        if (strcmp(argv[t], "--commaseparated") == 0) {
          optioncso = 1;
          optioncsocounter += 1;
          csoposition = t;
          maxarg +=1;
        }

        if (strcmp(argv[t], "--nocolor") == 0) {
          optionnocolor = 1;
          optionnocolorcounter += 1;
          nocolorposition = t;
          maxarg +=1;
        }

        if (strcmp(argv[t], "--json") == 0) {
          optionjson = 1;
          optionjsoncounter += 1;
          jsonposition = t;
          maxarg +=1;
        }

        if ((argv[t][0] == '-') && (argv[t][1] != '-'))
          for (u=0; u<strlen(argv[t]);u++) {
            if (argv[t][u] == 'w') {
              optionw = 1;
              optionwcounter += 1;
              wposition = t;
              if (u==1)
                maxarg += 1;
            }
            if (argv[t][u] == 'p') {
              optionport = 1;
              optionpcounter += 1;
              pposition = t;
              if (u==1)
                maxarg += 1;
              maxarg += 1;
              portnumber = atoi(argv[t+1]);
            }
            if (argv[t][u] == 'f') {
              optionf = 1;
              optionfcounter += 1;
              fposition = t;
              if (u==1)
                maxarg +=1;
              maxarg +=1;
              filename = argv[t+1];
            }
            if (argv[t][u] == 'n') {
              optionname = 1;
              optionnamecounter += 1;
              if (u==1)
                maxarg += 1;
              nameposition = t;
            }
            if (argv[t][u] == 'c') {
              optioncso = 1;
              optioncsocounter += 1;
              csoposition = t;
              if (u==1)
                maxarg +=1;
            }
            if (argv[t][u] == 'b') {
              optionnocolor = 1;
              optionnocolorcounter += 1;
              nocolorposition = t;
              if (u==1)
                maxarg +=1;
            }
            if (argv[t][u] == 'j') {
              optionjson = 1;
              optionjsoncounter += 1;
              jsonposition = t;
              if (u==1)
                maxarg +=1;
            }
          }
   }

    if (
        (optionwcounter > 1) ||
        (optionpcounter > 1) ||
        (optionnamecounter > 1) ||
        (optioncsocounter > 1) ||
        (optionfcounter > 1) ||
        (optionnocolorcounter > 1) ||
        (optionjsoncounter > 1)
       )
    {
        errdupopt();
        return 1;
    }

    if (portnumber < 1 || portnumber > 65535){
        errinvalport();
        return 1;
    }

    for (t=1; t<argc; t++) {
        if (pposition == t) {
            position[t] = 0;
            t++;
            position[t] = 0;
        }
        else if (fposition == t) {
          position[t] = 0;
          t++;
          position[t] = 0;
        }
        else if (wposition == t)
            position[t] = 0;
        else if (nameposition == t)
            position[t] = 0;
        else if (csoposition == t)
            position[t] = 0;
        else if (nocolorposition == t)
            position[t] = 0;
        else if (jsonposition == t)
            position[t] = 0;
        else
            position[t] = 1;
    }

    for (t=1; t<argc; t++) {
        if (position[t] == 1) {
            if (poscounter == 0) {
                ipstart = t;
                poscounter += 1;
            }
            if (poscounter == 1)
                ipend = t;
        }
    }

  if ((argc < 2) || (argc > maxarg)) {
    errexptiprange();
    usage(argv[0]);
    exit(1);
  }

  if ((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)) {
    description();
    usage(argv[0]);
    help();
    exit(0);
  }

  if ((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)) {
    version();
    exit(0);
  }

  int endsec, startsec;
  startsec = time(NULL);
  int i,istart,iend;
  int re;
  char cmd[100];
  char runningip[50];
  char ping[50];
  char network[100];

  strcpy(network, argv[ipstart]);
  int addr[4];
  int counter=1;
  char delimiter[] = ".";
  char *ptr;
  FILE *stream[255];
  char pingend[20];

  ptr = strtok(network, delimiter);

  while (ptr != NULL) {
        addr[counter] = atoi(ptr);
        counter++;
        ptr = strtok(NULL, delimiter);
        if (counter > 5) {
            errip();
            return 1;
        }
  }

  for(counter=1; counter<5; counter++) {
    if ((addr[counter] > 255) || (addr[counter] < 0)) {
      errip();
      return 1;
    }
  }
  strcpy(ping, "ping -c 2 -W 1 ");
  strcpy(pingend, " >/dev/null");

  istart = addr[4];
  iend = atoi(argv[ipend]);

  if ((iend - istart) < 0) {
      errnegip();
      return 1;
  }
  if ((iend > 255) || (iend < 0)) {
      errvalran();
      return 1;
  }

  int cpid, childreturn;
  int ch_return[(iend - istart + 1)];
  int ch_pid[(iend - istart + 1)];

  for (i=istart; i<=iend; i++) {
    strcpy(runningip, "");
    sprintf(runningip, "%d.%d.%d.%d", addr[1], addr[2], addr[3], i);
    strcpy(cmd, ping);
    strcat(cmd, runningip);
    strcat(cmd, pingend);
    stream[i] = popen(cmd, "r");

    if (optionport == 1) {
      cpid = fork();
      switch (cpid) {
        case 0:
            childreturn = portconnection(portnumber, runningip);
            exit(childreturn);
          break;
        case -1:
            perror("Error: fork()");
          break;
      default:
            ch_pid[i] = cpid;
          break;
      }
    }
  }

  FILE *outputfile;
  if (strcmp(filename, "stdout") != 0) {
    outputfile = fopen(filename, "w");
    fclose(outputfile);
  }

  if ((optioncso != 1) && (optionjson != 1))
    headline(optionport, portnumber, optionw, optionname, filename);

  if (optionjson == 1) {
    if (strcmp(filename, "stdout") != 0)
      outputfile = fopen(filename, "a");
    else
      outputfile = stdout;
    fprintf(outputfile, "{\"netchk\":");
    if (strcmp(filename, "stdout") != 0)
      fclose(outputfile);
  }

  for (i=istart; i<=iend; i++) {

    re = pclose(stream[i]);
    strcpy(runningip, "");
    sprintf(runningip, "%d.%d.%d.%d", addr[1], addr[2], addr[3], i);

    evaluation_ping(re, runningip, optioncso, filename, optionnocolor, optionjson);
    lookup(runningip, optionname, optioncso, filename, optionnocolor, optionjson);
    if (optionport == 1) {
      waitpid(ch_pid[i], &ch_return[i], WUNTRACED);
      evaluation_port(ch_return[i]/256, optioncso, filename, optionnocolor, optionjson);
    }

   if (strcmp(filename, "stdout") != 0)
     outputfile = fopen(filename, "a");
   else
     outputfile = stdout;

   if (optionjson != 1)
     fprintf(outputfile, "\n");
   else {
     fprintf(outputfile, "}");
     if (i != iend)
       fprintf(outputfile, ",");
   }

   if (optionw != 1)
     fprintf(outputfile, "\n");

   if (strcmp(filename, "stdout") != 0)
    fclose(outputfile);
  }

  if (optionjson == 1) {
    if (strcmp(filename, "stdout") != 0)
      outputfile = fopen(filename, "a");
    else
      outputfile = stdout;
    fprintf(outputfile, "}");
    if (strcmp(filename, "stdout") != 0)
      fclose(outputfile);
  }

  endsec = time(NULL);

  if ((optioncso != 1) && (optionjson != 1))
    end((endsec - startsec), (iend - istart + 1), optionw, filename);

  return 0;
}
