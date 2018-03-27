#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


bool less_(int a,int b){return a < b;}

bool greater_(int a, int b){return a > b;}

void swape(int* p1,int* p2)
{
    int aux=*(p1);
    *(p1)=*(p2);
    *(p2)=aux;
}

void imp(int* i,int tam)
{
   for(int o=0;o<tam;o++)
        cout<<*(i+o)<<" ";
}

void burbuja(int* arr,int tamano, bool (*p)(int,int))
{
    for(int i=0;i<tamano;i++)
        {
            for(int o=0;o<tamano-1-i;o++)
            {
                if(greater_(*(arr+o),*(arr+o+1)))
                {
                    swape(arr+o,arr+o+1);
                }
            }
        }
    imp(arr,tamano);
}

int main()
{
    const int tam=10000,maxi=20;
    int arreglo[tam]={};
    srand(time(0));
    for(int j=0;j<tam;j++)
        arreglo[j]=rand()%maxi;
    burbuja(arreglo,tam,greater_);
    return 0;
}
