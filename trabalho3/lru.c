#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int qtdQuadros;
    int qtdPaginas;
    int pgFaults=0;
    int temPagina=1;
    int leastUsed=0;
    int maior=0;
    int posicao=0;

    scanf("%d", &qtdQuadros);
    scanf("%d", &qtdPaginas);

    int *quadros = malloc(qtdQuadros*sizeof(int));
    int *paginas = malloc(qtdPaginas*sizeof(int));
    int *distancia = malloc(qtdPaginas*sizeof(int));;

    for (int i = 0; i < qtdPaginas; i++) scanf("%d", &paginas[i]);


    for(int i = 0; i < qtdQuadros; i++) {
        quadros[i] = -1;
    }

    for(int i = 0; i < qtdQuadros; i++) {
        distancia[i] = -1;
    }

    for (int i = 0; i < qtdPaginas; i++) {
        temPagina = 1;
        
        for(int j = 0; j < qtdQuadros; j++) {
            if(quadros[j] == paginas[i]){
                temPagina = 0;
                distancia[j] = 0;
            }
            else distancia[j]++; 
        }

        maior = distancia[0];
        posicao = 0;
        if(i<qtdQuadros) {
            leastUsed = i%qtdQuadros;
        }
        else {
            for(int j=0; j<qtdQuadros;j++) {
                if(distancia[j]>maior) {
                    maior=distancia[j];
                    posicao = j;
                }
            }
            leastUsed = posicao;
        }

        
        if(temPagina==1) {
            quadros[leastUsed] = paginas[i];
            pgFaults++;
            distancia[leastUsed] = 0;
        }

        // for(int j = 0; j < qtdQuadros; j++) {
        //     printf("%d ", quadros[j]);
        // }
        // printf("      %d %d   \n",paginas[i],leastUsed);
        // for(int j=0;j<qtdQuadros;j++) printf("%d", distancia[j]);
        // printf("\n");
    }

    printf("%d\n", pgFaults);
    
    return 0;
}