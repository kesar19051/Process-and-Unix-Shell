
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
void main(int argc, char *argv[]) 
{ 
    int check; 
    char* dirname = argv[1]; 
  
    check = mkdir(dirname, 0777); 
  
    // check if directory is created or not 
    if (!check) {
        printf("mkdir Directory created with mode 0777"); 
        printf(" '");
        printf("%s'\n", dirname);
    }

    else { 
        printf("Unable to create directory\n"); 
    } 
} 