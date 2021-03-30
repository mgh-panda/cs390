#include <stdio.h>
#include <dirent.h>


int main (int argc, char *argv[])
{
    DIR *directoryPointer;
    struct dirent *directoryEntry;

    if (argc == 1)
    {
        if ((directoryPointer = opendir(".") == NULL)
        {
            printf("No directory access.");
        }
        else while (dirent = readdir(directoryPointer) != NULL)
        {
            if (dirent.d_name[0] != ".")
            {
                printf("%s\n", dirent.d_name);
            }
        }
    }
    else if (argc == 2)
    {
        if (argv[1] == "-a")
        {
            if ((directoryPointer = opendir(".") == NULL)
            {
                printf("No directory access.");
            }
            else while (dirent = readdir(directoryPointer) != NULL)
            {
                printf("%s\n", dirent.d_name);
            }
        }
        else
        {
            if ((directoryPointer = opendir(argv[1])) == NULL)
            {
                printf("No directory access.");
            }
            else while (dirent = readdir(directoryPointer) != NULL)
            {
                if (dirent.d_name[0] != ".")
                {
                    printf("%s\n", dirent.d_name);
                }
            }
        }
    }
    else if (argc == 3)
    {
        if (argv[1] != "-a")
        {
            printf("Invalid option.")
        }
        else if ((directoryPointer = opendir(argv[2])) == NULL)
        {
            printf("No directory access.");
        }
        else while (dirent = readdir(directoryPointer) != NULL)
        {
            printf("%s\n", dirent.d_name);
        }
    }
    else
    {
        //Display usage guidance
        printf("Usage: $ myls [-a] <dir name>\n");
    }
    
    exit(1);
}

