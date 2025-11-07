#include <stdio.h>
#include <stdlib.h>

// typedef struct no_ NO;
// typedef struct lista_ LISTA;

// struct no_{
//     int valor;
//     NO* prox;
// };

// struct lista_{
//     int tamanho;
//     NO* inicio;
// };

// LISTA* cria_lista(){
//     LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
//     if (lista != NULL){
//         NO* cabeca = (NO*)malloc(sizeof(NO));
//         if (!cabeca){
//             free(lista);
//             return NULL;
//         }



//     }

//     return NULL;
// }


void montaVetor(int v[], int n){
    int valor;
    for (int i = 0; i < n; i++){
        int dia, mes, ano;
        scanf("%d-%d-%d", &dia, &mes, &ano);
        
        valor = 1000000*dia + 10000*mes + ano;
        v[i] = valor;
    }
}

void mostraVetor(int v[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
}

void CountingSort(int v[], int n){
    int* final = (int*)malloc(sizeof(int)*n);
    int max = v[0];

    for (int i = 1; i < n; i++){
        if (v[i] > max) max = v[i];
    }

    int* aux = (int*)calloc(max+1,sizeof(int));

    for (int i = 0; i < n; i++){
        aux[v[i]]++;
    }

    int j = 0;
    for (int i = 0; i < max + 1; i++){
        while (aux[i] != 0){
            final[j] = i;
            j++;
            aux[i]--;
        }
    }

    for (int i = 0; i < n; i++){
        v[i] = final[i];
    }


    free(final);
    free(aux);
}

int buscaBinaria(int v[], int inicio, int fim, int chave){
    if (inicio <= fim){
        int meio = (inicio + fim) / 2;

        if (v[meio] == chave)
            return meio;
        else if (v[meio] > chave)
            return buscaBinaria(v, inicio, meio - 1, chave);
        else
            return buscaBinaria(v, meio + 1, fim, chave);

    } else {
        return -1;
    }
}

int* criaTabelaHash(int v[], int n, int* tamanhoOut){
    int tamanho = n * 3 + 1;
    int* tabela = (int*)calloc(tamanho, sizeof(int)); // pode manter 0 = vazio

    for (int i = 0; i < n; i++){
        int h = v[i] % tamanho;
        if (h < 0) h += tamanho;

        int j = 0;
        int pos = h;

        while (tabela[pos] != 0) {
            j++;
            pos = (h + j*j) % tamanho;
        }

        tabela[pos] = v[i];
    }

    *tamanhoOut = tamanho;
    return tabela;
}

int buscaNaTabela(int* tabela, int tamanho, int chave){
    int h = chave % tamanho;
    if (h < 0) h += tamanho;

    int j = 0;
    int pos = h;

    while (tabela[pos] != 0 && j < tamanho) {
        if (tabela[pos] == chave)
            return pos;
        j++;
        pos = (h + j*j) % tamanho;
    }
    return -1;
}


int buscaSequencial(int v[], int n, int chave){
    int* array = v;
    int* fim = v + n;
    
    while (array < fim){
        if (*array == chave)
            return array - v;
        array++;
    }
    return -1;
}

void buscaComBinaria(int datas[], int buscadas[], int n, int q){
    CountingSort(datas, n);
    
    for (int i = 0; i < q; i++){
        if (buscaBinaria(datas, 0, n-1, buscadas[i]) != -1)
        printf("ENCONTRADA\n");
        else
        printf("NAO_ENCONTRADA\n");
    }
}

void buscaComHashing(int datas[], int buscadas[], int n, int q){
    int tamanho;
    int* tabela = criaTabelaHash(datas, n, &tamanho);

    for (int i = 0; i < q; i++){
        if (buscaNaTabela(tabela, tamanho, buscadas[i]) != -1)
            printf("ENCONTRADA\n");
        else
            printf("NAO_ENCONTRADA\n");
    }

    free(tabela);
}

void buscaComSequencial(int datas[], int buscadas[], int n, int q){
    for (int i = 0; i < q; i++){
        if (buscaSequencial(datas, n, buscadas[i]) != -1)
            printf("ENCONTRADA\n");
        else
            printf("NAO_ENCONTRADA\n");
    }    
}

int main(){

    int n;
    scanf("%d", &n);

    int* datas = (int*)malloc(sizeof(int)*n);
    montaVetor(datas, n);

    int q;
    scanf("%d", &q);

    int* buscadas = (int*)malloc(sizeof(int)*q);
    montaVetor(buscadas, q);

    int alg;
    scanf("%d", &alg);

    switch (alg)
    {
    case 1:
        buscaComBinaria(datas, buscadas, n, q);
        break;
    
    case 2:
        buscaComHashing(datas, buscadas, n, q);
        break;

    case 3:
        buscaComSequencial(datas, buscadas, n, q);
        break;

    default:
        break;
    }

    free(datas);
    free(buscadas);

    return 0;
}