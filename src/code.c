# include "inhead.h"

int main( int argv, char *argc[] )
{
    int ipstart=1, ipend=2;
    int t, optionport=5,optionpcounter=0;
    int optionw=5,optionwcounter=0;
    int portnumber=1;
    int maxarg=3;
    int pposition=0, wposition=0;
    int poscounter = 0;
    int position[argv];

    for (t=1; t<argv; t++)
    {
        if (( strcmp(argc[t], "-p") == 0 ) || ( strcmp(argc[t], "--port") == 0 ))
        {
            optionport = 1;
            optionpcounter += 1;
            pposition = t;
            maxarg += 2;
            portnumber = atoi(argc[t+1]);
        }

        if (( strcmp(argc[t], "-w") == 0 ) || ( strcmp(argc[t], "--without-blank") == 0 ))
        {
            optionw = 1;
            optionwcounter += 1;
            wposition = t;
            maxarg += 1;
        }

        if (( strcmp(argc[t], "-pw") == 0 ) || ( strcmp(argc[t], "-wp") == 0 ))
        {
            optionw = 1;
            optionport = 1;
            maxarg += 2;
            portnumber = atoi(argc[t+1]);
            pposition = t;
        }
    }

    if ( (optionwcounter > 1) || (optionpcounter > 1) )
    {
        errdupopt();
        return 1;
    }

    if ( portnumber < 1 || portnumber > 65535 )
    {
        errinvalport();
        return 1;
    }

    for (t=1; t<argv; t++)
    {
        if (pposition == t )
        {
            position[t] = 0;
            t++;
            position[t] = 0;
        }
        else if (wposition == t)
            position[t] = 0;
        else
            position[t] = 1;
    }

    for (t=1; t<argv; t++)
    {
        if ( position[t] == 1 )
        {
            if ( poscounter == 0)
            {
                ipstart = t;
                poscounter += 1;
            }
            if ( poscounter == 1)
                ipend = t;
        }
    }

  varchk(argv, argc, maxarg);

  int endsec, startsec;
  startsec = time( NULL );
  int i,istart,iend;
  int re;
  char cmd[100];
  char runningip[50];
  char ping[50];
  char network[100];

  strcpy(network, argc[ipstart]);
  int addr[4];
  int counter=1;
  char delimiter[] = ".";
  char *ptr;
  FILE *stream[255];
  char pingend[20];

  ptr = strtok(network, delimiter);

  while(ptr != NULL) {
        addr[counter] = atoi(ptr);
        counter++;
        ptr = strtok(NULL, delimiter);
        if ( counter > 5 )
        {
            errip();
            return 1;
        }
  }

  for(counter=1;counter<5;counter++)
  {
  if ( addr[counter] > 255 || addr[counter] < 0 )
  {
      errip();
      return 1;
  }
  }
  strcpy(ping, "ping -c 2 -W 1 ");
  strcpy(pingend, " >/dev/null");

  istart = addr[4];
  iend = atoi(argc[ipend]);

  if ((iend - istart) < 0)
  {
      errnegip();
      return 1;
  }
  if ( iend > 255 || iend < 0 )
  {
      errvalran();
      return 1;
  }

  int cpid, childreturn;
  int ch_return[(iend - istart + 1)];
  int ch_pid[(iend - istart + 1)];

  for ( i=istart;i<=iend;i++ )
  {
    strcpy(runningip, "");
    sprintf(runningip, "%d.%d.%d.%d", addr[1], addr[2], addr[3], i);
    strcpy(cmd, ping);
    strcat(cmd, runningip);
    strcat(cmd, pingend);
    stream[i] = popen(cmd, "r");

    if (optionport == 1) {

      cpid = fork();

      switch(cpid) {
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

  headline(optionport, portnumber, optionw);

  for ( i=istart;i<=iend;i++ )
  {
    re = pclose(stream[i]);
    strcpy(runningip, "");
    sprintf(runningip, "%d.%d.%d.%d", addr[1], addr[2], addr[3], i);

    evaluation_ping(re, runningip);
    lookup( runningip );
    if (optionport == 1) {
      waitpid(ch_pid[i], &ch_return[i], WUNTRACED);
      evaluation_port(ch_return[i]/256);
    }
    if ( optionw != 1)
    printf("\n");
  }

  endsec = time( NULL );

  end((endsec - startsec), (iend - istart + 1), optionw);

  return 0;

}
