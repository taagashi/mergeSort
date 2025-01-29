#include<iostream>
using namespace std;

void funcRecursivo(int num)
{
    cout << num << endl;
    funcRecursivo(num-1);
}

int main()
{
    int* ptr = new int[100];

    for(int i=0 ; i<100 ; i++)
    {
        cout << ptr[i] << " "; 
    }
    cout << endl;


    ptr = new int[20];

    delete[] ptr;
}