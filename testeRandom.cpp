#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void preencher(int vetor[], int tamanho)
{
    for(int i=0 ; i<tamanho ; i++)
    {
        vetor[i] = rand() % 100 + 1;
    }
}

void imprimirVetor(int vetor[], int tamanho)
{
    for(int i=0 ; i<tamanho ; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));

    int vetor[10];
    int tamanho = sizeof(vetor)/sizeof(int);
    
    preencher(vetor, tamanho);
    imprimirVetor(vetor, tamanho);

    preencher(vetor, tamanho);
    imprimirVetor(vetor, tamanho);

    preencher(vetor, tamanho);
    imprimirVetor(vetor, tamanho);

    preencher(vetor, tamanho);
    imprimirVetor(vetor, tamanho);

    preencher(vetor, tamanho);
    imprimirVetor(vetor, tamanho);
}