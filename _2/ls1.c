#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
	/* code */
	struct dirent **namelist;
	int n;
	int i = 0;
	if(argc<1){
		exit(EXIT_FAILURE);
	}
	else if(argc==1){
		n = scandir(".", &namelist, NULL, alphasort);
	}
	else{
		n = scandir(argv[1], &namelist, NULL, alphasort);
	}
	if(n<0){
		perror("scandir");
		exit(EXIT_FAILURE);
	}
	else{
		while(i<n){
			if(i!=1 && i!=0){
				printf("%s\n", namelist[i]->d_name);
				free(namelist[i]);
			}
			i++;
		}
		free(namelist);
	}
	exit(EXIT_FAILURE);
	return 0;
}