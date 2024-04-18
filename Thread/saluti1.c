#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

//thread POSIX, è uno standard
void* stampaSaluti(void* par)
{
    printf("%s\n",(char*)par);//sposto il printf dal main alla funzione
    return (void*)0;
}
int main(int argc, char* argv[])
{
    pthread_t threadGiorno, threadSera, threadNotte;
    char* msg1= "buongiorno";
    char* msg2= "buonasera";
    char* msg3= "buonanotte";
    printf("ciao\n");
    pthread_create(&threadGiorno,NULL,&stampaSaluti,msg1);
    pthread_create(&threadSera,NULL,&stampaSaluti,msg2);
    pthread_create(&threadNotte,NULL,&stampaSaluti,msg3);
    pthread_join(threadGiorno,NULL);
    pthread_join(threadSera,NULL);
    pthread_join(threadNotte,NULL);

    return 0;
}