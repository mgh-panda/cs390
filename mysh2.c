#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 128
#define TRUE 1
#define FALSE 0

int run_external_program(char *arguments[]);
int check_file_access(char *path);

int main (int argc, char *argv[])
{
    const char* prompt = "$";
    char inputString[MAX_INPUT];
    char delimeters[] = " \t\r\n\v\f";
    char *arguments[100];

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
        if (run_external_program(arguments) != TRUE)
        {
            //ERROR
            printf("%s\n", "Program not found...\n");
        }
    }
    return 0;
}

int run_external_program(char *args[])
{
    //If filepath given
    if (access(args[0], R_OK | X_OK)
    {
        //EXECUTE
        //RETURN TRUE
    }
    else
    {
        int index = 0;
        const char* environmentPaths[100];
        char *path = getenv("PATH");
        char *token = strtok(path, ":");
        while(token != NULL)
        {
            environmentPaths[index] = token;
            token = strtok(NULL, ":");
            index++;
        }

        environmentPaths[index] = NULL;

        while(paths[index] != NULL)
        {
            strcpy(path, paths[index]);
            strcat(path, "/");   
            strcat(path, args[0]);
            strcat(path,".out");
            if (access(path, R_OK | X_OK)
            {
                //fork?
                execv(path, args);
                return TRUE;
            }
        }
        return FALSE;
    }
}