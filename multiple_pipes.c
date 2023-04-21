


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void loop_pipe(char ***cmd) 
{
  int p[2];
  pid_t pid;
  int fd_in = 0;

  while (*cmd != NULL)
    {
      pipe(p);
      if ((pid = fork()) == -1)
        {
          exit(EXIT_FAILURE);
        }
      else if (pid == 0)
        {
          dup2(fd_in, 0); //change the input according to the old one 
          if (*(cmd + 1) != NULL)
            dup2(p[1], 1);
          close(p[0]);
          execve((*cmd)[0], *cmd, NULL);
          exit(EXIT_FAILURE);
        }
      else
        {
          wait(NULL);
          close(p[1]);
          fd_in = p[0]; //save the input for the next command
          cmd++;
        }
    }
      if (fd_in > 0) close(fd_in); // Close the last input file descriptor

}


int main()
{
     char *ls[] = {"/bin/ls", "-al", NULL};
	char *rev[] = {"/usr/bin/rev", NULL};
	char *nl[] = {"/usr/bin/nl", NULL};
	char *cat[] = {"/bin/cat", "-e", NULL};
    char *wc[] = {"/usr/bin/wc","-l", NULL};
    char **cmd[] = {ls, rev, nl, cat, wc,  NULL};

loop_pipe(cmd);
return 0;
}

