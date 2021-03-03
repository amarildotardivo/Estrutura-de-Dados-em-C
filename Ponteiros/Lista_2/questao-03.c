#include <stdio.h>
#include <stdlib.h>

int** ordenar(int n, int* vetorInteiro){
    int **w, *aux;

    //Alocando memória para o ponteiro w
    w = (int **) malloc(n * sizeof (int*));

    //Preenchendo o ponteiro w com notação vetor
    for(int i = 0; i < n; i++){
        w[i] = &vetorInteiro[i];
    }

    //Ordenando com bubble sort o ponteiro w
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            
            //verificando a condição olhando para os valores dos endereços que estão em w
            if(*w[j] > *w[j + 1]){
                //Ordenando os endereços do ponteiro w a partir da informação do conteúdo
                aux = w[j];
                w[j] = w[j + 1];
                w[j + 1] = aux;
            }
        }
    }
    
    return w;
}

int main(){
    int n = 4;
    int vetorInteiro[4] = {4, 3, 10, 1};
    int **w;

    //Mostrando os valores do vetor vetorInteiro
    printf("VetorInteiro (valores):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetorInteiro[i]);
    }
    printf("\n\n");

    //Mostrando os endereços do vetor vetorInteiro;
    printf("VetorInteiro (enderecos):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%p ", &vetorInteiro[i]);
    }
    printf("\n\n");

    //Chamando a função ordenar e atribuindo o retorno ao ponteiro
    w = ordenar(n, &vetorInteiro);

    //Mostrando os valores que os endereços que estão dentro do ponteiro W apontam
    printf("Ponteiro W (valores):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *w[i]);
    }
    printf("\n\n");

    //Mostrando os endereços que existem dentro de W
    printf("Ponteiro W (enderecos):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%p ", w[i]);
    }
    printf("\n\n");

    //Mostrando os valores do vetor vetorInteiro depois da ordenação do ponteiro w
    printf("VetorInteiro (valores):\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetorInteiro[i]);
    }
    printf("\n\n");

    free(w);

    return 0;
    
}