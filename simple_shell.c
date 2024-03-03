#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define PROMPT "#cisfun$ "

int main(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t characters;
    char *args[] = {NULL};
    int status;

    while (1)
    {
        printf(PROMPT);
        characters = getline(&line, &bufsize, stdin);
        if (characters == EOF)
        {
            printf("\n");
            break;
        }
        if (characters > 1) // If not just newline
        {
            line[strcspn(line, "\n")] = '\0'; // Remove newline
            // Parse and execute command
            if (fork() == 0)
            {
                execve(args[0], args, NULL);
                perror("Error");
                exit(EXIT_FAILURE);
            }
            else
            {
                wait(&status);
            }
        }
    }
    free(line);
    return EXIT_SUCCESS;
}
