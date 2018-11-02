#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
   //basic functions for working with files
   FILE *my_stream; // this here creates a pointer that will point to a stream
   int close_error;
   int bytes_read;
   size_t nbytes = 10;
   int i = 10;
   char * my_string;
   my_stream = fopen("text.txt", "w");
   if(!my_stream)
      printf("unable to open file\n");
   else
      printf("file opened\n");

   fwrite(&i, sizeof(int), 1, my_stream);
   
   close_error = fclose(my_stream);
   if(!close_error)
      printf("file closed successfully\n");
   else
      printf("unable to close file\n");

   puts("enter a line");
   my_string = (char *) malloc (nbytes+1);
   bytes_read = getline(&my_string,&nbytes, stdin);
   if (bytes_read == -1)
   {
      puts ("ERROR!");
   }
   else
   {
      puts ("You typed:");
      puts(my_string);
   }
   return 0;
   
}
