#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[]) 
{
   int fd, nread;
   char buff;

   fd = open(argv[1], O_RDONLY);
   printf("\n\n%d\n\n", fd);
   
   while (nread = read(fd, &buff, sizeof(buff)) > 0)
   {
      write(1, &buff, nread);
   }
   printf("\n\n%d\n\n", nread);

   close(fd);
   return 0;
}