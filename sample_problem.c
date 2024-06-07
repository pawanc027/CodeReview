/* This program's generates random numbers and write them out to a file
   Then get the md5sum of the file.
*/

#include "/usr/include/stdio.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void get_random_number(void *random){

    int r = rand();
    random = r;

}

char *getStringFromInt(long i)
{

        char str[8];
        sprintf(str, "%-d", i);
        return str;
}

void write_string_to_file(char *random_number)
{

        int fd = open("output.txt", O_WRONLY | O_APPEND, 0777);
        write(fd, random_number, strlen(random_number));
        return;

}

void printRandomNumber(char *file)
{

        char *command = malloc(32);
        sprintf(command, "md5sum %s", file);
        system(command);
        free(command);

}


int main(int argc, char** argv)
{

        printf("About to generate ");
        printf(argv[1]);
        printf(" random numbers...\n");

        printf("Press 'y' to continue..  ");
        char answer[2];
        gets(answer);
        printf("answer: %s %p\n", answer, answer);

        if(answer[0] == "y"){
                printf("You answered %s, aborting\n",answer);
                return 0;
        }


        short count = atoi(argv[1]);

        while(--count){

                int *a = malloc(4);
                get_random_number(a);

                char *str = getStringFromInt(a);
                write_string_to_file(str);
                printRandomNumber("output.txt");


        }

        return 0;

}
