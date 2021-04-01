#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 128
#define TRUE 1
#define FALSE 0

int check_file_access(const char *filePath);
const char *[] get_environment_paths();

int main (int argc, char *argv[])
{
    const char* prompt = "$";
    char inputString[MAX_INPUT];
    const char* tempString;
    char delimeters[] = " \t\r\n\v\f";
    const char *arguments[100];
    int argumentCount;
    int fileAccess;

    while(TRUE)
    {
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

        //If program name entered
        if(arguments[0] == "myls" || arguments[0] == "myls.c")
        {
            char *programName = "myls.c";
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
            //check all paths including current directory for myls
            if (execute_from_environment(environmentPaths, arguments) != TRUE)
            {
                //error
            }
        }
        else
        {
            //check given path for myls.c
            if (fileAccess)
            execv(arguments[0], arguments);
        }
    }
    return 0;
}
int execute_from_environment(const char *paths[], const char *args[])
{
    int accessCheck = FALSE;
    char *path;

    //If filepath given
    if (access(args[0], R_OK | X_OK)
    {

    }
    //Search for program
    else
    {
        while(paths[index] != NULL && accessCheck != TRUE)
        {
            strcpy(path, paths[index]);
            strcat(path, "/");   
            strcat(path, args[0]);
            strcat(path,".out");
            if (access(path, R_OK | X_OK)
            {
                accessCheck = TRUE;
                //fork?
                execv(path, args);
                return TRUE;
            }
        }
    }

}

/*
#include <unistd.h>
int result;
const char *filename = "/tmp/myfile";
result = access (filename, F_OK); // F_OK tests existence also (R_OK,W_OK,X_OK).
                                  //            for readable, writeable, executable
if ( result == 0 )
{
   printf("%s exists!!\n",filename);
}
else
{
   printf("ERROR: %s doesn't exist!\n",filename);
}
*/