#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <limits.h>
#include<fcntl.h>

int main()
{
	/* code */
	FILE *fptr = fopen("/home/kesar/Desktop/Assignment1/_2/historyFile.txt", "a+");

	
	while(1){

	char str[200];
	int n = 200;
	char *ptr;
	
	printf("%s\n", "Enter the command");
	//scanf("%s", str);
	fgets(str, 200, stdin);
	ptr = str;

	fprintf(fptr, "%s\n", ptr);

	int cd = strcmp("cd", strtok(str, " "));
	int echo = strcmp("echo", strtok(str, " "));
	int history = strcmp("history", strtok(str, " "));
	int pwd = strcmp("pwd", strtok(str, " "));
	int exit = strcmp("exit", strtok(str, " "));
	int ls = strcmp("ls", strtok(str, " "));
	int cat = strcmp("cat", strtok(str, " "));
	int date = strcmp("date", strtok(str, " "));
	int rm = strcmp("rm", strtok(str, " "));
	int mkdir = strcmp("mkdir", strtok(str, " "));
	//printf("%d\n", '"');

	if(history==0){
		//char str1[200];
		if(str[9]=='c'){
			fopen("/home/kesar/Desktop/Assignment1/_2/historyFile.txt", "w");
		}
		fclose(fptr);
		int fd;
		char ch;
		fd = open("/home/kesar/Desktop/Assignment1/_2/historyFile.txt",O_RDONLY);
		while(read(fd,&ch,1)){
			write(STDOUT_FILENO,&ch,1);
		}
		close(fd);
		fptr = fopen("/home/kesar/Desktop/Assignment1/_2/historyFile.txt", "a+");
	}


	if(exit==0){
		if(str[5]=='-'){
			int fd;
			char ch;
			fd = open("exitFile.txt", O_RDONLY);
			while(read(fd,&ch,1)){
				write(STDOUT_FILENO,&ch,1);
			}
			close(fd);
		}
		else{
			break;
			fclose(fptr);
			return 0;
		} 
		
	}

	if(cd==0){
		char option[197];
		char *ptr;
		for(int i = 0; i<197; i++){
			option[i] = str[3+i];
		}
		ptr = strtok(option, " ");
		printf("%s\n", ptr);
		if(chdir(ptr)!=0){
			printf("done\n");
			//chdir(ptr);
		}
	}

	if(echo==0){
		char option[195];
		char *ptr;
		char toPrint[190];
		for(int i = 0; i<195; i++){
			option[i] = str[5+i];
		}
		ptr = strtok(option, " ");
		//printf("%s\n", ptr);
		int length = strlen(ptr);
		if(length==2){
			if(ptr[1]=='E'){
				for(int i = 0; i<190; i++){
					if(option[4+i]==34)
						i++;
					toPrint[i] = option[4+i];
				}
				printf("%s\n", toPrint);
			}
			else{
				for(int i = 0; i<190; i++){
					if(option[4+i]==34)
						i++;
					toPrint[i] = option[4+i];
				}
				printf("%s", toPrint);
			}
		}
		else{
			printf("%s\n", ptr);
		}
	}

	if(pwd==0){
		//printf("%s\n", "pwd called");
		int fd;
		char ch;
		if(str[4]=='-'){
			fd = open("pwdFile.txt", O_RDONLY);
			while(read(fd,&ch,1)){
				write(STDOUT_FILENO,&ch,1);
			}
		close(fd);
		}
		
		else{
		char cwd[1024];
		chdir("/path/to/change/directory/to");
		getcwd(cwd, sizeof(cwd));
		printf("Current working dir: %s\n", cwd);}
	}

	if(ls==0){
		pid_t pid;

		pid = fork();
		if(pid<0){
			fprintf(stderr, "Fork failed");
		}
		else if(pid==0){
			printf("%s\n", "entered child");
			if(str[4]=='r'){
				char *args[] = {"./ls", NULL};
				execv(args[0], args);
			}
			else{
				char *args[] = {"./ls1", NULL};
				execv(args[0], args);
			}
		}
		else{
			wait(NULL);
		}
	}

	if(cat==0){
		pid_t pid;

		char filename[200];
		printf("%s\n", "Enter the filename");
		fgets(filename, 200, stdin);
		char *token;
		token = strtok(filename, " ");
		printf("%s\n", token);
		pid = fork();
		if(pid<0){
			fprintf(stderr, "Fork failed\n");
		}
		else if(pid==0){
			printf("%s\n", "entered child");
			if(str[5]=='E'){
				char *args[] = {"./cat", token, NULL};
				execv("./cat", args);
			}
			else{
				char *args[] = {"./cat1", token, NULL};
				execv("./cat1", args);
			}
		}
		else{
			wait(NULL);
		}
	}

	if(date==0){
		pid_t pid;
		pid = fork();

		if(pid<0){
			fprintf(stderr, "%s\n", "Fork failed");
		}
		else if(pid==0){
			if(str[6]=='u'){
				char *args[] = {"./date", NULL};
				execv("./date", args);
			}
			if(str[8]=='-'){
				char *args[] = {"./date1", NULL};
				execv("./date1", args);
			}
		}
		else{
			wait(NULL);
		}
	}

	if(rm==0){
		pid_t pid;
		
		char filename[200];
		printf("%s\n", "Enter the filename");
		fgets(filename, 200, stdin);
		char *token;
		token = strtok(filename, " ");

		pid = fork();

		if(pid<0){
			fprintf(stderr, "%s\n", "Fork failed");
		}

		else if(pid==0){
			if(str[4]=='f'){
				char *args[] = {"./rm", token, NULL};
				execv("./rm", args);
			}
			else{
				char *args[] = {"./rm1", token, NULL};
				execv("./rm1", args);
			}
		}

		else{
			wait(NULL);
		}

	}

	if(mkdir==0){
		pid_t pid;

		char filename[200];
		printf("%s\n", "Enter the filename");
		fgets(filename, 200, stdin);
		char *token;
		token = strtok(filename, " ");
		pid = fork();

		if(pid<0){
			fprintf(stderr, "%s\n", "Fork failed");
		}

		else if(pid==0){

			if(str[7]=='v'){
				char *args[] = {"./mkdir", token, NULL};
				execv("./mkdir", args);
			}
			else{
				char *args[] = {"./mkdir1", token, NULL};
				execv("./mkdir1", args);
			}
		}
		else{
			wait(NULL);
		}
	}


	}
}
