#include <stdio.h>
#include <string.h>

#define MAX_INPUT 50
#define TRUE = 1

const char** process_inputs(const char* inputString);
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
    const char* command;
    char delimeters[] = " \t\r\n\v\f";
    char *tempString;
    char *arguments;
    int argumentCount;

    while(TRUE)
    {
        printf("%s", prompt);
        gets(inputString);
        command = strtok(inputString, delimeters);
        printf("%s", command);
    }
    return 0;
}

