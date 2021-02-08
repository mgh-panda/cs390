#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int printStrings(const char* args[]);

int main( )
{
    int index = 0;
    const char* stringArray[100];

    char *path = getenv("PATH");
    char *token = strtok(path, ":");
    
    while(token != NULL)
    {
        stringArray[index] = token;
        token = strtok(NULL, ":");
        index++;
    }
    stringArray[index] = '0';

    printStrings(stringArray);

    return 0;
}

int printStrings(const char* args[])
{
    int index = 0;

    while(args[index] != '0')
    {
        printf("%s\n", args[index]);
        index++;
    }
    
    return 0;
}
