#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void preencherVetor(int*, int);
void imprimirArray(int*, int, string);
void resolverCasos(int, string);
void mergeSort(int*, int, int, int*);
void mesclar(int*, int, int, int, int*);

int main() {
    srand(time(0));

    resolverCasos(100, "MELHOR CASO");
    resolverCasos(1000000, "CASO MEDIO");
    resolverCasos(100000000, "PIOR CASO");

    return 0;
}

void preencherVetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % tamanho + 1;
    }
}

void imprimirArray(int* vetor, int tamanho, string tipoCaso) {
    cout << tipoCaso << ": ";
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl << endl;
}

void resolverCasos(int tamanhoDoCaso, string tipoCaso) {
    int* vetorCaso = new int[tamanhoDoCaso];
    int* vetorAuxiliar = new int[tamanhoDoCaso]; // criamos um vetor auxiliar do mesmo tamanho. Ele vai diminuir as consultas na heap, deixando o codigo mais rapido. Aqui, consegui sair de milhoes, para apenas n chamadas de resolucao de problema -> 3

    preencherVetor(vetorCaso, tamanhoDoCaso);

    auto inicio = std::chrono::high_resolution_clock::now();
    mergeSort(vetorCaso, 0, tamanhoDoCaso - 1, vetorAuxiliar);
    auto fim = std::chrono::high_resolution_clock::now();

    auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio);
    cout << "Tempo de execucao (" << tipoCaso << "): " << duracao.count() << " ms" << endl;

    // imprimirArray(vetorCaso, tamanhoDoCaso, tipoCaso);  // ESSE TRECHO DO CODIGO TA COMENTADO SO PARA VISUALIZAR O TEMPO QUE O ALGORITMO LEVOU PARA CONCLUIR O CENARIO

    // liberando memoria
    delete[] vetorCaso;
    delete[] vetorAuxiliar;  
}

// algoritmo Merge Sort Recursivo
void mergeSort(int* vetor, int inicio, int fim, int* vetorAuxiliar) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        // chamadas recursivas para dividir o vetor
        mergeSort(vetor, inicio, meio, vetorAuxiliar);
        mergeSort(vetor, meio + 1, fim, vetorAuxiliar);

        // Chamada da função para mesclar os dois subvetores ordenados
        mesclar(vetor, inicio, meio, fim, vetorAuxiliar);
    }
}

// funçao para mesclar os dois subvetores ordenados
void mesclar(int* vetor, int inicio, int meio, int fim, int* vetorAuxiliar) {
    // copia os elementos do intervalo para o vetor auxiliar
    for (int i = inicio; i <= fim; i++) {
        vetorAuxiliar[i] = vetor[i];
    }

    int i = inicio;     // esse cara aponta para a esquerda do vetor
    int j = meio + 1;   // esse cara aponta para a direita do vetor
    int k = inicio;     // ja esse daqui vai ser responsavel pela navegacao do vetorAuxiliar, para podermos copiar os elementos do vetor[i]

    // comparacao de elementos. tanto a direita como a esquerda vai ser comparada em um mesmo vetor -> vetorAuxiliar e logo em seguida, depositada no proprio vetor[k]
    while (i <= meio && j <= fim) {
        if (vetorAuxiliar[i] <= vetorAuxiliar[j]) {
            vetor[k++] = vetorAuxiliar[i++];
        } else {
            vetor[k++] = vetorAuxiliar[j++];
        }
    }

    // se ainda restarem elementos na parte esquerda, adicionamos ao vetor original
    while (i <= meio) {
        vetor[k++] = vetorAuxiliar[i++];
    }

    // se ainda restarem elementos na parte direita, adicionamos ao vetor original
    while (j <= fim) {
        vetor[k++] = vetorAuxiliar[j++];
    }
}