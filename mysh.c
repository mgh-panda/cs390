#include <stdio.h>
#include <string.h>

#define MAX_INPUT 50
#define TRUE 1

const char* cmd_echo(const char** arguments);
const char* cmd_prompt_string_one(const char* newPrompt);
const char* cmd_cat(const char* filePath);
int cmd_copy(const char* sourceFile, const char* destinationFile);//Clarification needed
int cmd_remove(const char* targetFile);//clarification
int cmd_make_directory(const char* directoryName);//clarification
int cmd_remove_directory(const char* directoryName);//clarification

int main (int argc, char *argv[])
{
    const char* prompt = "$";
    const char* inputString;
    const char* tempString;
    char delimeters[] = " \t\r\n\v\f";
    const char *arguments[100];
    int argumentCount;

    while(TRUE)
    {
        int argumentCount = 1;
        int argumentIndex = 0;

        printf("%s", prompt);
        fgets(inputString, MAX_INPUT, stdin);
        printf("%s", inputString);
        /*tempString = strtok(inputString, delimeters);
        while (tempString != NULL)
        {
            argumentCount++;
            arguments[argumentIndex] = tempString;
            tempString = strtok(NULL, delimeters);
            argumentIndex++;
        }*/
        /*for (int i = 0; i < argumentCount; i++)
        {
            printf("%s\n", arguments[i]);
        }*/
    }
    return 0;
}

