#include <iostream>

// vou usar como exemplo essa lista: {38, 27, 43, 3, 9, 82, 10} como exemplo para poder estudar o que esse programa faz passo a passo

using namespace std;

void mesclar(int vetor[], int inicio, int meio, int fim) {
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    // aqui eu estou criando dois vetores que vao representar a parte esquerda e direita do vetor original
    int esquerda[tamanhoEsquerda];
    int direita[tamanhoDireita];

    for (int i = 0; i < tamanhoEsquerda; i++)
        esquerda[i] = vetor[inicio + i];

    for (int j = 0; j < tamanhoDireita; j++)
        direita[j] = vetor[meio + 1 + j];

    int i = 0; // indice inicial do vetor da esquerda
    int j = 0; // indice inicial do vetor da direita
    int k = inicio; // indice inicial do vetor mesclado

    // ordenando o vetor original
    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    // se depois da ordenacao sobrar algum numero que nao foi adicionado tanto da esquerda quanto da direita, ele vai ser adicionado por aqui
    while (i < tamanhoEsquerda) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < tamanhoDireita) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (fim - inicio > 0) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        mesclar(vetor, inicio, meio, fim);
    }
}

void imprimirArray(int vetor[], int tamanho)
{
    for(int i=0 ; i<tamanho ; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main() {
    int vetor[] = {38, 27, 43, 3, 9, 82, 10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    cout << "Vetor original: ";
    imprimirArray(vetor, tamanho);

    mergeSort(vetor, 0, tamanho - 1);

    cout << "Vetor ordenado: ";
    imprimirArray(vetor,tamanho);

    return 0;
}
