#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define INPUT_FILE "./input/if2"

int main(int argc, char * argv[]) {
    
    if (argc < 2) {
	    printf("Provide a program.\n");
	    exit(1);
    }

    pid_t pid = fork();

    if (pid < 0) {
	    printf("Fork failed!\n");
	    exit(1);
    }

    if (pid == 0) {
	    printf("IN CHILD: pid=%d\n", getpid());

	    int input_fd = open(INPUT_FILE, O_RDONLY);
	    if (input_fd < 0) {
		    printf("Open input failed");
		    exit(1);
	    }


	    int output_fd = open("result", O_WRONLY | O_CREAT | O_TRUNC, 0664);
	    if (output_fd < 0) {
		    printf("Open output failed");
		    exit(1);
	    }

	    dup2(input_fd, STDIN_FILENO);
	    dup2(output_fd, STDOUT_FILENO);

	    close(input_fd);
	    close(output_fd);

	    execvp(argv[1], &argv[1]);

	    printf("exec failed");
	    exit(1);

    }

    else {
	    waitpid(pid, NULL, 0);
	    printf("IN PARENT: successfully waited child (pid=%d)\n", getpid());
    }

    return 0;
}
