#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define INPUT_FILE "./input/if1"

int main(int argc, char * argv[]) {
    
    if (argc < 2) {
	    printf("Provide a program.\n");
	    exit(1);
    }

    if (pid < 0) {
	    printf("Fork failed!\n");
    }

    if (pid == 0) {
	    printf("IN CHILD: pid=%d\n", getpid());

    }

    else {
	    waitpid(pid, NULL, 0);
	    printf("IN PARENT: successfully waited child (pid=%d)\n", getpid());
    }

    return 0;
}
