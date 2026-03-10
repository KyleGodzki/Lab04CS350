#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {

   pid_t pid = fork();
   if (pid < 0) {
	   printf("Fork failed!");
           exit(1);
   }

   if (pid == 0) {
	   printf("IN CHILD: pid=%d\n", getpid());
	   execlp("ls", "ls", "-l", "-a", NULL);

	   printf("Exec failed");
	   exit(1);
   }

   else {
	   waitpid(pid, NULL, 0);
	   printf("IN PARENT: successfully waited child (pid=%d)\n", getpid());
   }

   return 0;
}
