#include <iostream>
#include<cstdlib>
#include<ctime>
#include <chrono>
using namespace std;

void preencherVetor(int*, int);
void imprimirArray(int*, int, string);
void resolverCasos(int, string);
void mergeSort(int[], int, int);
void mesclar(int*, int, int, int);


int main() {
    srand(time(0));

    resolverCasos(10, "MELHOR CASO");
    
    resolverCasos(1000, "CASO MEDIO");
    
    resolverCasos(10000, "PIOR CASO");

    return 0;
}


// preenche vetor com valores randomicos
void preencherVetor(int* vetor, int tamanho){
  for(int i=0 ; i<tamanho ; i++)
  {
    vetor[i] = rand() % tamanho + 1;
  }
}


void imprimirArray(int* vetor, int tamanho, string tipoCaso){
    cout << tipoCaso << ": ";
    for(int i=0 ; i<tamanho ; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl << endl;
}


// eu pensei numa funcao generica que pode receber qualquer tipo de caso, e voce pode dizer qual eh o caso que esta resolvendo
void resolverCasos(int tamanhoDoCaso, string tipoCaso){
    // aqui eu estou usando ponteiros porque os valores passados para criar o vetor acontecem durante a execução do programa, e por padrao o compilador precisa saber os
    //valores antes de executar o programa. Sendo assim, por convensao, temos que alocar esse vetor dinamicamente, ligado a um ponteiro
    int* vetorCaso = new int[tamanhoDoCaso];

    preencherVetor(vetorCaso, tamanhoDoCaso);

    auto inicio = std::chrono::high_resolution_clock::now();  // Inicia a medição do tempo
    mergeSort(vetorCaso, 0, tamanhoDoCaso-1);
    auto fim = std::chrono::high_resolution_clock::now();  // Finaliza a medição do tempo
    
    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    cout << "Tempo de execucao (" << tipoCaso << "): " << duracao.count() << " ms" << endl;

    imprimirArray(vetorCaso, tamanhoDoCaso, tipoCaso);

    // liberar memoria para nao termos memory leak (vazamento de memoria)
    delete[] vetorCaso;
}


void mergeSort(int vetor[], int inicio, int fim) {

    if (fim > inicio) {
        int meio = inicio + (fim - inicio) / 2;

        // chamada recursiva para a parte esquerda do vetor
        mergeSort(vetor, inicio, meio);

        // chamada recursiva para a parte direita do vetor
        mergeSort(vetor, meio + 1, fim);

        // quando a o mergeSort da esquerda e direita for finalizado, os subarrays serão ordenados aqui, até chegar no vetor colocado no main
        mesclar(vetor, inicio, meio, fim);
    }
}


void mesclar(int* vetor, int inicio, int meio, int fim) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    int* ptrEsquerda = new int[tamanhoEsquerda];
    int* ptrDireita = new int[tamanhoDireita];

    for (int i = 0; i < tamanhoEsquerda; i++)
        ptrEsquerda[i] = vetor[inicio + i];

    for (int j = 0; j < tamanhoDireita; j++)
        ptrDireita[j] = vetor[meio + 1 + j];

    int i = 0; // indice inicial do vetor da esquerda
    int j = 0; // indice inicial do vetor da direita
    int k = inicio; // indice inicial do vetor mesclado

    // ordenando o vetor original
    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (ptrEsquerda[i] <= ptrDireita[j]) {
            vetor[k] = ptrEsquerda[i];
            i++;
        } else {
            vetor[k] = ptrDireita[j];
            j++;
        }
        k++;
    }

    // se depois da ordenacao sobrar algum numero que nao foi adicionado tanto da esquerda quanto da direita, ele vai ser adicionado por aqui
    while (i < tamanhoEsquerda) {
        vetor[k] = ptrEsquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        vetor[k] = ptrDireita[j];
        j++;
        k++;
    }

    delete[] ptrEsquerda;
    delete[] ptrDireita;
}

