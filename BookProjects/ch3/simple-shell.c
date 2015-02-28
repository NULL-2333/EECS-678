/**
 * Simple shell interface program.
 *
 * Operating System Concepts - Ninth Edition
 * Copyright John Wiley & Sons - 2013
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define MAX_LINE		80 /* 80 chars per line, per command */
#define DELIMS                  " \t\r\n"
int main(void)
{
  char args[MAX_LINE/2 + 1];	/* command line (of 80) has max of 40 arguments */
  char* string[MAX_LINE];

  int should_run = 1;
  char *cmd;
  int i, upper;
  while (should_run){   
    printf("osh>");
    fflush(stdout);
    if(!fgets(args,MAX_LINE,stdin)) break;
    cmd = strtok(args,DELIMS);
    int i =0;
    while(cmd != NULL){
      string[i] = cmd;
      printf(" %s\n",string[i]);
      cmd = strtok(NULL,DELIMS);
      i++;
    }
    string[i] = NULL;
    pid_t pid = fork();
    if(pid == 0) {
      execvp(string[0],string);
      printf("Unknown command");
      exit(0);
    } else {

    }

    /**
     * After reading user input, the steps are:
     * (1) fork a child process
     * (2) the child process will invoke execvp()
     * (3) if command included &, parent will invoke wait()
     */
  }
    
  return 0;
}
