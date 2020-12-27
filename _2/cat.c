#include<stdio.h>
#include<unistd.h> /*for STDOUT_FILENO*/
#include<stdlib.h> 
#include<fcntl.h> /*for open*/
 
int main(int argc,char *argv[])
{ 
    int fd, i;
    char ch;
    
    for (i = 1; i < argc; i++) {                    /*iterate the loop for total argument count.*/
        
        fd = open(argv[1],O_RDONLY);            /*open the file in READONLY mode*/
        
        if(fd < 0) { 
            perror("open"); 
            goto OUT; 
        } 
        
        while(read(fd,&ch,1)){  
                  /*Read one byte at a time*/
            if(ch=='\n'){
                write(STDOUT_FILENO, "$", 1);
                write(STDOUT_FILENO, "\n", 1);
            } 
            else{
                write(STDOUT_FILENO,&ch,1); 
            }
            

        }   /*Write the byte on Stdout*/
        
        close(fd);                              /*close the file discriptor*/
    }
 
    return 0;
OUT: 
        return -1;
}