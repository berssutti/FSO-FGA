#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int tamanho;
    int *v;
} vetor;

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void *ordena_vetor(void *args) {
    vetor *parametros_reais = args;
    qsort(parametros_reais->v,parametros_reais->tamanho, sizeof(int), cmpfunc);
}

int main(){
    int i;
    int tamanho;
    scanf("%d", &tamanho);

    vetor parametros1; 
    parametros1.v = malloc(sizeof(int)*tamanho);
    for(i = 0; i < tamanho; i++) 
        scanf("%d", &parametros1.v[i]);
    parametros1.tamanho = tamanho;
    
    vetor parametros2;
    parametros2.v = malloc(sizeof(int)*tamanho);
    for(i = 0; i < tamanho; i++) 
        scanf("%d", &parametros2.v[i]);
    parametros2.tamanho = tamanho;

    pthread_t thread1_id,thread2_id;

    pthread_create(&thread1_id, NULL, ordena_vetor, &parametros1);
    pthread_create(&thread2_id, NULL, ordena_vetor, &parametros2);

    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);

    int teste = 0;
    for(i = 0; i<tamanho; i++) {
        if(parametros1.v[i] != parametros2.v[i])
            teste = 1;
    }

    if(teste == 0)
        printf("Mesmos elementos\n");
    else   
        printf("Diferentes\n");

    exit(0);
}