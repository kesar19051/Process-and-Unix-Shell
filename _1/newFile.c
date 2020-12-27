#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fd;
	fd = open("csv.csv", O_RDONLY, 0);
	//printf("%s\n", "child proecess");
	char ch;
	char line[9917];
	int i =0;

	while(read(fd, &ch,1)==1){
		line[i] = ch;
		i++;
	}
	//printf("%s\n", line);
	char *token;
	char *tokenise;
	char *studentID;
	int a1;
            int a2;
            int a3;
            int a4;
	token = strtok(line, "\n");
	int y = 1;
	while(token!=NULL){
		if(y!=1){
		
		tokenise = strtok(token, ",");
		printf("%s ", tokenise);
		int i =1;
		while(tokenise!=NULL){
			
                if(i==2)
                    printf("%s ", tokenise);
                if(i==3)
                    a1 = atoi(tokenise);
                if(i==4)
                    a2 = atoi(tokenise);
                if(i==5)
                    a3 = atoi(tokenise);
                if(i==6)
                    a4 = atoi(tokenise);
                //printf("%s ", token);
                tokenise = strtok(NULL, ",");

                
                i++;
		}
		int marks = (a1+a2+a3+a4)/4;
		printf("%d\n", marks);
		y++;
		token = strtok(NULL, "\n");
	}
	else{

		
		token = strtok(NULL, "\n");
	}
	}
	close(fd);
}
