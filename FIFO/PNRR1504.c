#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 16
int main(int argc, char* argv[])
{
    FILE*fr, *fw;
    char buffer[DIM];
    int n;
    fr= fopen(argv[1],"r");
    fw= fopen(argv[1],"w");
    while(n=fread(buffer, 1, DIM, fr)>0)
    {
        fwrite(buffer,1,n,fw);
    }
    fclose(fr);
    fclose(fw);
    return 0;
}