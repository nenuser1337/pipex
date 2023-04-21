#include "get_next_line.h"

#define MAX_LINE_LENGTH 1000
void	here_doc(char *argv)
{
	int		file;
	char	*buf;
    int infile;
	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	
	while (1)
	{
		write(1, "heredoc> ", 9);
		buf = get_next_line(0);
		if (!strncmp(argv, buf, strlen(argv) ))
			break ;
		// write(file, buf, strlen(buf));
		// write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	infile = open(".heredoc_tmp", O_RDONLY);
	if (infile < 0)
	{
		unlink(".heredoc_tmp");
		printf("Error heredoc\n");
	}
}

int main(int ac , char **av)
{
    (void)ac;
    here_doc(av[1]);
    return 0;
}

// int main(void) {
//     char *delimiter = "EOF";
//     char *line = NULL;
//     size_t line_size = 0;
//     ssize_t read;
   
//     int pipefd[2];
//     // create a pipe for communication between child and parent processes
//     if (pipe(pipefd) == -1) {
//         perror("pipe");
//         exit(EXIT_FAILURE);
//     }
//     // fork the process to create a child process
//     pid_t pid = fork();
//     if (pid == -1) {
//         perror("fork");
//         exit(EXIT_FAILURE);
//     } else if (pid == 0) {
//         // child process reads from pipe and writes to stdout
//         close(pipefd[1]); // close write end of pipe
//         while ((read = read(pipefd[0], line, &line_size)) != -1) {
//             if (strcmp(line, delimiter) == 0) {
//                 break;
//             }
//             printf("%s", line);
//         }
//         close(pipefd[0]); // close read end of pipe
//         exit(EXIT_SUCCESS);
//     } else {
//         // parent process reads from stdin and writes to pipe
//         close(pipefd[0]); // close read end of pipe
//         while ((read = getline(&line, &line_size, stdin)) != -1) {
//             if (strcmp(line, delimiter) == 0) {
//                 write(pipefd[1], line, strlen(line) + 1);
//                 break;
//             }
//             write(pipefd[1], line, strlen(line) + 1);
//         }
//         close(pipefd[1]); // close write end of pipe
//         wait(NULL); // wait for child process to terminate
//     }
//     free(line);
//     return 0;
// }