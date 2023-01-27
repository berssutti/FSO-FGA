#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    void *handle;

    int (*imprime) (void);
    int (*calcula) (int a,int b);
    int (*trigo) (double c, double *d);

    int valImprime;
    int valCalcula;
    int valTrigo;

    int valor1 = atoi(argv[2]);
    int valor2 = atoi(argv[3]);
    double valorC = atof(argv[4]);


    handle = dlopen(argv[1], RTLD_NOW);
    if(!handle) {
        printf("nao disponivel");
        return 0;
    }

    imprime = dlsym(handle, "imprime");
    calcula = dlsym(handle, "calcula");
    trigo = dlsym(handle, "trigo");

    if (!imprime) {
        printf("nao implementado\n");
    } else {
        valImprime = imprime();
        printf("%d\n", valImprime);
    }
    if (!calcula) {
        printf("nao implementado\n");
    } else {
        valCalcula = calcula(valor1, valor2);
        printf("%d\n", valCalcula);
    }

    if (!trigo) {
        printf("nao implementado\n");
    } else {
        valTrigo = trigo(valorC, &valorC);
        printf("%d\n", valTrigo);
    }
    
    dlclose(handle);
    return 0;
}
