#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define PROMPT "$ "

int main(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t characters;
    char *args[1024];
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

            // Parse command and arguments
            char *token = strtok(line, " ");
            int i = 0;
            while (token != NULL)
            {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL;

            // Check for built-in commands
            if (strcmp(args[0], "exit") == 0)
            {
                break;
            }
            else if (strcmp(args[0], "env") == 0)
            {
                char **env = __environ;
                while (*env != NULL)
                {
                    printf("%s\n", *env);
                    env++;
                }
            }
            else
            {
                // Execute command
                if (access(args[0], X_OK) == 0)
                {
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
                else
                {
                    fprintf(stderr, "%s: command not found\n", args[0]);
                }
            }
        }
    }
    free(line);
    return EXIT_SUCCESS;
}
