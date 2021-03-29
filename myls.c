#include <stdio.h>
#include <dirent.h>


int main (int argc, char *argv[])
{
    DIR *directoryPointer;
    struct dirent *directoryEntry;

    if (argc == 1)
    {
        //you don't have an argument, so you opendir(".")
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
        //you've got either a "-a" or a directory.
        if (argv[1] == "-a") //then directory is implied to be "."
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
        else //argv[1] is the directory.
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

