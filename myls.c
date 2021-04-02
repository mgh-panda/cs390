#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    DIR *directoryPointer;
    struct dirent *directoryEntry;

    if (argc == 1)
    {
	printf("%s\n", "Opening current directory");
	directoryPointer = opendir(".");
        if (directoryPointer == NULL)
        {
            printf("No directory access.");
        }
//	printf("%s\n", "Preparing to read directory");
        else
        {
		while ((directoryEntry = readdir(directoryPointer)) != NULL)
		{
			if (directoryEntry->d_name[0] != '.')
			{
				printf("%s\n", directoryEntry->d_name);
			}
		}
        }
    }
    else if (argc == 2)
    {
        if (argv[1] == "-a")
        {

            directoryPointer = opendir(".");
	    if (directoryPointer == NULL)
            {
                printf("No directory access.");
            }
            else
	    {
	    	while ((directoryEntry = readdir(directoryPointer)) != NULL)
            	{
                	printf("%s\n", directoryEntry->d_name);
		}
            }
        }
        else
        {
            directoryPointer = opendir(argv[1]);
            if (directoryPointer == NULL)
	    {
                printf("No directory access.");
            }
            else
	    {
		 while (directoryEntry = readdir(directoryPointer) != NULL)
           	 {
               		 if (directoryEntry->d_name[0] != ".")
                	 {
                   		 printf("%s\n", directoryEntry->d_name);
               		 }
		 }
            }
        }
    }
    else if (argc == 3)
    {
        if (argv[1] != "-a")
        {
            printf("Invalid option.");
        }
        else
	{
		directoryPointer = opendir(argv[2]);
		if (directoryPointer == NULL)
		{
			printf("No directory access.");
		}
        
       		 else
		 { 
			 while (directoryEntry = readdir(directoryPointer) != NULL)
			 {
				 printf("%s\n", directoryEntry->d_name);
			 }
       
            	}
        }
    }
    else
    {
        //Display usage guidance
        printf("Usage: $ myls [-a] <dir name>\n");
    }
   closedir(directoryPointer); 
    exit(1);
}

