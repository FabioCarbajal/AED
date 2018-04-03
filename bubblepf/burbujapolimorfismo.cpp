#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
long ini,fin,t;

template <class T>
struct cless
{
	bool cmp(T a, T b)
	{
		return a < b;
	}
};

template <class T>
struct cgreater
{
	bool cmp(T a, T b)
	{
		return a > b;
	}
};

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

template <class T,class Op>
void burbuja(int* arr,int tamano)
{
	Op s;
	for(int i=0;i<tamano;i++)
	{
		for(int o=0;o<tamano-1-i;o++)
		{
			if(s.cmp(*(arr+o),*(arr+o+1)))
			{
				swape(arr+o,arr+o+1);
			}
		}
	}
	imp(arr,tamano);
}

int main()
{
	int *arreglo = NULL;
	int tam=10;
	arreglo=new int[tam];
	delete [] arreglo;
	arreglo=NULL;
	/*
	const int tam=1000000,maxi=100000;
	int arreglo[tam]={};
	srand(time(0));
	for(int j=0;j<tam;j++)
		arreglo[j]=rand()%maxi;
	*/
	ini=clock();
	burbuja<int,cgreater<int>>(arreglo,tam);
	fin=clock();
	double t=(double(fin-ini)/CLOCKS_PER_SEC);
	cout << "Tiempo: " << t << endl;
	return 0;
}
