#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
	/* code */
	struct dirent **namelist;
	int n;
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
		while(n--){
			if(n!=1 && n!=0){
				printf("%s ", namelist[n]->d_name);
				free(namelist[n]);
			}
		}
		free(namelist);
	}
	printf("\n");
	exit(EXIT_FAILURE);
	return 0;
}