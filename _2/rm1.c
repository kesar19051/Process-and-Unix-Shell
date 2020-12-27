#include<stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	char str[200];
	printf("%s\n", "Do you want to remove the file?");
	fgets(str, 200, stdin);
	int y = strcmp("y", strtok(str, " "));
	if(y==0){
		//printf("%s\n", "will remove");
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
   		return 0;
	}
	else
		return 0;
}


