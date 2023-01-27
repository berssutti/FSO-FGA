#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int qtdQuadros;
    int qtdPaginas;
    int pgFaults=0;
    int temPagina=1;
    int firstIn=0;
    int aux=0;

    scanf("%d", &qtdQuadros);
    scanf("%d", &qtdPaginas);

    int *quadros = malloc(qtdQuadros*sizeof(int));
    int *paginas = malloc(qtdPaginas*sizeof(int));

    for (int i = 0; i < qtdPaginas; i++) scanf("%d", &paginas[i]);


    for(int i = 0; i < qtdQuadros; i++) {
        quadros[i] = -1;
    }

    for (int i = 0; i < qtdPaginas; i++) {
        temPagina = 1;
        firstIn = aux%qtdQuadros;
        for(int j = 0; j < qtdQuadros; j++) {
            if(quadros[j] == paginas[i]) temPagina = 0;
        }
        if(temPagina==1) {
            quadros[firstIn] = paginas[i];
            pgFaults++;
            aux++;
        }
        // for(int j = 0; j < qtdQuadros; j++) {
        //     printf("%d ", quadros[j]);
        // }
        // printf("\n");
    }


    // for (int i = 0; i < qtdPaginas; i++) {
    //     printf("%d", paginas[i]);
    // }
    // printf("\n");
    printf("%d\n", pgFaults);
    
    return 0;
}