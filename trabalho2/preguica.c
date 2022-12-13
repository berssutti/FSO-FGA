#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int cont = 0;

void alrm_handler(int signum) {
    cont++;
    if(cont==3){
        printf("Os incomodados que se mudem, tchau\n");
        exit(0);
    }
    else
        printf("Ai que sono, quero dormir mais um pouco\n");
    alarm(2);
}

void r1_handler(int signum) {
    printf("SIGUSR1 eh para aproveitar mais um pouco\n");
}

int main() {
    signal(SIGUSR1, r1_handler);
    signal(SIGALRM, alrm_handler);

    // alarm(2);
  
    for(int i=1;;i++){
        // if(i%4==0)
        //     raise(SIGUSR1);
        
        pause();  
    }
    return 0;
}