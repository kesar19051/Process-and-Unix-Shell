#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *hFile = fopen("hello.txt", "w");

    char str[6] = "Kesar";
    int n = 6;

    fwrite(str, 1, sizeof(str), hFile);
    fwrite(&n, 1, sizeof(n), hFile);

    fclose(hFile);

    return 0;
}
