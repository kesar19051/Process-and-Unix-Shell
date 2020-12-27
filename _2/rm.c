#include<stdio.h>

void main(int argc, char* argv[]){

int status;
status=remove(argv[1]);
if(status==0)
  {
    printf("File removed\n");
  }
else
   {
    printf("File is not removed\n");
   }
}