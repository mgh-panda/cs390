#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_INPUT 128
#define TRUE 1
#define FALSE 0

int run_external_program(const char *arguments[], const char *paths[]);
int check_file_access(char *path);

int main (int argc, char *argv[])
{
    const char* prompt = "$";
    const char* environmentPaths[100];
    char inputString[MAX_INPUT];
    char delimeters[] = " \t\r\n\v\f";
    char *arguments[10];
    int index = 0;

    char *path = getenv("PATH");
    char *token = strtok(path, ":");
    
    while(token != NULL)
    {
        environmentPaths[index] = token;
        token = strtok(NULL, ":");
        index++;
    }

    while(TRUE)
    {
        char *tempString;
        int argumentCount = 0;
        int argumentIndex = 0;

        printf("%s", prompt);

        //Get input string from keyboard
        fgets(inputString, MAX_INPUT, stdin);

        //Tokenize input string, store in arguments array
        tempString = strtok(inputString, delimeters);
        while (tempString != NULL)
        {
            argumentCount++;
            arguments[argumentIndex] = tempString;
            tempString = strtok(NULL, delimeters);
            argumentIndex++;
        }

        //Test, discard when finished
        for (int i = 0; i < argumentCount; i++)
        {
            printf("%s\n", arguments[i]);
        }
        if (run_external_program(arguments, environmentPaths) != TRUE)
        {
            //ERROR
            printf("%s\n", "Program not found...\n");
        }
    }
    return 0;
}

int run_external_program(const char *args[], const char *paths[])
{
    int index = 0;
    char currentDirectory[256];
    char *path;

    printf("%s\n", "Run external program");
    //If filepath given
    if (access(args[0], R_OK || X_OK) == 1)
    {
        //EXECUTE
        //RETURN TRUE
        printf("%s\n", "Checking filepath");
    }
    else
    {
        printf("%s\n", "Filepath not given");
        getcwd(currentDirectory, sizeof(currentDirectory));

        paths[index] = NULL;

        while(paths[index] != NULL)
        {
            printf("%s\n", "Searching environment paths");
            strcpy(path, paths[index]);
            strcat(path, "/");   
            strcat(path, args[0]);
            strcat(path,".out");
            if (access(path, R_OK | X_OK))
            {
                //fork?
                execv(path, args);
                return TRUE;
            }
        }
        return FALSE;
    }
}