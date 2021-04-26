#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main() {
   char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("Current working directory: %s", cwd);
   } else {
       perror("getcwd() error");
       return 1;
   }
   system("pause");
   system("dir ");
   return 0;
}


