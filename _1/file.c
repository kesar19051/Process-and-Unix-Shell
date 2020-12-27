#include <stdio.h>
#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	int id = fork();
	
	if(id<0){
		printf("%s\n", "fork() has failed");
	}
	else if(id==0){
		//child process
		printf("%s\n", "child process");
		FILE *file = fopen("csv.csv", "r");
	char line[500];
	int j = 1;

	while(fgets(line, sizeof(line), file)){
        if(j!=1){
        int i = 1;
        char *token;
            char *studentID;
            char *section;
            int a1;
            int a2;
            int a3;
            int a4;
            token = strtok(line, ",");
            //token = strtok(token, " ");
            //printf("%s\n", token);
            while(token != NULL){
                
                if(i==1)
                    studentID = token;
                if(i==2)
                    section = token;
                if(i==3)
                    a1 = atoi(token);
                if(i==4)
                    a2 = atoi(token);
                if(i==5)
                    a3 = atoi(token);
                if(i==6)
                    a4 = atoi(token);
                //printf("%s ", token);
                token = strtok(NULL, ",");

                
                i++;
                //
            }
            int x = strcmp(section, "B");
            int marks = (a1+a2+a3+a4)/4;
            if(x==0){
            printf("%s ", studentID);
            printf("%s ", section);
            printf("%d ", marks);
            printf("\n");}
            
            
            
            //printf("\n");
    }
    j++;
}
	exit(1);
	}

	else if(id>0){
		//parent process
		int status = 1;
		waitpid(id, &status, 0);
		printf("%s\n", "parent proeccess");
		FILE *file = fopen("csv.csv", "r");
	char line[500];
	int j = 1;

	while(fgets(line, sizeof(line), file)){
        if(j!=1){
        int i = 1;
        char *token;
            char *studentID;
            char *section;
            int a1;
            int a2;
            int a3;
            int a4;
            token = strtok(line, ",");
            //token = strtok(token, " ");
            //printf("%s\n", token);
            while(token != NULL){
                
                if(i==1)
                    studentID = token;
                if(i==2)
                    section = token;
                if(i==3)
                    a1 = atoi(token);
                if(i==4)
                    a2 = atoi(token);
                if(i==5)
                    a3 = atoi(token);
                if(i==6)
                    a4 = atoi(token);
                //printf("%s ", token);
                token = strtok(NULL, ",");

                
                i++;
                //
            }
            int x = strcmp(section, "A");
            int marks = (a1+a2+a3+a4)/4;
            if(x==0){
            printf("%s ", studentID);
            printf("%s ", section);
            printf("%d ", marks);
            printf("\n");}
            
            
            
            //printf("\n");
    }
    j++;
}
	}
	return 0;
}

	